#include <string>  // for char_traits, operator+, string, basic_string, to_string
#include <memory>  // for allocator, __shared_ptr_access
#include <future>
#include <functional>

#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/component/event.hpp"           // for Event
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"  // for Ref
#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"  // for ftxui

#include <nlohmann/json.hpp>

#include "./search.h"
#include "./directories.h"
#include "./aiwatcher.h"

using namespace ftxui;
using json = nlohmann::json;

int main(int argc, char *argv[]) {

    json j = R"({"compact": true, "value": 50})"_json;
    int value;
    try{
        value = j["value"];
    } catch (json::exception& e){
        std::cout << e.what() << '\n';
    }

    auto screen = ScreenInteractive::Fullscreen();

    // The tree of components. This defines how to navigate using the keyboard.
    auto button_option = ButtonOption();
    button_option.border = false;

    Search  search = Search();
    Directories directories = Directories(&search);

    aiWatcher("/tmp/ai", [&](const std::string &path) {
        search.list_obj.list.push_back(path);
    });

    /*
    aiWatcher("/tmp/ai", [&](const std::string &path) {
        QDirIterator it(path.c_str(), QStringList() << "*.*", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            auto file = it.next();
            // do something with the file
            search.list_obj.list.push_back(path);
        }
    });
    */


    int tab_index = 0;
            std::vector<std::string> tab_entries = { "Pesquisar", "Diretorios"};

    auto tab_selection = Toggle(&tab_entries, &tab_index);
    auto tab_content = Container::Tab(
                {
                    search.render,
                    directories.render,
                },
                &tab_index);

    auto navbar_con = Container::Vertical({
                                              tab_selection,
                                              tab_content,
                                          });

    auto navbar = Renderer(navbar_con, [&] {
        return vbox({
                        tab_selection->Render(),
                        tab_content->Render() | flex,
                    }) | border;
    });


    // Botão fechar
    auto button_quit = Button("Sair",screen.ExitLoopClosure(),&button_option);
    // HEADER
    auto main_header_con = Container::Vertical({button_quit});

    auto main_header = Renderer(main_header_con, [&] {
        return hbox({
                        button_quit->Render() | align_right,
                        text("")|flex,
                        text("Organizador de Imagens") | bold | center,
                        text("")|flex,
                    });
    });

    auto main_container = Container::Vertical({navbar_con,main_header_con});

    auto main_renderer = Renderer(main_container, [&] {
        return vbox({
                        main_header->Render(),
                        navbar->Render()
                    });
    });

    screen.Loop(main_renderer);
}


#include <string>  // for char_traits, operator+, string, basic_string, to_string
#include <memory>  // for allocator, __shared_ptr_access

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

#include "./search.h"
#include "./process.h"

using namespace ftxui;

int main(int argc, char *argv[]) {

    auto screen = ScreenInteractive::Fullscreen();

    int value = 50;

    // The tree of components. This defines how to navigate using the keyboard.
    auto button_option = ButtonOption();
    button_option.border = false;
    auto buttons = Container::Horizontal({
                                                 Button(
                                                         "[Decrease]", [&] { value--; }, &button_option),
                                                 Button(
                                                         "[Increase]", [&] { value++; }, &button_option),
                                         });

    auto renderer_wrap = Renderer(buttons, [&] {
        return vbox({
                            text("value = " + std::to_string(value)),
                            separator(),
                            gauge(value * 0.01f),
                            separator(),
                            buttons->Render(),
                    }) |
               border;
    });

    auto buttonTest = Container::Horizontal({
                                                    Button(
                                                            "Pesquisar", [&] {
                                                                new Process();
                                                                value++;
                                                            }, &button_option),
                                            });

    auto termin = Renderer(buttonTest, [&] {
        return vbox({
                            buttonTest->Render(),
                    }) |
               border;
    });

    Search search = Search();

    auto main_container = Container::Vertical({
                                                      search.render,
                                                      renderer_wrap,
                                                      termin
                                              });

    auto main_renderer = Renderer(main_container, [&] {
        return vbox({
                            text("Organizador de Imagens") | bold | hcenter,
                            search.render->Render(),
                            renderer_wrap->Render(),
                            termin->Render(),
                    });
    });

    screen.Loop(main_renderer);
}
#ifndef DIRECTORIES_H
#define DIRECTORIES_H

#include <functional>  // for function
#include <string>  // for char_traits, operator+, string, basic_string, to_string
#include <memory>  // for allocator, __shared_ptr_access
#include <vector>
#include <iostream>

#include "ftxui/component/component_base.hpp"     // for ComponentBase
#include "ftxui/util/ref.hpp"  // for StringRef, Ref, WideStringRef, ConstStringRef
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border

#include <QString>

#include "./list.h"
#include "./traverse.h"
#include "./search.h"

using namespace ftxui;

class Directories : public ComponentBase {
public:
    int value;
    ButtonOption button_option = ButtonOption();
    std::shared_ptr<ComponentBase> submit_con;
    std::string  query;
    Component input;
    int selected = 0;
    MenuOption menu_option;
    List list_dir;
    std::shared_ptr<ComponentBase> dir_con;
    std::shared_ptr<ComponentBase> render;
    void addFiles(std::string i_string);
    Search *search_files;
    Directories(Search * i_search);
};

#endif // DIRECTORIES_H

#ifndef LIST_H
#define LIST_H

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

using namespace ftxui;

class List : public ComponentBase {
public:
    int selected = 0;
    MenuOption menu_option;
    std::vector<std::string> list;
    std::shared_ptr<ComponentBase> list_con = Container::Vertical({
                                                                      Menu(&list,&selected,&menu_option)
                                                                  });

    std::shared_ptr<ComponentBase> render = Renderer(list_con, [&] {
        return vbox({
                        list_con->Render()
                    }) | vscroll_indicator | frame |
                size(HEIGHT, LESS_THAN, 10) | border;
    });

};
#endif // LIST_H

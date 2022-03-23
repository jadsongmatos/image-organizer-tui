//
// Created by jadson on 09/03/2022.
//

#ifndef T5_SEARCH_H
#define T5_SEARCH_H

#include <functional>  // for function
#include <string>  // for char_traits, operator+, string, basic_string, to_string
#include <memory>  // for allocator, __shared_ptr_access
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

#include "ftxui/component/component_base.hpp"     // for ComponentBase
#include "ftxui/util/ref.hpp"  // for StringRef, Ref, WideStringRef, ConstStringRef
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border

#include <QString>

#include "./traverse.h"
#include "./list.h"

using namespace ftxui;

class Search : public ComponentBase {
public:
    ButtonOption button_option = ButtonOption();
    std::shared_ptr<ComponentBase> submit_con = Container::Horizontal({
                                                                          Button(
                                                                          "Pesquisar", [&] {
                                                                              if(query.compare("") == 0){
                                                                                  searchFiles(query);
                                                                                  a++;
                                                                              }
                                                                          }, &button_option),
                                                                      });
    Component input;
    List list_files;

    //List list_files_cont;
    std::shared_ptr<ComponentBase> input_con;
    std::string  query;
    std::shared_ptr<ComponentBase> render;
    void addFiles(std::string i_string);
    void searchFiles(std::string i_string);
    int a = 10;

    Search();
};


#endif //T5_SEARCH_H

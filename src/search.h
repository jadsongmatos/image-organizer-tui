//
// Created by jadson on 09/03/2022.
//

#ifndef T5_SEARCH_H
#define T5_SEARCH_H

#include <functional>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <regex>
#include <stdlib.h>
#include <stdexcept>
#include <stdio.h>
#include <future>

#include "ftxui/component/component_base.hpp"     // for ComponentBase
#include "ftxui/util/ref.hpp"  // for StringRef, Ref, WideStringRef, ConstStringRef
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border

#include <QString>
#include <QDir>

#include "./traverse.h"
#include "./list.h"

using namespace ftxui;

class Search : public ComponentBase {
public:
    ButtonOption button_option = ButtonOption();
    Component input;
    List list_files;
    List list_obj;

    //List list_files_cont;
    std::shared_ptr<ComponentBase> input_con;
    std::string query;
    int a = 10;

    std::shared_ptr<ComponentBase> submit_con = Container::Horizontal({
                                                                          Button(
                                                                          "Pesquisar", [&] {
                                                                              if(query.compare("")){
                                                                                  searchFiles(query);
                                                                                  a++;
                                                                              }
                                                                          }, &button_option),
                                                                      });

    std::shared_ptr<ComponentBase> render;
    void addFiles(int i,std::string i_string);
    void searchFiles(std::string i_string);

    Search();
};


#endif //T5_SEARCH_H

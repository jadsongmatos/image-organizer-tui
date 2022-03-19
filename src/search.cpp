//
// Created by jadson on 09/03/2022.
//

#include "search.h"

void Search::addFiles(std::string i_string){
    auto tmp = traverse(QString::fromUtf8(i_string.c_str()), 0);
    for(int i = 0; i < tmp.size();i++){
        list_files.list.push_back(tmp[i]);
    }
};

Search::Search(){
    input = Input(query, "cachorro");
    submit_con = Container::Horizontal({
                                           Button(
                                           "Pesquisar", [&] {
                                               query = "";
                                           }, &button_option),
                                       });

    input_con = Container::Vertical({
                                        input,
                                        submit_con,
                                        list_files.list_con
                                    });


    render = Renderer(input_con, [&] {
        return vbox({
                        hbox(
                        text("Buscar : ") | center,
                        input->Render() | center |flex ,
                        submit_con->Render() | center
                        ),
                        list_files.render->Render()
                    }) | border;
    });
};

//
// Created by jadson on 09/03/2022.
//

#include "search.h"

Search::Search() {

    files = {"test1","tesd"};

    files = traverse(QString("."),QString("/home/jadson/Downloads/"), 0);

    files_menu = Menu(&files,&selected,&menu_option);


    input = Input(query, "cachorro");
    submit_con = Container::Horizontal({
                                           Button(
                                           "Pesquisar", [&] {
                                               query = "";
                                           }, &button_option),
                                           files_menu
                                       });

    input_con = Container::Vertical({input,submit_con});


    render = Renderer(input_con, [&] {
        return vbox({
                        hbox(text("Buscar : "), input->Render()),
                        submit_con->Render()
                    }) | border;
    });
};

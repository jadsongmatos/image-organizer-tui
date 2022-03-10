//
// Created by jadson on 09/03/2022.
//

#include "search.h"

Search::Search() {
    input_first_name = Input(query, "Ex: cachorro");
    inputCom = Container::Vertical({input_first_name});

    render = Renderer(inputCom, [&] {
        return vbox({
                            hbox(text("Buscar : "), input_first_name->Render()),
                    }) | border;
    });
};

#include "directories.h"

Directories::Directories(Search * i_search) {
    search_files = i_search;
    input = Input(&query, "***");
    submit_con = Container::Horizontal({
                                           Button(
                                           "Adicionar", [&] {
                                               if(query.compare("")){
                                                   list_dir.list.push_back(query);
                                                   search_files->addFiles(query);
                                                   query = "";
                                               }
                                           }, &button_option),
                                       });

    dir_con = Container::Vertical({
                                      input,
                                      submit_con,
                                      list_dir.list_con
                                  });

    render = Renderer(dir_con, [&] {
        return vbox({
                        hbox({
                            text("Diretórios : ") | center,
                            input->Render() | center |flex ,
                            submit_con->Render() | center
                        }),
                        list_dir.render->Render()
                    }) | border;
    });
};

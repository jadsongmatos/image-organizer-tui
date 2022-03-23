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

void Search::searchFiles(std::string i_string){
    std::vector<std::string> tmp = list_files.list;

    /*
    copy_if(list_files.list.begin(), list_files.list.end(),
            back_inserter(tmp), [&](const std::string& i){
        return i.find(i_string) != ULLONG_MAX;
    });
    */

    sort(list_files.list.begin(), list_files.list.end(),
         [&](const std::string& a, const std::string& b) {
        return a.find(i_string) < b.find(i_string);
    });

    render = Renderer(input_con, [&] {
        return vbox({
                        hbox(
                        text("Buscar : " + std::to_string(a)) | center,
                        input->Render() | center |flex ,
                        submit_con->Render() | center
                        ),
                        list_files.render->Render()
                    }) | border;
    });

}

Search::Search(){

    input = Input(query, "***");


    input_con = Container::Vertical({
                                        input,
                                        submit_con,
                                        list_files.list_con
                                    });

    render = Renderer(input_con, [&] {
        return vbox({
                        hbox(
                        text("Buscar : " + std::to_string(a)) | center,
                        input->Render() | center |flex ,
                        submit_con->Render() | center
                        ),
                        list_files.render->Render()
                    }) | border;
    });
};

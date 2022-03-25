//
// Created by jadson on 09/03/2022.
//

#include "search.h"

int newProc(std::string cmd){
    return system(cmd.c_str());
}

void Search::addFiles(int i,std::string i_string){
    auto tmp = traverse(QString::fromUtf8(i_string.c_str()), 0);
    if(i < tmp.size()){
        list_files.list.push_back(tmp[i]);
        std::string comand = "mkdir -p /tmp/ai & python ./ai/ai.py '";
        comand = comand + tmp[i] + "' /tmp/ai/" + std::to_string(i) + ".json </dev/null &>/dev/null & ";

        std::future <int> ret = std::async(newProc,comand); //creates another process
        try{
            i++;
            addFiles(i,i_string);
        }
        catch(const std::exception& e){
            i++;
            addFiles(i,i_string);
        }
    }
};

void Search::searchFiles(std::string i_string){
    sort(list_files.list.begin(), list_files.list.end(),[&](const std::string& a, const std::string& b) {
        return a.find(i_string) < b.find(i_string);
    });
}

Search::Search(){

    input = Input(&query, "***");

    input_con = Container::Vertical({
                                        input,
                                        submit_con,
                                        list_files.list_con,
                                        list_obj.list_con
                                    });

    render = Renderer(input_con, [&] {
        return vbox({
                        hbox(
                        text("Buscar : " + std::to_string(a)) | center,
                        input->Render() | center |flex ,
                        submit_con->Render() | center
                        ),
                        list_files.render->Render(),
                        list_obj.render->Render()
                    }) | border;
    });
};

//
// Created by jadson on 09/03/2022.
//

#include "search.h"

int newProc(std::string cmd){
    return system(cmd.c_str());
}

void Search::addFiles(std::string i_string){
    auto tmp = traverse(QString::fromUtf8(i_string.c_str()), 0);
    int size = tmp.size();
    for(int i = 0; i < size;i++){
        list_files.list.push_back(tmp[i]);
        std::string comand = "mkdir -p /tmp/ai & python ./ai/ai.py '";
        comand = comand + tmp[i] + "' /tmp/" + std::to_string(i) + ".json </dev/null &>/dev/null & ";

        std::future <int> ret = std::async(newProc,comand); //creates another process
        try{
            int status = ret.get(); // wait for process to finish
            std::cout << status << std::endl;
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }

        //list_files.list.push_back(comand);
        //std::system("echo oi > /tmp/test.txt");
        //std::system(comand.c_str());
        //FILE* pipe = popen(comand.c_str(), "r");
        //pclose(pipe);
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

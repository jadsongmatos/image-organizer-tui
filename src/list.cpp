#include "list.h"


List::List(std::vector<std::string> list) {

    files = list;

    files_con = Container::Vertical({
                                        Menu(&files,&selected,&menu_option)
                                    });


    render = Renderer(files_con, [&] {
        return vbox({
                        files_con->Render()
                    }) | border;
    });
};

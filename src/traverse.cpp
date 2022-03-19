#include "traverse.h"


std::vector<std::string> traverse(const QString dirname, int level){
    std::vector<std::string> result;

    QDir dir(dirname);
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoSymLinks | QDir::NoDot | QDir::NoDotDot);

    std::string tmp_path;
    std::string tmp_extension;

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        tmp_path = list.at(i).absoluteFilePath().toStdString();
        tmp_extension = fs::path(tmp_path.c_str()).extension();
        if(
                tmp_extension == ".jpg"  ||
                tmp_extension == ".png"  ||
                tmp_extension == ".webp" ||
                tmp_extension == ".tif"
                ){
            result.push_back(tmp_path);
        }

    }
    return result;
}

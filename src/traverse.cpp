#include "traverse.h"


std::vector<std::string> traverse(const QString pattern, const QString dirname, int level){
    std::vector<std::string> result;

    QDir dir(dirname);
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoSymLinks | QDir::NoDot | QDir::NoDotDot);

    static const QStringList stringList = pattern.split('/');

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        if( list.at(0).isDir() ) {

        } else {
            result.push_back(list.at(i).absoluteFilePath().toStdString());
        }

    }
    return result;
}

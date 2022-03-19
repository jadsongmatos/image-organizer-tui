#ifndef TRAVERSE_H
#define TRAVERSE_H

#include <string>  // for char_traits, operator+, string, basic_string, to_string
#include <vector>
#include <filesystem>

#include <QDir>
#include <QFileInfoList>
#include <QString>
#include <QStringList>

namespace fs = std::filesystem;

std::vector<std::string> traverse(const QString dirname, int level);

#endif // TRAVERSE_H

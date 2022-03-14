#ifndef TRAVERSE_H
#define TRAVERSE_H

#include <string>  // for char_traits, operator+, string, basic_string, to_string
#include <vector>

#include <QDir>
#include <QFileInfoList>
#include <QString>
#include <QStringList>

std::vector<std::string> traverse(const QString pattern, const QString dirname, int level);

#endif // TRAVERSE_H

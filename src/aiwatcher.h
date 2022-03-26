#ifndef AIWATCHER_H
#define AIWATCHER_H

#include <QObject>
#include <QEventLoop>
#include <QFileSystemWatcher>
#include <QDirIterator>
#include <QString>
#include <QDir>
#include <QThread>
#include <string>
#include <memory>
#include <future>
#include <functional>

void aiWatcher(const std::string &path, std::function<void(const std::string &)> callback);

#endif // AIWATCHER_H

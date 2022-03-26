#include "aiwatcher.h"

/*
void aiWatcher(const std::string &path, std::function<void(const std::string &)> callback)
{
    QFileSystemWatcher watcher;
    QEventLoop loop;
    QObject::connect(&watcher, &QFileSystemWatcher::directoryChanged, [&]() {
        callback(path);
        loop.quit();
    });
    QDirIterator it(QString::fromStdString(path), QStringList() << "*", QDir::Files);
    while (it.hasNext()) {
        it.next();
        watcher.addPath(it.filePath());
    }
    loop.exec();
}
*/

/*
void aiWatcher(const std::string &path, std::function<void(const std::string&)> callback) {
    QFileSystemWatcher watcher;
    watcher.addPath(path.c_str());

    // for each change, call the callback in a separate thread
    QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, [&](const QString &path) {
        QThread* thread = new QThread;
        QObject::connect(thread, &QThread::started, [=] {
            callback(path.toStdString());
            thread->quit();
            thread->deleteLater();
        });
        thread->start();
    });
}
*/

void aiWatcher(const std::string &path, std::function<void(const std::string&)> callback) {
    QFileSystemWatcher watcher;
    watcher.addPath(QString::fromStdString(path));

    QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, QThread::currentThread(), [&](const QString &path) {
        callback(path.toStdString());
    });
}

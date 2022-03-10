//
// Created by jadson on 10/03/2022.
//

#ifndef IMAGE_ORGANIZER_TUI_PROCESS_H
#define IMAGE_ORGANIZER_TUI_PROCESS_H

#include <QProcess>
#include <QStringList>

class Process {
public:

    void read_output();

    void finished();

    Process();

};

#endif //IMAGE_ORGANIZER_TUI_PROCESS_H

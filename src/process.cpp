//
// Created by jadson on 10/03/2022.
//

#include "process.h"

Process::Process() {
    auto myProcess = new QProcess();
    myProcess->setProgram("echo");

    QStringList arguments;
    arguments << "oi" << ">" << "/tmp/test.txt";

    myProcess->setArguments(arguments);
    myProcess->start();
}


void Process::read_output() {
    //myProcess->readAllStandardOutput()
}

void Process::finished() {
    //ui->label_load->setText("");
    //ui->button_start->setEnabled(true);
}
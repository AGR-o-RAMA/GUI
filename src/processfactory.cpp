#include "processfactory.h"

ProcessFactory::ProcessFactory(QObject *parent)
    : QObject{parent}
{
    m_process = new QProcess(this);
    connect(m_process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(processFinished(int,QProcess::ExitStatus)));
}

void ProcessFactory::spawnProcess(QString path)
{
    m_process->start(path);
}

void ProcessFactory::processFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    bool success = (exitStatus == QProcess::NormalExit && exitCode == 0);
    emit processTerminated(exitCode, success);
}

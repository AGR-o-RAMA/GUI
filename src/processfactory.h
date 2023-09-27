#ifndef PROCESSFACTORY_H
#define PROCESSFACTORY_H

#include <QObject>
#include <QProcess>

class ProcessFactory : public QObject
{
    Q_OBJECT
public:
    explicit ProcessFactory(QObject *parent = nullptr);

public slots:
    void spawnProcess(QString path);

private slots:
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);

signals:
    void processTerminated(int exitCode, bool success);

private:
    QProcess *m_process;
};

#endif // PROCESSFACTORY_H

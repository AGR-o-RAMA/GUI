#ifndef APPLICATION_ENGINE_H
#define APPLICATION_ENGINE_H

#include <QQmlApplicationEngine>

class ApplicationEngine : public QQmlApplicationEngine{
    Q_OBJECT

public:
    ApplicationEngine(QQmlApplicationEngine *parent = nullptr);

public slots:
    int setup(QString api_key);
};

#endif // APPLICATION_ENGINE_H

#ifndef API_KEY_H
#define API_KEY_H

#include <QInputDialog>
#include <QObject>

class ApiKey : public QInputDialog
{
    Q_OBJECT

private:
    bool keySet = false;
    QString value = "";

public:
    ApiKey(QInputDialog *parent = nullptr);
    bool isKeySet();
    QString getValue();

public slots:
    void receiveKey();

private slots:
    void setKey(QString key);
    void writeKey(QString key);
    QString readKey();

signals:
    void keySetSignal(QString key);
};

#endif // API_KEY_H

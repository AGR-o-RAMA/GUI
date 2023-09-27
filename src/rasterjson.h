#ifndef RASTERJSON_H
#define RASTERJSON_H

#include <QWidget>
#include <QFile>
#define JSON_NAME "color.json"

class RasterJson : public QWidget
{
private:
    QString name;
    QString json_string;

public:
    RasterJson(QWidget *parent = nullptr);
public slots:
    void writeJSON();
};

#endif // RASTERJSON_H

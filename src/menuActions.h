
#ifndef MENUACTIONS_H
#define MENUACTIONS_H

#include <QTabWidget>
#include <QFileDialog>


class MenuActions : public QTabWidget
{
    Q_OBJECT
private:
    void readFromFile(const QString &fileName);
    void writeToFile(const QString &fileName);
public:
    MenuActions(QWidget *parent = nullptr);

public slots:
    void openProject();
    void saveProject();
    void quit();
};

#endif // MENUACTIONS_H

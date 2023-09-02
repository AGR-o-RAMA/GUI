
#ifndef MENUACTIONS_H
#define MENUACTIONS_H

#include <QTabWidget>
#include <QFileDialog>
#include <QWindow>
#include <QUrl>

class MenuActions : public QTabWidget
{
    Q_OBJECT
private:
    QUrl photo_path;
    QUrl project_path;
    QUrl output_path;
public:
    MenuActions(QWidget *parent = nullptr);

public slots:
    void openProject();
    void saveProject();
    void setPhotoPath();
    void setProjectPath();
    void setOutputPath();
};

#endif // MENUACTIONS_H

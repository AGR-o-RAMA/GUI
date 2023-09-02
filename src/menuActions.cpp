#include "menuActions.h"

#include <QDebug>
#include <QQmlProperty>
#include <QtWidgets>


MenuActions::MenuActions(QWidget *parent) : QTabWidget(parent){}

void MenuActions::openProject(){
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        QString ph;
        QString pr;
        QString ot;
        in >> ph;
        in >> pr;
        in >> ot;

        qDebug() << ph;
        qDebug() << pr;
        qDebug() << ot;
    }
}

void MenuActions::saveProject(){
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()){
        QFile file(fileName);

        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }

        QDataStream out(&file);
        out << photo_path.toString();
        out << project_path.toString();
        out << output_path.toString();
    }

}

void MenuActions::setProjectPath(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    project_path = url;
    qDebug() << url.toString();

}
void MenuActions::setOutputPath(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    output_path = url;
    qDebug() << url.toString();

}
void MenuActions::setPhotoPath(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    photo_path = url;
    qDebug() << url.toString();

}


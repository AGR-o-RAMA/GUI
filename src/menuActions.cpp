#include "menuActions.h"

#include <QDebug>
#include <QQmlProperty>
#include <QtWidgets>


MenuActions::MenuActions(QWidget *parent) : QTabWidget(parent){}

void MenuActions::openProject(){
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        readFromFile(fileName);
}

void MenuActions::saveProject(){
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty())
        writeToFile(fileName);
}

void MenuActions::quit(){
//    QWidget::close();
}

void MenuActions::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }

    QDataStream in(&file);

}

void MenuActions::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
}


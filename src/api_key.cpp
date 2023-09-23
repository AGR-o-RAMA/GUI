#include "api_key.h"

#include "ArcGISRuntimeEnvironment.h"
#include <QFile>

using namespace Esri::ArcGISRuntime;

ApiKey::ApiKey(QInputDialog *parent) : QInputDialog{parent}{}

bool ApiKey::isKeySet(){
    return keySet;
}

QString ApiKey::getValue(){
    return value;
}

void ApiKey::setKey(QString value){
    if (value.isEmpty()) receiveKey();
    else{
        this -> keySet = true;
        this -> value = value;
        ArcGISRuntimeEnvironment::setApiKey(value);
        writeKey(value);
        emit keySetSignal(value);
    }
}

void ApiKey::writeKey(QString value){
    QFile file(Esri::ArcGISRuntime::ArcGISRuntimeEnvironment::installDirectory() + "/sdk/linux/x64/.api_key");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << value;
        file.close();
    }
}

QString ApiKey::readKey(){
    QFile file(Esri::ArcGISRuntime::ArcGISRuntimeEnvironment::installDirectory() + "/sdk/linux/x64/.api_key");
    QString line = QString("");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        line = in.readLine();
        file.close();
    }
    return line;
}

void ApiKey::receiveKey(){
    QString key = readKey();
    resize(1000,100);
    setWindowTitle("Use of Esri location services, including basemaps, requires you to set the API Key");
    show();
    setInputMode(QInputDialog::TextInput);
    setTextValue(key);
    connect(this, SIGNAL(textValueSelected(QString)), this, SLOT(setKey(QString)));
}

//AAPKaee6e86df5054d838ca028100d788f8b7C1W1Equqmh_6BP-VdUGO7bZv2T70-GHdf4JbvDUP7IqRV9azY6QpRtjmZJENMP2


#include "coord_input.h"

using namespace Esri::ArcGISRuntime;

CoordInput::CoordInput(QDialog *parent) :
    QDialog{parent}, point_{} {
    setWindowTitle("Set some coordinates");
    QFormLayout* form = new QFormLayout(this);

    QLineEdit* long_edit = new QLineEdit(this);
    QString label2 = QString("Longitude");
    form->addRow(label2, long_edit);
    fields << long_edit;

    QLineEdit* lat_edit = new QLineEdit(this);
    QString label1 = QString("Latitude");
    form->addRow(label1, lat_edit);
    fields << lat_edit;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,Qt::Horizontal, this);
    form->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &CoordInput::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &CoordInput::reject);
}

QPointF CoordInput::getPoint(){
    if (this->exec()){
        double longit = fields[0]->text().toDouble();
        double latit = fields[1]->text().toDouble();
        point_ = QPointF(longit, latit);
    }
    return point_;
}

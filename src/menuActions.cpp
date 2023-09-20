#include "menuActions.h"

#include <QDebug>
#include <QQmlProperty>
#include <QtWidgets>
#include <QPixmap>
#include <QPalette>


MenuActions::MenuActions(QWidget *parent) : QTabWidget(parent), guiSubDir(GUI_SUB_PATH){}

void MenuActions::newProject()
{
    // PAGE 1
    QWizardPage *page = new QWizardPage;
    page->setTitle("Settings");

    label = new QLabel("Set all the infromation fields below.");
    label->setWordWrap(true);

    photo_label = new QLabel("Photo path: ");
    photo_label->setWordWrap(true);

    project_label = new QLabel("Project path: ");
    project_label->setWordWrap(true);

    output_label = new QLabel("Output path: ");
    output_label->setWordWrap(true);

    api_label = new QLabel("API Key: ");
    api_label->setWordWrap(true);

    photo_url = new QLineEdit(photo_path.toString());
    project_url = new QLineEdit(project_path.toString());
    output_url = new QLineEdit(output_path.toString());
    api_url = new QLineEdit(api_key);

    button_photo = new QPushButton("&Open...", this);
    connect(button_photo, &QPushButton::released, this, &MenuActions::setPhotoPath);

    button_project= new QPushButton("&Open...", this);
    connect(button_project, &QPushButton::released, this, &MenuActions::setProjectPath);

    button_output = new QPushButton("&Open...", this);
    connect(button_output, &QPushButton::released, this, &MenuActions::setOutputPath);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 1);
    layout->addWidget(photo_label, 1,0);
    layout->addWidget(photo_url, 1, 1);
    layout->addWidget(button_photo, 1, 2);

    layout->addWidget(project_label, 2,0);
    layout->addWidget(project_url, 2, 1);
    layout->addWidget(button_project, 2, 2);

    layout->addWidget(output_label, 3,0);
    layout->addWidget(output_url, 3, 1);
    layout->addWidget(button_output, 3, 2);

    layout->addWidget(api_label, 4, 0);
    layout->addWidget(api_url, 4, 1);
    page->setLayout(layout);

    wizard_settings = new QWizard();
    wizard_settings->addPage(page);
    wizard_settings->setWindowTitle("New Project");

    wizard_settings->setOptions(QWizard::NoBackButtonOnLastPage);
    wizard_settings->show();

    connect(wizard_settings->button(QWizard::FinishButton),
            SIGNAL(clicked()),this,SLOT(onCreateFinished()));

}

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
        QString key;
        in >> ph;
        in >> pr;
        in >> ot;
        in >> key;

        qDebug() << ph;
        qDebug() << pr;
        qDebug() << ot;
        qDebug() << key;
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
        out << api_key;
    }

}

void MenuActions::setProjectPath(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 ".",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    project_url->selectAll();
    project_url->del();
    project_url->insert(url.toString());
    qDebug() << project_url->text();

}
void MenuActions::setOutputPath(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 ".",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    output_url->selectAll();
    output_url->del();
    output_url->insert(url.toString());
    qDebug() << output_url->text();

}
void MenuActions::setPhotoPath(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 ".",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    photo_url->selectAll();
    photo_url->del();
    photo_url->insert(url.toString());
    qDebug() << photo_url->text();
}

void MenuActions::setApiKey(){
    QString key = QInputDialog::getText(this, tr("Insert API Key"),
                                        tr("API Key:"), QLineEdit::Normal);
    api_key = key;
    qDebug() << key;

}

void MenuActions::create_filterPointsUSGS(){
    filterUSGS_box = new QGroupBox(tr("Filter Points USGS"));

    QLabel *enableUSGS_label = new QLabel("Enable: ");
    enableUSGS = new QComboBox();
    enableUSGS->addItem("True");
    enableUSGS->addItem("False");

    QLabel *recPercUSGS_label = new QLabel("Rec Thresh Percentage: ");
    recPercUSGS = new QDoubleSpinBox();

    QLabel *recAbsUSGS_label = new QLabel("Rec Thresh Absolute: ");
    recAbsUSGS = new QDoubleSpinBox();

    QLabel *projPercUSGS_label = new QLabel("Proj Thresh Percentage: ");
    projPercUSGS = new QDoubleSpinBox();

    QLabel *projAbsUSGS_label = new QLabel("Proj Thresh Absolute: ");
    projAbsUSGS = new QDoubleSpinBox();

    QLabel *reprojPercUSGS_label = new QLabel("Reproj Thresh Percentage: ");
    reprojPercUSGS = new QDoubleSpinBox();

    QLabel *reprojAbsUSGS_label = new QLabel("Reproj Thresh Absolute: ");
    reprojAbsUSGS = new QDoubleSpinBox();

    QGridLayout* layoutFilter= new QGridLayout;
    layoutFilter->addWidget(enableUSGS_label, 0, 0);
    layoutFilter->addWidget(enableUSGS, 0, 1);

    layoutFilter->addWidget(recPercUSGS_label, 1,0);
    layoutFilter->addWidget(recPercUSGS, 1,1);

    layoutFilter->addWidget(recAbsUSGS_label, 2,0);
    layoutFilter->addWidget(recAbsUSGS, 2,1);

    layoutFilter->addWidget(projPercUSGS_label, 3,0);
    layoutFilter->addWidget(projPercUSGS, 3,1);

    layoutFilter->addWidget(projAbsUSGS_label, 4,0);
    layoutFilter->addWidget(projAbsUSGS, 4,1);

    layoutFilter->addWidget(reprojPercUSGS_label, 5,0);
    layoutFilter->addWidget(reprojPercUSGS, 5,1);

    layoutFilter->addWidget(reprojAbsUSGS_label, 6,0);
    layoutFilter->addWidget(reprojAbsUSGS, 6,1);

    filterUSGS_box->setLayout(layoutFilter);
}

void MenuActions::create_optimizeCamera(){
    optimizeCamera_box = new QGroupBox(tr("Optimize Camera Settings"));

    QLabel *enableOpt_label = new QLabel("Enable: ");
    enableOpt = new QComboBox();
    enableOpt->addItem("True");
    enableOpt->addItem("False");

    QLabel *adaptiveOpt_label = new QLabel("Adaptive Fitting: ");
    adaptiveOpt = new QComboBox();
    adaptiveOpt->addItem("True");
    adaptiveOpt->addItem("False");

    QGridLayout* layoutOpt = new QGridLayout();
    layoutOpt->addWidget(enableOpt_label, 0,0);
    layoutOpt->addWidget(enableOpt, 0,1);

    layoutOpt->addWidget(adaptiveOpt_label, 1,0);
    layoutOpt->addWidget(adaptiveOpt, 1,1);

    optimizeCamera_box->setLayout(layoutOpt);
}

void MenuActions::create_pointCloud(){

    pointCloud_box = new QGroupBox(tr("Build Point Cloud Settings"));

    QLabel* enableCloud_label = new QLabel("Enable: ");
    enableCloud = new QComboBox();
    enableCloud->addItem("True");
    enableCloud->addItem("False");

    QLabel *downscaleCloud_label = new QLabel("Downscale: ");
    downscaleCloud = new QDoubleSpinBox();

    QLabel* filterCloud_label = new QLabel("Filter Mode: ");
    filterCloud = new QLineEdit();

    QLabel* reuseCloud_label = new QLabel("Reuse depth: ");
    reuseCloud = new QComboBox();
    reuseCloud->addItem("True");
    reuseCloud->addItem("False");

    QLabel* keepCloud_label = new QLabel("Keep depth: ");
    keepCloud = new QComboBox();
    keepCloud->addItem("False");
    keepCloud->addItem("True");

    QLabel* maxneighborsCloud_label = new QLabel("Max Neighbors: ");
    maxneighborsCloud = new QDoubleSpinBox();

    QLabel* classifyCloud_label = new QLabel("Classify Ground Points: ");
    classifyCloud = new QComboBox();
    classifyCloud->addItem("True");
    classifyCloud->addItem("False");

    QLabel* exportCloud_label = new QLabel("Export: ");
    exportCloud = new QComboBox();
    exportCloud->addItem("True");
    exportCloud->addItem("False");

    QLabel* classesCloud_label = new QLabel("Classes: ");
    classesCloud = new QLineEdit();

    QGridLayout* layoutCloud = new QGridLayout;
    layoutCloud->addWidget(enableCloud_label, 0, 0);
    layoutCloud->addWidget(enableCloud, 0, 1);
    layoutCloud->addWidget(downscaleCloud_label, 1, 0);
    layoutCloud->addWidget(downscaleCloud, 1, 1);
    layoutCloud->addWidget(filterCloud_label, 2, 0);
    layoutCloud->addWidget(filterCloud, 2, 1);
    layoutCloud->addWidget(reuseCloud_label, 3, 0);
    layoutCloud->addWidget(reuseCloud, 3,1);
    layoutCloud->addWidget(keepCloud_label, 4,0);
    layoutCloud->addWidget(keepCloud, 4,1);
    layoutCloud->addWidget(maxneighborsCloud_label, 5,0);
    layoutCloud->addWidget(maxneighborsCloud,5,1);
    layoutCloud->addWidget(classifyCloud_label, 6,0);
    layoutCloud->addWidget(classifyCloud, 6,1);
    layoutCloud->addWidget(exportCloud_label, 7,0);
    layoutCloud->addWidget(exportCloud, 7,1);
    layoutCloud->addWidget(classesCloud_label, 8,0);
    layoutCloud->addWidget(classesCloud, 8,1);

    pointCloud_box->setLayout(layoutCloud);

}

void MenuActions::create_classifyGround(){
    classifyGround_box = new QGroupBox(tr("Classify Ground Points Settings"));

    QLabel* angleClassify_label = new QLabel("Max Angles: ");
    angleClassify = new QDoubleSpinBox();

    QLabel* distanceClassify_label = new QLabel("Max Distances: ");
    distanceClassify = new QDoubleSpinBox();

    QLabel* cellClassify_label = new QLabel("Cell Size: ");
    cellClassify = new QDoubleSpinBox();

    QGridLayout* layoutClassify= new QGridLayout;
    layoutClassify->addWidget(angleClassify_label, 0, 0);
    layoutClassify->addWidget(angleClassify, 0, 1);

    layoutClassify->addWidget(distanceClassify_label, 1, 0);
    layoutClassify->addWidget(distanceClassify, 1, 1);

    layoutClassify->addWidget(cellClassify_label, 2, 0);
    layoutClassify->addWidget(cellClassify, 2, 1);

    classifyGround_box->setLayout(layoutClassify);
}

void MenuActions::create_DEM(){
    dem_box = new QGroupBox(tr("Digital Elevation Model (DEM)"));

    QLabel *enableDEM_label = new QLabel("Enable: ");
    enableDEM = new QComboBox();
    enableDEM->addItem("True");
    enableDEM->addItem("False");

    QLabel* classifyDEM_label = new QLabel("Classify Ground Points: ");
    classifyDEM = new QComboBox();
    classifyDEM->addItem("True");
    classifyDEM->addItem("False");

    QLabel* typeDEM_label = new QLabel("Type: ");
    typeDEM = new QLineEdit();

    QLabel* exportDEM_label = new QLabel("Export: ");
    exportDEM = new QComboBox();
    exportDEM->addItem("True");
    exportDEM->addItem("False");

    QLabel* bigDEM_label = new QLabel("Tiff Big: ");
    bigDEM = new QComboBox();
    bigDEM->addItem("True");
    bigDEM->addItem("False");

    QLabel* tiledDEM_label = new QLabel("Tiff Tiled: ");
    tiledDEM = new QComboBox();
    tiledDEM->addItem("True");
    tiledDEM->addItem("False");

    QLabel* nodataDEM_label = new QLabel("Nodata: ");
    nodataDEM = new QDoubleSpinBox();

    QLabel* overviewsDEM_label = new QLabel("Tiff Tiled: ");
    overviewsDEM = new QComboBox();
    overviewsDEM->addItem("True");
    overviewsDEM->addItem("False");


    QGridLayout* layoutDEM = new QGridLayout;
    layoutDEM->addWidget(enableDEM_label, 0, 0);
    layoutDEM->addWidget(enableDEM, 0, 1);

    layoutDEM->addWidget(classifyDEM_label, 1, 0);
    layoutDEM->addWidget(classifyDEM, 1, 1);

    layoutDEM->addWidget(typeDEM_label, 2, 0);
    layoutDEM->addWidget(typeDEM, 2, 1);

    layoutDEM->addWidget(exportDEM_label, 3, 0);
    layoutDEM->addWidget(exportDEM, 3,1);

    layoutDEM->addWidget(bigDEM_label, 4,0);
    layoutDEM->addWidget(bigDEM, 4,1);

    layoutDEM->addWidget(tiledDEM_label, 5,0);
    layoutDEM->addWidget(tiledDEM,5,1);

    layoutDEM->addWidget(nodataDEM_label, 6,0);
    layoutDEM->addWidget(nodataDEM, 6,1);

    layoutDEM->addWidget(overviewsDEM_label, 7,0);
    layoutDEM->addWidget(overviewsDEM, 7,1);

    dem_box->setLayout(layoutDEM);

}

void MenuActions::create_orthomosaic(){
    ortho_box = new QGroupBox(tr("Orthomosaic Settings"));

    QLabel* enableOrtho_label = new QLabel("Enable: ");
    enableOrtho = new QComboBox();
    enableOrtho->addItem("True");
    enableOrtho->addItem("False");

    QLabel* surfaceOrtho_label = new QLabel("Surface: ");
    surfaceOrtho = new QLineEdit();

    QLabel* pathOrtho_label = new QLabel("Path: ");
    pathOrtho = new QLineEdit();

    QLabel* crsOrtho_label = new QLabel("CRS: ");
    crsOrtho = new QLineEdit();

    QLabel* blendingOrtho_label = new QLabel("Blending: ");
    blendingOrtho = new QLineEdit();

    QLabel* holesOrtho_label = new QLabel("Fill Holes: ");
    holesOrtho = new QComboBox();
    holesOrtho->addItem("True");
    holesOrtho->addItem("False");

    QLabel* seamlinesOrtho_label = new QLabel("Refine Seamlines: ");
    seamlinesOrtho = new QComboBox();
    seamlinesOrtho->addItem("True");
    seamlinesOrtho->addItem("False");

    QLabel* exportOrtho_label = new QLabel("Export: ");
    exportOrtho = new QComboBox();
    exportOrtho->addItem("True");
    exportOrtho->addItem("False");

    QLabel* bigOrtho_label = new QLabel("Tiff big: ");
    bigOrtho = new QComboBox();
    bigOrtho->addItem("True");
    bigOrtho->addItem("False");

    QLabel* tiledOrtho_label = new QLabel("Tiff tiled: ");
    tiledOrtho = new QComboBox();
    tiledOrtho->addItem("True");
    tiledOrtho->addItem("False");

    QLabel* nodataOrtho_label = new QLabel("Nodata: ");
    nodataOrtho = new QDoubleSpinBox();

    QLabel* overviewsOrtho_label = new QLabel("Tiff Overviews: ");
    overviewsOrtho = new QComboBox();
    overviewsOrtho->addItem("True");
    overviewsOrtho->addItem("False");

    QGridLayout* layoutOrtho = new QGridLayout;
    layoutOrtho->addWidget(enableOrtho_label, 0, 0);
    layoutOrtho->addWidget(enableOrtho, 0, 1);
    layoutOrtho->addWidget(surfaceOrtho_label, 1, 0);
    layoutOrtho->addWidget(surfaceOrtho, 1, 1);
    layoutOrtho->addWidget(pathOrtho_label, 2, 0);
    layoutOrtho->addWidget(pathOrtho, 2, 1);
    layoutOrtho->addWidget(crsOrtho_label, 3, 0);
    layoutOrtho->addWidget(crsOrtho, 3,1);
    layoutOrtho->addWidget(blendingOrtho_label, 4,0);
    layoutOrtho->addWidget(blendingOrtho, 4,1);
    layoutOrtho->addWidget(holesOrtho_label, 5,0);
    layoutOrtho->addWidget(holesOrtho, 5,1);
    layoutOrtho->addWidget(seamlinesOrtho_label, 6,0);
    layoutOrtho->addWidget(seamlinesOrtho,6,1);
    layoutOrtho->addWidget(exportOrtho_label, 7,0);
    layoutOrtho->addWidget(exportOrtho, 7,1);
    layoutOrtho->addWidget(bigOrtho_label, 8,0);
    layoutOrtho->addWidget(bigOrtho, 8,1);
    layoutOrtho->addWidget(tiledOrtho_label, 9,0);
    layoutOrtho->addWidget(tiledOrtho, 9,1);
    layoutOrtho->addWidget(nodataOrtho_label, 10,0);
    layoutOrtho->addWidget(nodataOrtho, 10,1);
    layoutOrtho->addWidget(overviewsOrtho_label, 11,0);
    layoutOrtho->addWidget(overviewsOrtho, 11,1);

    ortho_box->setLayout(layoutOrtho);
}

void MenuActions::create_alignPhotos(){
    alignPhotos_box = new QGroupBox(tr("Align Photos Settings"));

    QLabel *enableAlign_label = new QLabel("Enable: ");
    enableAlign = new QComboBox();
    enableAlign->addItem("True");
    enableAlign->addItem("False");

    QLabel *downscaleAlign_label = new QLabel("Downscale: ");
    downscaleAlign = new QDoubleSpinBox();

    QLabel *adaptiveAlign_label = new QLabel("Adaptive fitting: ");
    adaptiveAlign = new QComboBox();
    adaptiveAlign->addItem("True");
    adaptiveAlign->addItem("False");

    QLabel *keypointsAlign_label = new QLabel("Keep Keypoints: ");
    keypointsAlign = new QComboBox();
    keypointsAlign->addItem("True");
    keypointsAlign->addItem("False");

    QLabel *resetAlign_label = new QLabel("Reset Alignment: ");
    resetAlign = new QComboBox();
    resetAlign->addItem("True");
    resetAlign->addItem("False");

    QLabel *genPreAlign_label = new QLabel("Generic Preselection: ");
    genPreAlign = new QComboBox();
    genPreAlign->addItem("True");
    genPreAlign->addItem("False");

    QLabel *refPreAlign_label = new QLabel("Reference Preselection: ");
    refPreAlign = new QComboBox();
    refPreAlign->addItem("True");
    refPreAlign->addItem("False");

    QLabel *preModeAlign_label = new QLabel("Reference Preselection Mode: ");
    preModeAlign = new QLineEdit("Metashape.ReferencePreselectionSource"); //DUBBIO


    QGridLayout* layoutAlign = new QGridLayout;
    layoutAlign->addWidget(enableAlign_label, 0, 0);
    layoutAlign->addWidget(enableAlign, 0, 1);

    layoutAlign->addWidget(downscaleAlign_label, 1, 0);
    layoutAlign->addWidget(downscaleAlign, 1, 1);

    layoutAlign->addWidget(adaptiveAlign_label, 2, 0);
    layoutAlign->addWidget(adaptiveAlign, 2, 1);

    layoutAlign->addWidget(keypointsAlign_label, 3, 0);
    layoutAlign->addWidget(keypointsAlign, 3,1);

    layoutAlign->addWidget(resetAlign_label, 4,0);
    layoutAlign->addWidget(resetAlign, 4,1);

    layoutAlign->addWidget(genPreAlign_label, 5,0);
    layoutAlign->addWidget(genPreAlign,5,1);

    layoutAlign->addWidget(refPreAlign_label, 6,0);
    layoutAlign->addWidget(refPreAlign, 6,1);

    layoutAlign->addWidget(preModeAlign_label, 7,0);
    layoutAlign->addWidget(preModeAlign, 7,1);

    alignPhotos_box->setLayout(layoutAlign);

}

void MenuActions::setSettings(){

    // PAGE 1
    QWizardPage *page = new QWizardPage;
    page->setTitle("Settings");

    label = new QLabel("Set all the infromation fields below.");
    label->setWordWrap(true);

    photo_label = new QLabel("Photo path: ");
    photo_label->setWordWrap(true);

    project_label = new QLabel("Project path: ");
    project_label->setWordWrap(true);

    output_label = new QLabel("Output path: ");
    output_label->setWordWrap(true);

    api_label = new QLabel("API Key: ");
    api_label->setWordWrap(true);

    photo_url = new QLineEdit(photo_path.toString());
    project_url = new QLineEdit(project_path.toString());
    output_url = new QLineEdit(output_path.toString());
    api_url = new QLineEdit(api_key);

    button_photo = new QPushButton("&Open...", this);
    connect(button_photo, &QPushButton::released, this, &MenuActions::setPhotoPath);

    button_project= new QPushButton("&Open...", this);
    connect(button_project, &QPushButton::released, this, &MenuActions::setProjectPath);

    button_output = new QPushButton("&Open...", this);
    connect(button_output, &QPushButton::released, this, &MenuActions::setOutputPath);


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 1);
    layout->addWidget(photo_label, 1,0);
    layout->addWidget(photo_url, 1, 1);
    layout->addWidget(button_photo, 1, 2);

    layout->addWidget(project_label, 2,0);
    layout->addWidget(project_url, 2, 1);
    layout->addWidget(button_project, 2, 2);

    layout->addWidget(output_label, 3,0);
    layout->addWidget(output_url, 3, 1);
    layout->addWidget(button_output, 3, 2);

    layout->addWidget(api_label, 4, 0);
    layout->addWidget(api_url, 4, 1);
    page->setLayout(layout);


    // PAGE 2
    QWizardPage *page2 = new QWizardPage;
    scrollArea = new QScrollArea;

    page2->setTitle("Advanced Settings");

    label2 = new QLabel("Change these informations only if necessary: ");
    label2->setWordWrap(true);


    create_alignPhotos();
    create_optimizeCamera();
    create_filterPointsUSGS();
    create_pointCloud();
    create_classifyGround();
    create_DEM();
    create_orthomosaic();

    QWidget* containerWidget = new QWidget();
    QGridLayout *layout2 = new QGridLayout;
    layout2->addWidget(label2, 0, 1);
    layout2->addWidget(alignPhotos_box, 1,1);
    layout2->addWidget(filterUSGS_box, 2,1);
    layout2->addWidget(optimizeCamera_box, 3,1);
    layout2->addWidget(pointCloud_box,4,1);
    layout2->addWidget(classifyGround_box, 5,1);
    layout2->addWidget(dem_box,6,1);
    layout2->addWidget(ortho_box,7,1);


    containerWidget->setLayout(layout2);
    scrollArea->setWidget(containerWidget);
    scrollArea->setWidgetResizable(true);

    // Enable vertical scrollbar for page2
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(scrollArea);
    page2->setLayout(mainLayout);

    wizard_settings = new QWizard();
    wizard_settings->addPage(page);
    wizard_settings->addPage(page2);
    wizard_settings->setWindowTitle("Configure");
    wizard_settings->show();
}

void MenuActions::onCreateFinished()
{
    // TODO: sanity check
    // QDir("Folder").exists();
    QUrl path = project_path.resolved(guiSubDir);
    QDir().mkpath(path.toString());

    // TODO: scrivi yaml save
}

#include "menuActions.h"

#include <QDebug>
#include <QQmlProperty>
#include <QtWidgets>
#include <QPixmap>
#include <QPalette>
#include "ArcGISRuntimeEnvironment.h"
#include "settings.h"


MenuActions::MenuActions(QWidget *parent) : QTabWidget(parent){}

void MenuActions::newProject(QQuickItem* leftWindow)
{
    this->leftWindow = leftWindow;
    // PAGE 1
    NewWizardPage *page = new NewWizardPage();
    page->setTitle("Settings");

    label = new QLabel("Set all the infromation fields below.");
    label->setWordWrap(true);

    photo_label = new QLabel("Photo path: ");
    photo_label->setWordWrap(true);

    project_label = new QLabel("Project path: ");
    project_label->setWordWrap(true);

    output_label = new QLabel("Output path: ");
    output_label->setWordWrap(true);


    photo_line = new QLineEdit();
    photo_line->setObjectName("photo_line");
    project_line = new QLineEdit();
    project_line->setObjectName("project_line");
    output_line = new QLineEdit();
    output_line->setObjectName("output_line"),

    button_photo = new QPushButton("&Open...", this);
    connect(button_photo, &QPushButton::released, this, &MenuActions::setPhotoUrl);

    button_project= new QPushButton("&Open...", this);
    connect(button_project, &QPushButton::released, this, &MenuActions::setProjectUrl);

    button_output = new QPushButton("&Open...", this);
    connect(button_output, &QPushButton::released, this, &MenuActions::setOutputUrl);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 1);
    layout->addWidget(photo_label, 1,0);
    layout->addWidget(photo_line, 1, 1);
    layout->addWidget(button_photo, 1, 2);

    layout->addWidget(project_label, 2,0);
    layout->addWidget(project_line, 2, 1);
    layout->addWidget(button_project, 2, 2);

    layout->addWidget(output_label, 3,0);
    layout->addWidget(output_line, 3, 1);
    layout->addWidget(button_output, 3, 2);
    page->setLayout(layout);

    wizard_settings = new QWizard();
    wizard_settings->addPage(page);
    wizard_settings->setWindowTitle("New Project");

    wizard_settings->setOptions(QWizard::NoBackButtonOnLastPage);
    wizard_settings->show();

    connect(page,
            SIGNAL(sanityCheckPassedSignal()),this,SLOT(onCreateFinished()));

}

void MenuActions::openProject(QQuickItem* leftWindow){

    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Select the project directory"),
                                                 ".",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QString dirName = url.toString();
    std::vector<QString> vs = {dirName, Settings::guiSubDir, Settings::yamlSaveName};
    QString fileName = Settings::pathJoin(vs);

    YAML::Node saveFile = YAML::LoadFile(fileName.toStdString());

    Settings::photo_path = QUrl(saveFile["photo_path"].as<std::string>().c_str());
    Settings::project_path = QUrl(saveFile["project_path"].as<std::string>().c_str());
    Settings::output_path = QUrl(saveFile["output_path"].as<std::string>().c_str());

    Settings::run_name = QString(saveFile["run_name"].as<std::string>().c_str());
    Settings::project_crs = QString(saveFile["project_crs"].as<std::string>().c_str());
    Settings::subdivide_task = saveFile["subdivide_task"].as<bool>();
    Settings::use_cuda = saveFile["use_cuda"].as<bool>();

    Settings::enabled_align = saveFile["alignPhotos"]["enabled"].as<bool>();
    Settings::downscale_align = saveFile["alignPhotos"]["downscale"].as<int>();
    Settings::adaptive_align = saveFile["alignPhotos"]["adaptive_fitting"].as<bool>();
    Settings::keypoints_align = saveFile["alignPhotos"]["keep_keypoints"].as<bool>();
    Settings::reset_align = saveFile["alignPhotos"]["reset_alignment"].as<bool>();
    Settings::genPre_align = saveFile["alignPhotos"]["generic_preselection"].as<bool>();
    Settings::refPre_align = saveFile["alignPhotos"]["reference_preselection"].as<bool>();
    Settings::preMode_align = QString(saveFile["alignPhotos"]["reference_preselection_mode"].as<std::string>().c_str());

    Settings::enable_USGS = saveFile["filterPointsUSGS"]["enabled"].as<bool>();
    Settings::recPerc_USGS = saveFile["filterPointsUSGS"]["rec_thresh_percent"].as<double>();
    Settings::recAbs_USGS = saveFile["filterPointsUSGS"]["rec_thresh_absolute"].as<double>();
    Settings::projPerc_USGS = saveFile["filterPointsUSGS"]["proj_thresh_percent"].as<double>();
    Settings::projAbs_USGS = saveFile["filterPointsUSGS"]["proj_thresh_absolute"].as<double>();
    Settings::reprojPerc_USGS = saveFile["filterPointsUSGS"]["reproj_thresh_percent"].as<double>();
    Settings::reprojAbs_USGS = saveFile["filterPointsUSGS"]["reproj_thresh_absolute"].as<double>();

    Settings::enable_opt = saveFile["optimizeCameras"]["enabled"].as<bool>();
    Settings::adaptive_opt = saveFile["optimizeCameras"]["adaptive_fitting"].as<bool>();

    Settings::enable_cloud = saveFile["buildPointCloud"]["enabled"].as<bool>();
    Settings::downscale_cloud = saveFile["buildPointCloud"]["downscale"].as<double>();
    Settings::filter_cloud = QString(saveFile["buildPointCloud"]["filter_mode"].as<std::string>().c_str());
    Settings::reuse_cloud = saveFile["buildPointCloud"]["reuse_depth"].as<bool>();
    Settings::keep_cloud = saveFile["buildPointCloud"]["keep_depth"].as<bool>();
    Settings::maxneighbors_cloud = saveFile["buildPointCloud"]["max_neighbors"].as<int>();
    Settings::classify_cloud = saveFile["buildPointCloud"]["classify_ground_points"].as<bool>();
    Settings::export_cloud = saveFile["buildPointCloud"]["export"].as<bool>();
    Settings::classes_cloud = QString(saveFile["buildPointCloud"]["classes"].as<std::string>().c_str());

    Settings::angle_classify = saveFile["classifyGroundPoints"]["max_angle"].as<double>();
    Settings::distance_classify = saveFile["classifyGroundPoints"]["max_distance"].as<double>();
    Settings::cell_classify = saveFile["classifyGroundPoints"]["cell_size"].as<double>();

    Settings::enable_DEM = saveFile["buildDem"]["enabled"].as<bool>();
    Settings::classify_DEM = saveFile["buildDem"]["classify_ground_points"].as<bool>();
    Settings::type_DEM = QString(saveFile["buildDem"]["type"].as<std::string>().c_str());
    Settings::export_DEM = saveFile["buildDem"]["export"].as<bool>();
    Settings::big_DEM = saveFile["buildDem"]["tiff_big"].as<bool>();
    Settings::tiled_DEM = saveFile["buildDem"]["tiff_tiled"].as<bool>();
    Settings::nodata_DEM = saveFile["buildDem"]["nodata"].as<int>();
    Settings::overviews_DEM = saveFile["buildDem"]["tiff_overviews"].as<bool>();

    Settings::enable_ortho = saveFile["buildOrthomosaic"]["enabled"].as<bool>();
    Settings::surface_ortho = QString(saveFile["buildOrthomosaic"]["surface"].as<std::string>().c_str());
    Settings::path_ortho = QString(saveFile["buildOrthomosaic"]["usgs_dem_path"].as<std::string>().c_str());
    Settings::crs_ortho = QString(saveFile["buildOrthomosaic"]["usgs_dem_crs"].as<std::string>().c_str());
    Settings::blending_ortho = QString(saveFile["buildOrthomosaic"]["blending"].as<std::string>().c_str());
    Settings::holes_ortho = saveFile["buildOrthomosaic"]["fill_holes"].as<bool>();
    Settings::seamlines_ortho = saveFile["buildOrthomosaic"]["refine_seamlines"].as<bool>();
    Settings::export_ortho = saveFile["buildOrthomosaic"]["export"].as<bool>();
    Settings::big_ortho = saveFile["buildOrthomosaic"]["tiff_big"].as<bool>();
    Settings::tiled_ortho = saveFile["buildOrthomosaic"]["tiff_tiled"].as<bool>();
    Settings::nodata_ortho = saveFile["buildOrthomosaic"]["nodata"].as<int>();
    Settings::overviews_ortho = saveFile["buildOrthomosaic"]["tiff_overviews"].as<bool>();
    leftWindow->setEnabled(true);
}

void MenuActions::setProjectUrl(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 ".",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    project_line->selectAll();
    project_line->del();
    project_line->insert(url.toString());
    qDebug() << project_line->text();

}
void MenuActions::setOutputUrl(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 ".",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    output_line->selectAll();
    output_line->del();
    output_line->insert(url.toString());
    qDebug() << output_line->text();

}
void MenuActions::setPhotoUrl(){
    QUrl url = QFileDialog::getExistingDirectory(this,
                                                 tr("Open Directory"),
                                                 ".",
                                                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!url.isValid()) {
        qDebug("Invalid URL: %s", qUtf8Printable(url.toString()));
    }
    photo_line->selectAll();
    photo_line->del();
    photo_line->insert(url.toString());
    qDebug() << photo_line->text();
}


void MenuActions::create_preliminary(){
    preliminary_box = new QGroupBox(tr("Preliminary Settings"));

    QLabel *crs_label = new QLabel("Coordinate Reference System: ");
    crs_line = new QLineEdit(Settings::project_crs);
    crs_line->setObjectName("crs_line");


    QLabel *task_label = new QLabel("Subdivide task: ");
    task_box = new QComboBox();
    if(Settings::subdivide_task){
        task_box->addItem(QString("True"));
        task_box->addItem(QString("False"));
    }else{
        task_box->addItem(QString("False"));
        task_box->addItem(QString("True"));
    }

    QGridLayout* layoutPre = new QGridLayout;
    layoutPre->addWidget(crs_label, 0,0);
    layoutPre->addWidget(crs_line,0,1);

    layoutPre->addWidget(task_label,1,0);
    layoutPre->addWidget(task_box,1,1);

    preliminary_box->setLayout(layoutPre);

}

void MenuActions::create_alignPhotos(){
    alignPhotos_box = new QGroupBox(tr("Align Photos Settings"));

    QLabel *enableAlign_label = new QLabel("Enable: ");
    enableAlign = new QComboBox();
    if(Settings::enabled_align){
        enableAlign->addItem(QString("True"));
        enableAlign->addItem(QString("False"));
    }else{
        enableAlign->addItem(QString("False"));
        enableAlign->addItem(QString("True"));
    }
    QLabel *downscaleAlign_label = new QLabel("Downscale: ");
    downscaleAlign = new QDoubleSpinBox();
    downscaleAlign->setValue(Settings::downscale_align);

    QLabel *adaptiveAlign_label = new QLabel("Adaptive fitting: ");
    adaptiveAlign = new QComboBox();
    if(Settings::adaptive_align){
        adaptiveAlign->addItem(QString("True"));
        adaptiveAlign->addItem(QString("False"));
    }else{
        adaptiveAlign->addItem(QString("False"));
        adaptiveAlign->addItem(QString("True"));
    }
    QLabel *keypointsAlign_label = new QLabel("Keep Keypoints: ");
    keypointsAlign = new QComboBox();
    if(Settings::keypoints_align){
        keypointsAlign->addItem(QString("True"));
        keypointsAlign->addItem(QString("False"));
    }else{
        keypointsAlign->addItem(QString("False"));
        keypointsAlign->addItem(QString("True"));
    }
    QLabel *resetAlign_label = new QLabel("Reset Alignment: ");
    resetAlign = new QComboBox();
    if(Settings::reset_align){
        resetAlign->addItem(QString("True"));
        resetAlign->addItem(QString("False"));
    }else{
        resetAlign->addItem(QString("False"));
        resetAlign->addItem(QString("True"));
    }
    QLabel *genPreAlign_label = new QLabel("Generic Preselection: ");
    genPreAlign = new QComboBox();
    if(Settings::genPre_align){
        genPreAlign->addItem(QString("True"));
        genPreAlign->addItem(QString("False"));
    }else{
        genPreAlign->addItem(QString("False"));
        genPreAlign->addItem(QString("True"));
    }
    QLabel *refPreAlign_label = new QLabel("Reference Preselection: ");
    refPreAlign = new QComboBox();
    if(Settings::refPre_align){
        refPreAlign->addItem(QString("True"));
        refPreAlign->addItem(QString("False"));
    }else{
        refPreAlign->addItem(QString("False"));
        refPreAlign->addItem(QString("True"));
    }
    QLabel *preModeAlign_label = new QLabel("Reference Preselection Mode: ");
    preModeAlign = new QLineEdit("Metashape.ReferencePreselectionSource");
    preModeAlign->setObjectName("preModeAlign");



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

void MenuActions::create_optimizeCamera(){
    optimizeCamera_box = new QGroupBox(tr("Optimize Camera Settings"));

    QLabel *enableOpt_label = new QLabel("Enable: ");
    enableOpt = new QComboBox();
    if(Settings::enable_opt){
        enableOpt->addItem(QString("True"));
        enableOpt->addItem(QString("False"));
    }else{
        enableOpt->addItem(QString("False"));
        enableOpt->addItem(QString("True"));
    }
    QLabel *adaptiveOpt_label = new QLabel("Adaptive Fitting: ");
    adaptiveOpt = new QComboBox();
    if(Settings::adaptive_opt){
        adaptiveOpt->addItem(QString("True"));
        adaptiveOpt->addItem(QString("False"));
    }else{
        adaptiveOpt->addItem(QString("False"));
        adaptiveOpt->addItem(QString("True"));
    }
    QGridLayout* layoutOpt = new QGridLayout();
    layoutOpt->addWidget(enableOpt_label, 0,0);
    layoutOpt->addWidget(enableOpt, 0,1);

    layoutOpt->addWidget(adaptiveOpt_label, 1,0);
    layoutOpt->addWidget(adaptiveOpt, 1,1);

    optimizeCamera_box->setLayout(layoutOpt);
}

void MenuActions::create_filterPointsUSGS(){
    filterUSGS_box = new QGroupBox(tr("Filter Points USGS"));

    QLabel *enableUSGS_label = new QLabel("Enable: ");
    enableUSGS = new QComboBox();
    if(Settings::enable_USGS){
        enableUSGS->addItem(QString("True"));
        enableUSGS->addItem(QString("False"));
    }else{
        enableUSGS->addItem(QString("False"));
        enableUSGS->addItem(QString("True"));
    }
    QLabel *recPercUSGS_label = new QLabel("Rec Thresh Percentage: ");
    recPercUSGS = new QDoubleSpinBox();
    recPercUSGS->setValue(Settings::recPerc_USGS);

    QLabel *recAbsUSGS_label = new QLabel("Rec Thresh Absolute: ");
    recAbsUSGS = new QDoubleSpinBox();
    recAbsUSGS->setValue(Settings::recAbs_USGS);

    QLabel *projPercUSGS_label = new QLabel("Proj Thresh Percentage: ");
    projPercUSGS = new QDoubleSpinBox();
    projPercUSGS->setValue(Settings::projPerc_USGS);

    QLabel *projAbsUSGS_label = new QLabel("Proj Thresh Absolute: ");
    projAbsUSGS = new QDoubleSpinBox();
    projAbsUSGS->setValue(Settings::projAbs_USGS);

    QLabel *reprojPercUSGS_label = new QLabel("Reproj Thresh Percentage: ");
    reprojPercUSGS = new QDoubleSpinBox();
    reprojPercUSGS->setValue(Settings::reprojPerc_USGS);

    QLabel *reprojAbsUSGS_label = new QLabel("Reproj Thresh Absolute: ");
    reprojAbsUSGS = new QDoubleSpinBox();
    reprojAbsUSGS->setValue(Settings::reprojAbs_USGS);

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


void MenuActions::create_pointCloud(){

    pointCloud_box = new QGroupBox(tr("Build Point Cloud Settings"));

    QLabel* enableCloud_label = new QLabel("Enable: ");
    enableCloud = new QComboBox();
    if(Settings::enable_cloud){
        enableCloud->addItem(QString("True"));
        enableCloud->addItem(QString("False"));
    }else{
        enableCloud->addItem(QString("False"));
        enableCloud->addItem(QString("True"));
    }
    QLabel *downscaleCloud_label = new QLabel("Downscale: ");
    downscaleCloud = new QDoubleSpinBox();
    downscaleCloud->setValue(Settings::downscale_cloud);

    QLabel* filterCloud_label = new QLabel("Filter Mode: ");
    filterCloud = new QLineEdit(Settings::filter_cloud);
    filterCloud->setObjectName("filterCloud");


    QLabel* reuseCloud_label = new QLabel("Reuse depth: ");
    reuseCloud = new QComboBox();
    if(Settings::reuse_cloud){
        reuseCloud->addItem(QString("True"));
        reuseCloud->addItem(QString("False"));
    }else{
        reuseCloud->addItem(QString("False"));
        reuseCloud->addItem(QString("True"));
    }

    QLabel* keepCloud_label = new QLabel("Keep depth: ");
    keepCloud = new QComboBox();
    if(Settings::keep_cloud){
        keepCloud->addItem(QString("True"));
        keepCloud->addItem(QString("False"));
    }else{
        keepCloud->addItem(QString("False"));
        keepCloud->addItem(QString("True"));
    }

    QLabel* maxneighborsCloud_label = new QLabel("Max Neighbors: ");
    maxneighborsCloud = new QDoubleSpinBox();
    maxneighborsCloud->setValue(Settings::maxneighbors_cloud);

    QLabel* classifyCloud_label = new QLabel("Classify Ground Points: ");
    classifyCloud = new QComboBox();
    if(Settings::classify_cloud){
        classifyCloud->addItem(QString("True"));
        classifyCloud->addItem(QString("False"));
    }else{
        classifyCloud->addItem(QString("False"));
        classifyCloud->addItem(QString("True"));
    }

    QLabel* exportCloud_label = new QLabel("Export: ");
    exportCloud = new QComboBox();
    if(Settings::export_cloud){
        exportCloud->addItem(QString("True"));
        exportCloud->addItem(QString("False"));
    }else{
        exportCloud->addItem(QString("False"));
        exportCloud->addItem(QString("True"));
    }

    QLabel* classesCloud_label = new QLabel("Classes: ");
    classesCloud = new QLineEdit(Settings::classes_cloud);
    classesCloud->setObjectName("classesCloud");


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
    angleClassify->setValue(Settings::angle_classify);

    QLabel* distanceClassify_label = new QLabel("Max Distances: ");
    distanceClassify = new QDoubleSpinBox();
    distanceClassify->setValue(Settings::distance_classify);

    QLabel* cellClassify_label = new QLabel("Cell Size: ");
    cellClassify = new QDoubleSpinBox();
    cellClassify->setValue(Settings::cell_classify);

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
    if(Settings::enable_DEM){
        enableDEM->addItem(QString("True"));
        enableDEM->addItem(QString("False"));
    }else{
        enableDEM->addItem(QString("False"));
        enableDEM->addItem(QString("True"));
    }
    QLabel* classifyDEM_label = new QLabel("Classify Ground Points: ");
    classifyDEM = new QComboBox();
    if(Settings::classify_DEM){
        classifyDEM->addItem(QString("True"));
        classifyDEM->addItem(QString("False"));
    }else{
        classifyDEM->addItem(QString("False"));
        classifyDEM->addItem(QString("True"));
    }
    QLabel* typeDEM_label = new QLabel("Type: ");
    typeDEM = new QLineEdit(Settings::type_DEM);
    typeDEM->setObjectName("typeDEM");


    QLabel* exportDEM_label = new QLabel("Export: ");
    exportDEM = new QComboBox();
    if(Settings::export_DEM){
        exportDEM->addItem(QString("True"));
        exportDEM->addItem(QString("False"));
    }else{
        exportDEM->addItem(QString("False"));
        exportDEM->addItem(QString("True"));
    }

    QLabel* bigDEM_label = new QLabel("Tiff Big: ");
    bigDEM = new QComboBox();
    if(Settings::big_DEM){
        bigDEM->addItem(QString("True"));
        bigDEM->addItem(QString("False"));
    }else{
        bigDEM->addItem(QString("False"));
        bigDEM->addItem(QString("True"));
    }

    QLabel* tiledDEM_label = new QLabel("Tiff Tiled: ");
    tiledDEM = new QComboBox();
    if(Settings::tiled_DEM){
        tiledDEM->addItem(QString("True"));
        tiledDEM->addItem(QString("False"));
    }else{
        tiledDEM->addItem(QString("False"));
        tiledDEM->addItem(QString("True"));
    }

    QLabel* nodataDEM_label = new QLabel("Nodata: ");
    nodataDEM = new QDoubleSpinBox();
    nodataDEM->setMinimum(-1000000);
    nodataDEM->setValue(Settings::nodata_DEM);

    QLabel* overviewsDEM_label = new QLabel("Tiff Tiled: ");
    overviewsDEM = new QComboBox();
    if(Settings::overviews_DEM){
        overviewsDEM->addItem(QString("True"));
        overviewsDEM->addItem(QString("False"));
    }else{
        overviewsDEM->addItem(QString("False"));
        overviewsDEM->addItem(QString("True"));
    }

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
    if(Settings::enable_ortho){
        enableOrtho->addItem(QString("True"));
        enableOrtho->addItem(QString("False"));
    }else{
        enableOrtho->addItem(QString("False"));
        enableOrtho->addItem(QString("True"));
    }

    QLabel* surfaceOrtho_label = new QLabel("Surface: ");
    surfaceOrtho = new QLineEdit(Settings::surface_ortho);
    surfaceOrtho->setObjectName("surfaceOrtho");


    QLabel* pathOrtho_label = new QLabel("Path: ");
    pathOrtho = new QLineEdit(Settings::path_ortho);
    pathOrtho->setObjectName("pathOrtho");


    QLabel* crsOrtho_label = new QLabel("CRS: ");
    crsOrtho = new QLineEdit(Settings::crs_ortho);
    crsOrtho->setObjectName("crsOrtho");


    QLabel* blendingOrtho_label = new QLabel("Blending: ");
    blendingOrtho = new QLineEdit(Settings::blending_ortho);
    blendingOrtho->setObjectName("blendingOrtho");

    QLabel* holesOrtho_label = new QLabel("Fill Holes: ");
    holesOrtho = new QComboBox();
    if(Settings::holes_ortho){
        holesOrtho->addItem(QString("True"));
        holesOrtho->addItem(QString("False"));
    }else{
        holesOrtho->addItem(QString("False"));
        holesOrtho->addItem(QString("True"));
    }

    QLabel* seamlinesOrtho_label = new QLabel("Refine Seamlines: ");
    seamlinesOrtho = new QComboBox();
    if(Settings::seamlines_ortho){
        seamlinesOrtho->addItem(QString("True"));
        seamlinesOrtho->addItem(QString("False"));
    }else{
        seamlinesOrtho->addItem(QString("False"));
        seamlinesOrtho->addItem(QString("True"));
    }

    QLabel* exportOrtho_label = new QLabel("Export: ");
    exportOrtho = new QComboBox();
    if(Settings::export_ortho){
        exportOrtho->addItem(QString("True"));
        exportOrtho->addItem(QString("False"));
    }else{
        exportOrtho->addItem(QString("False"));
        exportOrtho->addItem(QString("True"));
    }

    QLabel* bigOrtho_label = new QLabel("Tiff big: ");
    bigOrtho = new QComboBox();
    if(Settings::big_ortho){
        bigOrtho->addItem(QString("True"));
        bigOrtho->addItem(QString("False"));
    }else{
        bigOrtho->addItem(QString("False"));
        bigOrtho->addItem(QString("True"));
    }

    QLabel* tiledOrtho_label = new QLabel("Tiff tiled: ");
    tiledOrtho = new QComboBox();
    if(Settings::tiled_ortho){
        tiledOrtho->addItem(QString("True"));
        tiledOrtho->addItem(QString("False"));
    }else{
        tiledOrtho->addItem(QString("False"));
        tiledOrtho->addItem(QString("True"));
    }

    QLabel* nodataOrtho_label = new QLabel("Nodata: ");
    nodataOrtho = new QDoubleSpinBox();
    nodataOrtho->setMinimum(-10000000);
    nodataOrtho->setValue(Settings::nodata_ortho);

    QLabel* overviewsOrtho_label = new QLabel("Tiff Overviews: ");
    overviewsOrtho = new QComboBox();
    if(Settings::overviews_ortho){
        overviewsOrtho->addItem(QString("True"));
        overviewsOrtho->addItem(QString("False"));
    }else{
        overviewsOrtho->addItem(QString("False"));
        overviewsOrtho->addItem(QString("True"));
    }

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

void MenuActions::onNextButtonClicked(){
    Settings::photo_path = QUrl(photo_line->text());
    Settings::project_path = QUrl(project_line->text());
    Settings::output_path = QUrl(output_line->text());

}

void MenuActions::onFinishButtonClicked(){
// SET ALL SETTINGS PARAMETERS

    Settings::project_crs = crs_line->text();
    Settings::subdivide_task = (((task_box->currentText()) == QString("True")) ? true : false);

    Settings::enabled_align = (((enableAlign->currentText()) == QString("True")) ? true : false);
    Settings::downscale_align = downscaleAlign->value();
    Settings::adaptive_align = (((adaptiveAlign->currentText()) == QString("True")) ? true : false);
    Settings::keypoints_align = (((keypointsAlign->currentText()) == QString("True")) ? true : false);
    Settings::reset_align = (((resetAlign->currentText()) == QString("True")) ? true : false);
    Settings::genPre_align = (((genPreAlign->currentText()) == QString("True")) ? true : false);
    Settings::refPre_align = (((refPreAlign->currentText()) == QString("True")) ? true : false);
    Settings::preMode_align = preModeAlign->text();

    Settings::enable_USGS = (((enableUSGS->currentText()) == QString("True")) ? true : false);
    Settings::recPerc_USGS = recPercUSGS->value();
    Settings::recAbs_USGS = recAbsUSGS->value();
    Settings::projPerc_USGS = projPercUSGS->value();
    Settings::projAbs_USGS = projAbsUSGS->value();
    Settings::reprojPerc_USGS = reprojPercUSGS->value();
    Settings::reprojAbs_USGS = reprojAbsUSGS->value();

    Settings::enable_opt = (((enableOpt->currentText()) == QString("True")) ? true : false);
    Settings::adaptive_opt = (((adaptiveOpt->currentText()) == QString("True")) ? true : false);

    Settings::enable_cloud = (((enableCloud->currentText()) == QString("True")) ? true : false);
    Settings::downscale_cloud = downscaleCloud->value();
    Settings::filter_cloud = filterCloud->text();
    Settings::reuse_cloud = (((reuseCloud->currentText()) == QString("True")) ? true : false);
    Settings::keep_cloud = (((keepCloud->currentText()) == QString("True")) ? true : false);
    Settings::maxneighbors_cloud = maxneighborsCloud->value();
    Settings::classify_cloud = (((classifyCloud->currentText()) == QString("True")) ? true : false);
    Settings::export_cloud = (((exportCloud->currentText()) == QString("True")) ? true : false);
    Settings::classes_cloud = classesCloud->text();

    Settings::angle_classify = angleClassify->value();
    Settings::distance_classify = distanceClassify->value();
    Settings::cell_classify = cellClassify->value();

    Settings::enable_DEM = (((enableDEM->currentText()) == QString("True")) ? true : false);
    Settings::classify_DEM = (((classifyDEM->currentText()) == QString("True")) ? true : false);
    Settings::type_DEM = typeDEM->text();
    Settings::export_DEM = (((exportDEM->currentText()) == QString("True")) ? true : false);
    Settings::big_DEM = (((bigDEM->currentText()) == QString("True")) ? true : false);
    Settings::tiled_DEM = (((tiledDEM->currentText()) == QString("True")) ? true : false);
    Settings::nodata_DEM = nodataDEM->value();
    Settings::overviews_DEM = (((overviewsDEM->currentText()) == QString("True")) ? true : false);

    Settings::enable_ortho = (((enableUSGS->currentText()) == QString("True")) ? true : false);
    Settings::surface_ortho = surfaceOrtho->text();
    Settings::path_ortho = pathOrtho->text();
    Settings::crs_ortho = crsOrtho->text();
    Settings::blending_ortho = blendingOrtho->text();
    Settings::holes_ortho = (((holesOrtho->currentText()) == QString("True")) ? true : false);
    Settings::seamlines_ortho = (((seamlinesOrtho->currentText()) == QString("True")) ? true : false);
    Settings::export_ortho = (((exportOrtho->currentText()) == QString("True")) ? true : false);
    Settings::big_ortho = (((bigOrtho->currentText()) == QString("True")) ? true : false);
    Settings::tiled_ortho = (((tiledOrtho->currentText()) == QString("True")) ? true : false);
    Settings::nodata_ortho = nodataOrtho->value();
    Settings::overviews_ortho = (((overviewsOrtho->currentText()) == QString("True")) ? true : false);
}

void MenuActions::setSettings(){

    // PAGE 1
    SettingsWizardPage *page = new SettingsWizardPage;
    page->setTitle("Settings");

    label = new QLabel("Set all the infromation fields below.");
    label->setWordWrap(true);

    photo_label = new QLabel("Photo path: ");
    photo_label->setWordWrap(true);

    project_label = new QLabel("Project path: ");
    project_label->setWordWrap(true);

    output_label = new QLabel("Output path: ");
    output_label->setWordWrap(true);

    photo_line = new QLineEdit(Settings::photo_path.toString());
    photo_line->setObjectName("photo_line");

    project_line = new QLineEdit(Settings::project_path.toString());
    project_line->setObjectName("project_line");

    output_line = new QLineEdit(Settings::output_path.toString());
    output_line->setObjectName("output_line");

    button_photo = new QPushButton("&Open...", this);
    connect(button_photo, &QPushButton::released, this, &MenuActions::setPhotoUrl);

    button_project= new QPushButton("&Open...", this);
    connect(button_project, &QPushButton::released, this, &MenuActions::setProjectUrl);

    button_output = new QPushButton("&Open...", this);
    connect(button_output, &QPushButton::released, this, &MenuActions::setOutputUrl);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 1);
    layout->addWidget(photo_label, 1,0);
    layout->addWidget(photo_line, 1, 1);
    layout->addWidget(button_photo, 1, 2);

    layout->addWidget(project_label, 2,0);
    layout->addWidget(project_line, 2, 1);
    layout->addWidget(button_project, 2, 2);

    layout->addWidget(output_label, 3,0);
    layout->addWidget(output_line, 3, 1);
    layout->addWidget(button_output, 3, 2);

    page->setLayout(layout);


    // PAGE 2
    SettingsWizardPage *page2 = new SettingsWizardPage;
    scrollArea = new QScrollArea;

    page2->setTitle("Advanced Settings");

    label2 = new QLabel("Change these informations only if necessary: ");
    label2->setWordWrap(true);

    create_preliminary();
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
    layout2->addWidget(preliminary_box,2,1);
    layout2->addWidget(alignPhotos_box, 3,1);
    layout2->addWidget(filterUSGS_box, 4,1);
    layout2->addWidget(optimizeCamera_box, 5,1);
    layout2->addWidget(pointCloud_box,6,1);
    layout2->addWidget(classifyGround_box, 7,1);
    layout2->addWidget(dem_box,8,1);
    layout2->addWidget(ortho_box,9,1);


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
    connect(page,
            SIGNAL(sanitySettingsCheckPassedSignal()),this,SLOT(onNextButtonClicked()));
    connect(page2,
            SIGNAL(sanitySettingsCheckPassedSignal()),this,SLOT(onFinishButtonClicked()));
    wizard_settings->setWindowTitle("Configure");
    wizard_settings->show();

}

void MenuActions::onCreateFinished()
{
    Settings::photo_path = QUrl(photo_line->text());
    Settings::project_path = QUrl(project_line->text());
    Settings::output_path = QUrl(output_line->text());

    std::vector<QString> elems = {Settings::project_path.toString(), Settings::guiSubDir};
    QString p = Settings::pathJoin(elems);

    QDir().mkpath(p);

    elems.push_back(Settings::yamlSaveName);
    p = Settings::pathJoin(elems);
    qDebug() << p;
    Settings::dumpToYaml(p);
    leftWindow->setEnabled(true);
}

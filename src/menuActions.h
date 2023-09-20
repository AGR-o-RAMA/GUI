#ifndef MENUACTIONS_H
#define MENUACTIONS_H

#include <QTabWidget>
#include <QFileDialog>
#include <QWindow>
#include <QUrl>
#include <QLabel>
#include <QLineEdit>
#include <QWizard>
#include <QGroupBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QScrollArea>
#include "settings.h"

class MenuActions : public QTabWidget
{
    Q_OBJECT
private:

    // PROPERTIES

//    QUrl photo_path;
//    QUrl project_path;
//    QUrl output_path;
//    QString api_key;

//    // ADVANCED PROPERTIES

//    QString project_crs;
//    bool subdivide_task;

//    bool enabled_align;
//    int downscale_align;
//    bool adaptive_align;
//    bool keypoints_align;
//    bool reset_align;
//    bool genPre_align;
//    bool refPre_align;
//    QString preMode_align;

//    bool enable_USGS;
//    double recPerc_USGS;
//    double recAbs_USGS;
//    double projPerc_USGS;
//    double projAbs_USGS;
//    double reprojPerc_USGS;
//    double reprojAbs_USGS;

//    bool enable_opt;
//    bool adaptive_opt;

//    bool enable_cloud;
//    double downscale_cloud;
//    QString filter_cloud;
//    bool reuse_cloud;
//    bool keep_cloud;
//    int maxneighbors_cloud;
//    bool classify_cloud;
//    bool export_cloud;
//    QString classes_cloud;

//    double angle_classify;
//    double distance_classify;
//    double cell_classify;

//    bool enable_DEM;
//    bool classify_DEM;
//    QString type_DEM;
//    bool export_DEM;
//    bool big_DEM;
//    bool tiled_DEM;
//    int nodata_DEM;
//    bool overviews_DEM;

//    bool enable_ortho;
//    QString surface_ortho;
//    QString path_ortho;
//    QString crs_ortho;
//    QString blending_ortho;
//    bool holes_ortho;
//    bool seamlines_ortho;
//    bool export_ortho;
//    bool big_ortho;
//    bool tiled_ortho;
//    int nodata_ortho;
//    bool overviews_ortho;





    // PAGE 1
    QLabel *label;
    QLabel *photo_label;
    QLabel *project_label;
    QLabel *output_label;
    QLabel *api_label;

    QLineEdit *photo_line;
    QLineEdit *project_line;
    QLineEdit *output_line;
    QLineEdit *api_line;

    QPushButton *button_photo;
    QPushButton *button_project;
    QPushButton *button_output;

    // PAGE 2
    QLabel *label2;

    QGroupBox *preliminary_box;

    QLineEdit *crs_line;

    QComboBox *task_box;
///////////////////////

    QGroupBox *alignPhotos_box;
    QComboBox *enableAlign;
    QDoubleSpinBox *downscaleAlign;
    QComboBox *adaptiveAlign;
    QComboBox *keypointsAlign;
    QComboBox *resetAlign;
    QComboBox *genPreAlign;
    QComboBox *refPreAlign;
    QLineEdit *preModeAlign;

///////////////////////

    QGroupBox *filterUSGS_box;
    QComboBox *enableUSGS;
    QDoubleSpinBox *recPercUSGS;
    QDoubleSpinBox *recAbsUSGS;
    QDoubleSpinBox *projPercUSGS;
    QDoubleSpinBox *projAbsUSGS;
    QDoubleSpinBox *reprojPercUSGS;
    QDoubleSpinBox *reprojAbsUSGS;

//////////////////////

    QGroupBox *optimizeCamera_box;
    QComboBox *enableOpt;
    QComboBox *adaptiveOpt;

//////////////////////

    QGroupBox* pointCloud_box;
    QComboBox* enableCloud;
    QDoubleSpinBox* downscaleCloud;
    QLineEdit* filterCloud;
    QComboBox* reuseCloud;
    QComboBox* keepCloud;
    QDoubleSpinBox* maxneighborsCloud;
    QComboBox* classifyCloud;
    QComboBox* exportCloud;
    QLineEdit* classesCloud;

////////////////////////////////

    QGroupBox* classifyGround_box;
    QDoubleSpinBox* angleClassify;
    QDoubleSpinBox* distanceClassify;
    QDoubleSpinBox* cellClassify;

///////////////////////////////

    QGroupBox* dem_box;
    QComboBox* enableDEM;
    QComboBox* classifyDEM;
    QLineEdit* typeDEM;
    QComboBox* exportDEM;
    QComboBox* bigDEM;
    QComboBox* tiledDEM;
    QDoubleSpinBox* nodataDEM;
    QComboBox* overviewsDEM;

///////////////////////////////

    QGroupBox* ortho_box;
    QComboBox* enableOrtho;
    QLineEdit* surfaceOrtho;
    QLineEdit* pathOrtho;
    QLineEdit* crsOrtho;
    QLineEdit* blendingOrtho;
    QComboBox* holesOrtho;
    QComboBox* seamlinesOrtho;
    QComboBox* exportOrtho;
    QComboBox* bigOrtho;
    QComboBox* tiledOrtho;
    QDoubleSpinBox* nodataOrtho;
    QComboBox* overviewsOrtho;

///////////////////////////////

    QScrollArea* scrollArea;
    QWizard* wizard_settings;


    void handlePhotoButton();
    void handleProjectButton();
    void handleOutputButton();
    void setPhotoUrl();
    void setProjectUrl();
    void setOutputUrl();

    void create_preliminary();
    void create_alignPhotos();
    void create_filterPointsUSGS();
    void create_optimizeCamera();
    void create_pointCloud();
    void create_classifyGround();
    void create_DEM();
    void create_orthomosaic();

public:
    MenuActions(QWidget *parent = nullptr);

public slots:
    void openProject();
    void saveProject();

    void onNextButtonCliked();
    void onFinishButtonCliked();    
    void setSettings();
};

#endif // MENUACTIONS_H

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

#define GUI_SUB_PATH "gui"


class MenuActions : public QTabWidget
{
    Q_OBJECT
private:
    QUrl guiSubDir;

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
    void newProject();
    void openProject();
    void saveProject();

    void onFinishButtonCliked();    
    void setSettings();
    void onCreateFinished();
};

class NewWizardPage : public QWizardPage {
    Q_OBJECT

signals:
    void sanityCheckPassedSignal();

public:
    NewWizardPage(QWidget* parent = nullptr) : QWizardPage(parent){}

    bool validatePage() override {
        QLineEdit* photoLineEdit = findChild<QLineEdit*>("photo_line");
        QLineEdit* projectLineEdit = findChild<QLineEdit*>("project_line");
        QLineEdit* outputLineEdit = findChild<QLineEdit*>("output_line");
        QLineEdit* apiLineEdit = findChild<QLineEdit*>("api_line");

        photoLineEdit->setStyleSheet("");
        projectLineEdit->setStyleSheet("");
        outputLineEdit->setStyleSheet("");
        apiLineEdit->setStyleSheet("");

        QString photo = (photoLineEdit) ? photoLineEdit->text() : "";
        QString project = (projectLineEdit) ? projectLineEdit->text() : "";
        QString output = (outputLineEdit) ? outputLineEdit->text() : "";
        QString api = (apiLineEdit) ? apiLineEdit->text() : "";

        bool res = true;

        if (photo.isEmpty() || !QDir(photo).exists()){
            photoLineEdit->setStyleSheet("border: 2px solid red;");
            res = false;
        }

        if (project.isEmpty() || !QDir(project).exists()){
            projectLineEdit->setStyleSheet("border: 2px solid red;");
            res = false;
        }

        if (output.isEmpty() || !QDir(output).exists()){
            outputLineEdit->setStyleSheet("border: 2px solid red;");
            res = false;
        }

        if (api.isEmpty()){
            apiLineEdit->setStyleSheet("border: 2px solid red;");
            res = false;
        }

        if(res)
            emit sanityCheckPassedSignal();

        return res;
    }
};

#endif // MENUACTIONS_H

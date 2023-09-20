#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QFileDialog>
#include <QWindow>
#include <QUrl>
#include <QGroupBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QScrollArea>

class Settings : public QWidget
{
    Q_OBJECT
public:

    Settings(QWidget *parent = nullptr);

    // PROPERTIES

    static QUrl photo_path;
    static QUrl project_path;
    static QUrl output_path;
    static QString api_key;

    // ADVANCED PROPERTIES

    static QString project_crs;
    static bool subdivide_task;

    static bool enabled_align;
    static int downscale_align;
    static bool adaptive_align;
    static bool keypoints_align;
    static bool reset_align;
    static bool genPre_align;
    static bool refPre_align;
    static QString preMode_align;

    static bool enable_USGS;
    static double recPerc_USGS;
    static double recAbs_USGS;
    static double projPerc_USGS;
    static double projAbs_USGS;
    static double reprojPerc_USGS;
    static double reprojAbs_USGS;

    static bool enable_opt;
    static bool adaptive_opt;

    static bool enable_cloud;
    static double downscale_cloud;
    static QString filter_cloud;
    static bool reuse_cloud;
    static bool keep_cloud;
    static int maxneighbors_cloud;
    static bool classify_cloud;
    static bool export_cloud;
    static QString classes_cloud;

    static double angle_classify;
    static double distance_classify;
    static double cell_classify;

    static bool enable_DEM;
    static bool classify_DEM;
    static QString type_DEM;
    static bool export_DEM;
    static bool big_DEM;
    static bool tiled_DEM;
    static int nodata_DEM;
    static bool overviews_DEM;

    static bool enable_ortho;
    static QString surface_ortho;
    static QString path_ortho;
    static QString crs_ortho;
    static QString blending_ortho;
    static bool holes_ortho;
    static bool seamlines_ortho;
    static bool export_ortho;
    static bool big_ortho;
    static bool tiled_ortho;
    static int nodata_ortho;
    static bool overviews_ortho;
};

#endif // SETTINGS_H

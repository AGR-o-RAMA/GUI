#include "settings.h"

#include <QDebug>
#include <QQmlProperty>
#include <QtWidgets>
#include <QPixmap>
#include <QPalette>


Settings::Settings(QWidget *parent) : QWidget(parent){
    photo_path = QUrl("");
    project_path = QUrl("");
    output_path = QUrl("");
    api_key = QString("");

    // ADVANCED PROPERTIES

    project_crs = QString("EPSG::4326");
    subdivide_task = true;

    enabled_align = true;
    downscale_align = 2;
    adaptive_align = true;
    keypoints_align = true;
    reset_align = false;
    genPre_align = true;
    refPre_align = true;
    preMode_align = QString("Metashape.ReferencePreselectionSource");

    enable_USGS = false;
    recPerc_USGS = 20;
    recAbs_USGS = 15;
    projPerc_USGS = 30;
    projAbs_USGS = 2;
    reprojPerc_USGS = 5;
    reprojAbs_USGS = 0.3;

    enable_opt = true;
    adaptive_opt = true;

    enable_cloud = true;
    downscale_cloud = 2;
    filter_cloud = QString("Metashape.ModerateFiltering");
    reuse_cloud = false;
    keep_cloud = false;
    maxneighbors_cloud = 100;
    classify_cloud = true;
    export_cloud = true;
    classes_cloud = QString("ALL");

    angle_classify = 15.0;
    distance_classify = 1.0;
    cell_classify = 50.0;

    enable_DEM = true;
    classify_DEM = false;
    type_DEM = QString("both");
    export_DEM = true;
    big_DEM = true;
    tiled_DEM = false;
    nodata_DEM = -32767;
    overviews_DEM = true;

    enable_ortho = true;
    surface_ortho = QString("DTMandDSM");
    path_ortho = QString("dem_usgs/dem_usgs.tif");
    crs_ortho = QString("EPSG::4326");
    blending_ortho = QString("Metashape.MosaicBlending");
    holes_ortho = true;
    seamlines_ortho = true;
    export_ortho = true;
    big_ortho = true;
    tiled_ortho = false;
    nodata_ortho = -32767;
    overviews_ortho = true;
}


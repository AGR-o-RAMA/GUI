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

    run_name = QString("run-001");
    project_crs = QString("EPSG::4326");
    subdivide_task = true;
    use_cuda = true;

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

    guiSubDir = QString(GUI_SUB_PATH);
    csvName = QString(CSV_NAME);
    yamlParamsName = QString(YAML_PARAMS_NAME);
    yamlSaveName = QString(YAML_SAVE_NAME);
}

bool Settings::getUse_cuda()
{
    return use_cuda;
}

QString Settings::getYamlSaveName()
{
    return yamlSaveName;
}

QString Settings::getGuiSubDir()
{
    return guiSubDir;
}

QString Settings::getYamlParamsName()
{
    return yamlParamsName;
}

QString Settings::getProject_path()
{
    return project_path.toString();
}

void Settings::setUse_cuda(bool newUse_cuda)
{
    use_cuda = newUse_cuda;
}

void Settings::dumpToYaml(QString path)
{
    YAML::Node yamlNode;

    yamlNode["load_project"] = "";
    yamlNode["photo_path"] = photo_path.toString().toStdString();
    yamlNode["output_path"] = output_path.toString().toStdString();
    yamlNode["project_path"] = project_path.toString().toStdString();
    yamlNode["run_name"] = run_name.toStdString();
    yamlNode["project_crs"] = project_crs.toStdString();
    yamlNode["subdivide_task"] = subdivide_task;
    yamlNode["use_cuda"] = use_cuda;

    YAML::Node alignPhotosNode;
    alignPhotosNode["enabled"] = enabled_align;
    alignPhotosNode["downscale"] = downscale_align;
    alignPhotosNode["adaptive_fitting"] = adaptive_align;
    alignPhotosNode["keep_keypoints"] = keypoints_align;
    alignPhotosNode["reset_alignment"] = reset_align;
    alignPhotosNode["generic_preselection"] = genPre_align;
    alignPhotosNode["reference_preselection"] = refPre_align;
    alignPhotosNode["reference_preselection_mode"] = preMode_align.toStdString();

    yamlNode["alignPhotos"] = alignPhotosNode;

    YAML::Node filterPointsNode;
    filterPointsNode["enabled"] = enable_USGS;
    filterPointsNode["rec_thresh_percent"] = recPerc_USGS;
    filterPointsNode["rec_thresh_absolute"] = recAbs_USGS;
    filterPointsNode["proj_thresh_percent"] = projPerc_USGS;
    filterPointsNode["proj_thresh_absolute"] = projAbs_USGS;
    filterPointsNode["reproj_thresh_percent"] = reprojPerc_USGS;
    filterPointsNode["reproj_thresh_absolute"] = reprojAbs_USGS;

    yamlNode["filterPointsUSGS"] = filterPointsNode;

    YAML::Node optimizeCamerasNode;
    optimizeCamerasNode["enabled"] = enable_opt;
    optimizeCamerasNode["adaptive_fitting"] = adaptive_opt;

    yamlNode["optimizeCameras"] = optimizeCamerasNode;

    YAML::Node pointCloudNode;
    pointCloudNode["enabled"] = enable_cloud;
    pointCloudNode["downscale"] = downscale_cloud;
    pointCloudNode["filter_mode"] = filter_cloud.toStdString();
    pointCloudNode["reuse_depth"] = reuse_cloud;
    pointCloudNode["keep_depth"] = keep_cloud;
    pointCloudNode["max_neighbors"] = maxneighbors_cloud;
    pointCloudNode["classify_ground_points"] = classify_cloud;
    pointCloudNode["export"] = export_cloud;
    pointCloudNode["classes"] = classes_cloud.toStdString();

    yamlNode["buildPointCloud"] = pointCloudNode;

    YAML::Node groundPointsNode;
    groundPointsNode["max_angle"] = angle_classify;
    groundPointsNode["max_distance"] = distance_classify;
    groundPointsNode["cell_size"] = cell_classify;

    yamlNode["classifyGroundPoints"] = groundPointsNode;

    YAML::Node buildDemNode;
    buildDemNode["enabled"] = enable_DEM;
    buildDemNode["classify_ground_points"] = classify_DEM;
    buildDemNode["type"] = type_DEM.toStdString();
    buildDemNode["export"] = export_DEM;
    buildDemNode["tiff_big"] = big_DEM;
    buildDemNode["tiff_tiled"] = tiled_DEM;
    buildDemNode["nodata"] = nodata_DEM;
    buildDemNode["tiff_overviews"] = overviews_DEM;

    yamlNode["buildDem"] = buildDemNode;

    YAML::Node orthomosaicNode;
    orthomosaicNode["enabled"] = enable_ortho;
    orthomosaicNode["surface"] = surface_ortho.toStdString();
    orthomosaicNode["usgs_dem_path"] = path_ortho.toStdString();
    orthomosaicNode["usgs_dem_crs"] = crs_ortho.toStdString();
    orthomosaicNode["blending"] = blending_ortho.toStdString();
    orthomosaicNode["fill_holes"] = holes_ortho;
    orthomosaicNode["refine_seamlines"] = seamlines_ortho;
    orthomosaicNode["export"] = export_ortho;
    orthomosaicNode["tiff_big"] = big_ortho;
    orthomosaicNode["tiff_tiled"] = tiled_ortho;
    orthomosaicNode["nodata"] = nodata_ortho;
    orthomosaicNode["tiff_overviews"] = overviews_ortho;

    yamlNode["buildOrthomosaic"] = orthomosaicNode;

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QTextStream out(&file);
    out << QString::fromStdString(YAML::Dump(yamlNode));
    file.close();
}

QString Settings::pathJoin(std::vector<QString> paths)
{
    ssize_t n = paths.size();

    auto slash = [](QString param){ return param.endsWith("/") ? param : param + "/"; };

    QString res("");

    for(int i = 0; i < n; ++i){
        if(i < n-1)
            res += slash(paths[i]);
        else
            res += paths[i];
    }

    return res;
}


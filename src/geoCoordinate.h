#ifndef GEOCOORDINATE_H
#define GEOCOORDINATE_H

#include "qvariant.h"
#include <cmath>
#include <QPoint>
#include <QMetaType>

#include <iostream>

class GeoCoordinate{
private:
    const double r = 6371.0;
    const double p = M_PI / 180.0;
    QPointF point;
public:
    GeoCoordinate(QPointF point): point(point){};
    GeoCoordinate(QVariant var) : GeoCoordinate(var.value<QPointF>()){}

    float latitude() const {return this->point.y();};
    float longitude() const {return this->point.x();};
    // Based on https://stackoverflow.com/questions/27928/calculate-distance-between-two-latitude-longitude-points-haversine-formula
    float distanceTo(GeoCoordinate gc2){
        auto deg2rad = [this](double deg) -> double {
            return deg * this->p;
        };

        double dLat = deg2rad(gc2.latitude()-this->latitude());
        double dLon = deg2rad(gc2.longitude()-this->longitude());

        double a =
            sin(dLat/2) * sin(dLat/2) +
                cos(deg2rad(this->latitude())) * cos(deg2rad(gc2.latitude())) *
                sin(dLon/2) * sin(dLon/2);

        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        double d = this->r * c; // Distance in km
        return d*1000;
    };

    QString toString() const {
        return QString("< %1   %2 >").arg(latitude()).arg(longitude());
    }
};

Q_DECLARE_METATYPE(GeoCoordinate)

#endif // GEOCOORDINATE_H

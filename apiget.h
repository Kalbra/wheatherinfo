#ifndef APIGET_H
#define APIGET_H

#include <QMainWindow>

extern void WriteFromApiToValues(QJsonDocument);
extern QJsonDocument GetRestApi(QString);
extern double temp;
extern double temp;
extern double temp_max;
extern double temp_min;
extern double lat;
extern double lon;
extern int    pressure;
extern int    humidity;
extern int    speed;
extern int    deg;
extern int    cod;

class apiget
{
public:
    apiget();




};

#endif // APIGET_H

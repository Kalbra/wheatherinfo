#include "apiget.h"
#include <QJsonDocument>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtCore>

double temp;
double temp_max;
double temp_min;
double lat;
double lon;
int pressure;
int humidity;
int speed;
int deg;
int cod;


apiget::apiget()
{


    QJsonDocument GetRestApi(QString);
    void WriteFromApiToValues(QJsonDocument);



}
QJsonDocument GetRestApi(QString domain){

    QString url = "http://api.openweathermap.org/data/2.5/weather?q="+domain+"&units=metric&appid=3d05933c33e4793b2bae7d389ec892d1";

    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    QObject::connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    QString html = response->readAll();
    QJsonDocument restapijsondocument = QJsonDocument::fromJson(html.toUtf8());
    return restapijsondocument;
}

void WriteFromApiToValues(QJsonDocument sourcejson){
    QJsonObject restapijsonobject = sourcejson.object();


    QJsonValue restapijsonmainvalue = restapijsonobject.value(QString("main"));
    QJsonValue restapijsonwindvalue = restapijsonobject.value(QString("wind"));
    QJsonValue restapijsoncodvalue  = restapijsonobject.value(QString("cod"));
    QJsonValue restapijsoncoorvalue = restapijsonobject.value(QString("coord"));


    QJsonObject restapijsonwinditem = restapijsonwindvalue.toObject();
    QJsonObject restapijsonmainitem = restapijsonmainvalue.toObject();
    QJsonObject restapijsoncooritem = restapijsoncoorvalue.toObject();


    QJsonValue restapijsonhumidityvalue  = restapijsonmainitem.value(QString("humidity"));
    QJsonValue restapijsonpressurevalue  = restapijsonmainitem.value(QString("pressure"));
    QJsonValue restapijsontempvalue      = restapijsonmainitem.value(QString("temp"));
    QJsonValue restapijsontemp_maxvalue  = restapijsonmainitem.value(QString("temp_max"));
    QJsonValue restapijsontemp_minvalue  = restapijsonmainitem.value(QString("temp_min"));

    QJsonValue restapijsonwindspeedvalue = restapijsonwinditem.value(QString("speed"));
    QJsonValue restapijsonwinddegvalue   = restapijsonwinditem.value(QString("deg"));

    QJsonValue restapijsonlatvalue       = restapijsoncooritem.value(QString("lat"));
    QJsonValue restapijsonlonvalue       = restapijsoncooritem.value(QString("lon"));



    humidity = restapijsonhumidityvalue.toInt();
    pressure = restapijsonpressurevalue.toInt();
    temp     = restapijsontempvalue.toDouble();
    temp_max = restapijsontemp_maxvalue.toDouble();
    temp_min = restapijsontemp_minvalue.toDouble();
    deg      = restapijsonwindspeedvalue.toInt();
    speed    = restapijsonwinddegvalue.toInt();
    cod      = restapijsoncodvalue.toInt();
    lat      = restapijsonlatvalue.toDouble();
    lon      = restapijsonlonvalue.toDouble();

}

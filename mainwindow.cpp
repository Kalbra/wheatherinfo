#include "apiget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLineEdit>
#include <QMessageBox>
#include <string>
#include <QProcess>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->errormsg->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_go_clicked()
{
    QString domain = ui->domaininput->text();
    WriteFromApiToValues(GetRestApi(domain));

    if(cod == 200){

        ui->errormsg->hide();
        ui->templabel->setText("Temp: "+QString::number(temp)+"°");
        ui->pressurelabel->setText("Pressure: "+QString::number(pressure)+" hPa");
        ui->humiditylabel->setText("Humidity: "+QString::number(humidity)+"%");
        ui->windspeedlabel->setText("Wind speed: "+QString::number(speed)+" m/s");
        ui->coordlabel->setText("lat: "+QString::number(lat)+"; lon: "+ QString::number(lon));

    }
    if(cod == 0){
        ui->errormsg->show();
        ui->templabel->setText("Temp: None");
        ui->pressurelabel->setText("Pressure: None");
        ui->humiditylabel->setText("Humidity: None");
        ui->windspeedlabel->setText("Wind speed: None");
        ui->coordlabel->setText("lat: None; lon: None");
    }
}

void MainWindow::on_help_clicked()
{
    newform =new QDialog;
    newform->setModal(true);
    Form.setupUi(newform);
    newform->show();
    connect (Form.pushButton, SIGNAL(clicked()),newform,SLOT(close()));
}

void MainWindow::on_goonmaps_clicked()                                                           //fuer platform anpassen
{
    std::string lonstd = std::to_string(lon);
    std::string latstd = std::to_string(lat);
    std::string sysopen = "gnome-open https://www.google.de/maps/search/"+ latstd + "+" + lonstd;

    std::system(sysopen.c_str());

}

void MainWindow::on_settings_clicked()
{
    setting = new QDialog;
    setting->setModal(true);
    settings.setupUi(setting);
    setting->show();


}

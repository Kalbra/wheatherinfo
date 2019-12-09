#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_form.h"
#include "ui_settings.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_go_clicked();

    void on_help_clicked();

    void on_goonmaps_clicked();

    void on_settings_clicked();

private:
    Ui::MainWindow *ui;

    QDialog *setting;

    QDialog *newform;

    Ui::Form settings;

    Ui::Form Form;

};
#endif // MAINWINDOW_H

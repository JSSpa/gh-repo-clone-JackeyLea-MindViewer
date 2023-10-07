#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QThread>
#include <QDateTime>
#include <QDebug>

#include "simulator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void sltReceivePackage(const QByteArray &ba);

private slots:
    void on_actionOpen_triggered();

    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

    void on_actionGithub_triggered();

    void on_actionSimulator_triggered();

    void on_actionSerialport_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    Simulator *m_sim;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_sim(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if(m_sim){
        m_sim->deleteLater();
    }
    delete ui;
}

void MainWindow::sltReceivePackage(QByteArray ba)
{
    qDebug()<<QTime::currentTime()<<ba;
}


void MainWindow::on_actionOpen_triggered()
{

}


void MainWindow::on_actionAbout_triggered()
{
    QString msg = QString("<h1>MindViewer</h1>"
                          "<h2>TGAM module tools</h2>"
                          "<h3>Author: JackeyLea</h3>"
                          "<h3>E-mail: 1768478912@qq.com</h3>"
                          "<h3>GitHub: https://github.com/JackeyLea/MindViewer</h3>"
                          "<h3>Gitee: https://gitee.com/JackeyLea/MindViewer</h3>"
                          "<h4>Do what you want but please obey the LGPL3 rules</h4>"
                          "<h4>And keep those message within application</h4>");
    QMessageBox::information(this, tr("About"), msg, QMessageBox::Ok);

}


void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}


void MainWindow::on_actionGithub_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/JackeyLea/MindViewer"));
}


void MainWindow::on_actionSimulator_triggered()
{
    m_sim = new Simulator();
    connect(m_sim,&Simulator::sendPackage,this,&MainWindow::sltReceivePackage);
}


void MainWindow::on_actionSerialport_triggered()
{

}


void MainWindow::on_actionExit_triggered()
{
    qApp->exit(0);
}


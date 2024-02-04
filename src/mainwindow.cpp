#include "mainwindow.h"
#include "ui_mainwindow.h"

///////////////////////////以下内容来自官方参考代码//////////////////////////////////////
/* Parser types */
#define PARSER_TYPE_PACKETS    0x01    /* Stream bytes as ThinkGear Packets */
#define PARSER_TYPE_2BYTERAW   0x02    /* Stream bytes as 2-byte raw data */

/* Data CODE definitions */
#define PARSER_CODE_BATTERY            0x01
#define PARSER_CODE_POOR_QUALITY       0x02
#define PARSER_CODE_ATTENTION          0x04
#define PARSER_CODE_MEDITATION         0x05
#define PARSER_CODE_8BITRAW_SIGNAL     0x06
#define PARSER_CODE_RAW_MARKER         0x07

/* Decoder states (Packet decoding) */
#define PARSER_STATE_NULL           0x00  /* NULL state */
#define PARSER_STATE_SYNC           0x01  /* Waiting for SYNC byte */
#define PARSER_STATE_SYNC_CHECK     0x02  /* Waiting for second SYNC byte */
#define PARSER_STATE_PAYLOAD_LENGTH 0x03  /* Waiting for payload[] length */
#define PARSER_STATE_CHKSUM         0x04  /* Waiting for chksum byte */
#define PARSER_STATE_PAYLOAD        0x05  /* Waiting for next payload[] byte */

/* Decoder states (2-byte raw decoding) */
#define PARSER_STATE_WAIT_HIGH      0x06  /* Waiting for high byte */
#define PARSER_STATE_WAIT_LOW       0x07  /* High r'cvd.  Expecting low part */

/* Other constants */
#define PARSER_SYNC_BYTE            0xAA  /* Syncronization byte */
#define PARSER_EXCODE_BYTE          0x55  /* EXtended CODE level byte */

#define PARSER_CODE_RAW_SIGNAL         0x80
#define PARSER_CODE_EEG_POWERS         0x81
#define PARSER_CODE_ASIC_EEG_POWER_INT 0x83
/////////////////////////////////////////////////////////////////////////////////////////////////////


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

void MainWindow::parseData(QByteArray ba)
{
    if(ba.isEmpty()) return;
}

void MainWindow::sltReceivePackage(const QByteArray& ba)
{
    if(ba.size()==0) return;


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


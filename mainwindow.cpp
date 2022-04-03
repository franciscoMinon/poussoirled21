#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <wiringPi.h>

#define	LED	21


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // gestion evenements
    connect( ui->pbLed1, &QPushButton::released, this, &MainWindow::handlePbLed1);
    // IO
    wiringPiSetupSys();
    pinMode(LED, OUTPUT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handlePbLed1()
{
    if (bLed) {
        bLed = false;
        digitalWrite(LED, LOW);  // eteint
        PbLed1Bleu();
    }
    else {
        bLed = true;
        digitalWrite(LED, HIGH);  // allume
        PbLed1Rouge();
    }

}

void MainWindow::PbLed1Rouge() {
    //ui->pbLed1->setStyleSheet( "background-color: red;");
    ui->pbLed1->setAutoFillBackground( true);
    QPalette palette;
    palette.setColor(QPalette::Base, QColor(Qt::red));
    ui->pbLed1->setPalette( palette);
    ui->pbLed1->update();
    ui->pbLed1->repaint();
}

void MainWindow::PbLed1Bleu()
{
    ui->pbLed1->setStyleSheet( QString( "QPushButton:pressed{background-color: blue;}"));
    ui->pbLed1->update();ui->pbLed1->repaint();
}

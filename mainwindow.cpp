#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->listWidget->hide();
    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    agent ->start();


    b_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_scan_btn_clicked()
{
    ui->listWidget->show();
    ui->listWidget->clear();
    agent->stop();
    agent->start();
}


void MainWindow::on_on_btn_clicked()
{
//    s_val = "h";
    b_socket->write("h");
//    QDebug()<<s_val;
}


void MainWindow::on_off_btn_clicked()
{
//    s_val = "l";
    b_socket->write("l");
//    QDebug()<< s_val;
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    ui->listWidget->addItem(device.name());
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    text = item->text();
//    item->setText(text);
    ui->listWidget->addItem(text);
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    b_socket->connectToService(QBluetoothAddress (text), QBluetoothUuid (serviceUuid), QIODevice::ReadWrite);

}


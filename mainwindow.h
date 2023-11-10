#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QListWidgetItem>
#include <QBluetoothSocket>
#include <QIODevice>
//#include <QDebug>
//#include <QBluetoothServiceInfo>
#include <QBluetoothUuid>
//#include <qbluetoothdeviceinfo.h>

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
    void on_scan_btn_clicked();

    void on_on_btn_clicked();

    void on_off_btn_clicked();

    void deviceDiscovered(const QBluetoothDeviceInfo &device);

    void on_listWidget_itemClicked(QListWidgetItem *item);


private:
    Ui::MainWindow *ui;

    QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;

    QBluetoothSocket *b_socket;

    QString text;
//    QString s_val;
    static const QString serviceUuid;
};
#endif // MAINWINDOW_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QLabel>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE


#define MAX_X   90      //画图坐标轴限制
#define MAX_Y   180     //画图坐标轴限制

typedef struct  AngleData
{
    float Sensor_1;
}Angle;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void InitUartPort(void);
    void Chart_Init(void);
    Angle Data;
    QSplineSeries *lineSeries1;
    QTimer *timerDrawLine;
    QChart *chart;

private slots:

    void ReadData();

    void TimerToSend();

    void StringToHex(QString str, QByteArray &SendData);

    char CharToHex(char ch);

    void StringToNumber(char string[]);

    void on_OpenUartPushButton_clicked();

    void on_ClearReceivePushButton_clicked();

    void on_ClearSendPushButton_clicked();

    void on_SendPushButton_clicked();

private:
    Ui::Widget *ui;
    int count = 0;
    QSerialPort *serialPort;
    QTimer *timer;
};
#endif // WIDGET_H

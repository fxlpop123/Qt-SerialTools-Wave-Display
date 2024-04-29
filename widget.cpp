#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer();

    Data.Sensor_1 = (float)MAX_Y/2;

    InitUartPort();
    Chart_Init();

    //设置串口默认值
    ui->UartPortComboBox->setCurrentIndex(0);
    ui->BaudComboBox->setCurrentIndex(1);
    ui->StopBitComboBox->setCurrentIndex(0);
    ui->DataBitComboBox->setCurrentIndex(0);
    ui->ParityBitComboBox->setCurrentIndex(0);

    ui->SendPushButton->setEnabled(false);
    ui->SendHexRadioButton->setEnabled(false);
    ui->SendTextRadioButton->setChecked(true);
    ui->SendTextRadioButton->setEnabled(false);
    ui->ReceiveTextRadioButton->setChecked(true);
    ui->ReceiveHexRadioButton->setChecked(false);
    ui->ReceiveDIsplayCheckBox->setChecked(true);

    connect(ui->AutoRepeatCheckBox, &QCheckBox::stateChanged, this, &Widget::TimerToSend);
    connect(timer, &QTimer::timeout, this, &Widget::on_SendPushButton_clicked);
}

Widget::~Widget()
{
    delete ui;
    delete serialPort;
    delete timer;
}


//初始化串口设置UI信息
void Widget::InitUartPort()
{
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->UartPortComboBox->addItem(info.portName());
            serial.close();
        }
    }
    QStringList baudList;
    QStringList parityList;
    QStringList dataBitsList;
    QStringList stopBitsList;

    baudList<<"9600"<<"115200";
    ui->BaudComboBox->addItems(baudList);
    ui->BaudComboBox->setCurrentIndex(1);

    parityList<<"无";
    ui->ParityBitComboBox->addItems(parityList);
    ui->ParityBitComboBox->setCurrentIndex(0);

    dataBitsList<<"8";
    ui->DataBitComboBox->addItems(dataBitsList);
    ui->DataBitComboBox->setCurrentIndex(0);

    stopBitsList<<"1";
    ui->StopBitComboBox->addItems(stopBitsList);

}

void Widget::ReadData()
{
    QByteArray buf;

    if(serialPort)
    {
        buf = serialPort->readAll();

        if(ui->ReceiveTextRadioButton->isChecked() && !ui->WaveChanalOneCheckBox->isChecked())
        {
            if (!buf.isEmpty())
            {
                QString myStrTemp = QString::fromLocal8Bit(buf); //支持中文显示
                if(ui->ReceiveDIsplayCheckBox->isChecked())
                {
                    QString str = ui->ReceiveTextBrowser->toPlainText();
                    str +=myStrTemp;
                    if(ui->AutoNewLineCheckBox->isChecked())
                    {
                        str += "\r\n";
                    }
                    ui->ReceiveTextBrowser->clear();
                    ui->ReceiveTextBrowser->append(str);
                }
            }
        }
        else if(ui->ReceiveHexRadioButton->isChecked()&& !ui->WaveChanalOneCheckBox->isChecked())
        {
            QDataStream out(&buf,QIODevice::ReadOnly);//将字节数组读入
            while(!out.atEnd())
            {
                qint8 outChar = 0;
                out>>outChar;

                QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));

                ui->ReceiveTextBrowser->insertPlainText(str.toUpper());
                ui->ReceiveTextBrowser->insertPlainText(" ");
                ui->ReceiveTextBrowser->moveCursor(QTextCursor::End);
            }
        }
        else
        {
            if(ui->WaveChanalOneCheckBox->isChecked())
            {
                QString str = ui->ReceiveTextBrowser->toPlainText();

                int bufferlens = 0;     //帧长
                QByteArray bufferbegin = "*";   //帧头
                int index=0;
                QByteArray bufferend = "#";     //帧尾
                int indexend = 0;
                QByteArray buffercashe;

                index = buf.indexOf(bufferbegin,index); //查找帧头
                indexend = buf.indexOf(bufferend,indexend); //查找帧尾
                if((index<buf.size())&&(indexend<buf.size()))
                {
                    bufferlens = indexend - index + 1; //计算帧长度
                    buffercashe = buf.mid(index,bufferlens); //截取出数据帧
                }
                char recvdata[buffercashe.size()];
                memset(recvdata,0,sizeof(recvdata));
                memcpy(recvdata,buffercashe.data(),bufferlens-1);
                recvdata[buffercashe.size()-1]=35;

                if(recvdata[0]=='*'&&recvdata[buffercashe.size()-1]=='#')   //二次帧检查
                {
                    StringToNumber(recvdata);//更新数据并缓存到保存区
                    str+=">>>";
                    str+=tr(buffercashe);
                    str += "\r\n";
                    ui->ReceiveTextBrowser->clear();
                    ui->ReceiveTextBrowser->append(str);
                }
                else
                {
                    str+="xxx"; //错误处理
                    str+=tr(buffercashe);
                    str += "\r\n";
                    ui->ReceiveTextBrowser->clear();
                    ui->ReceiveTextBrowser->append(str);
                }
            }
        }
        buf.clear();
    }
}

void Widget::TimerToSend()
{
    if(ui->AutoRepeatCheckBox->isChecked())
    {
        if(timer->isActive()) return;
        else
        {
            int ms = ui->RepeatNumberLineEdit->text().toInt();
            timer->start(ms);
        }
    }
    else
    {
        if(timer->isActive()) timer->stop();
        else return;
    }
}

void Widget::on_OpenUartPushButton_clicked()
{
    if(ui->OpenUartPushButton->text() == tr("打开串口") )
    {
        serialPort = new QSerialPort;
        serialPort->setPortName(ui->UartPortComboBox->currentText());

        if(serialPort->open(QIODevice::ReadWrite))
        {
            //设置串口波特率
            switch (ui->BaudComboBox->currentIndex())
            {
                case 0:
                    serialPort->setBaudRate(QSerialPort::Baud9600);
                    break;
                case 1:
                    serialPort->setBaudRate(QSerialPort::Baud115200);
                    break;
                default:
                    break;
            }
            //设置串口停止位
            switch (ui->StopBitComboBox->currentIndex())
            {
                case 0:
                    serialPort->setStopBits(QSerialPort::OneStop);
                    break;
                default:
                    break;
            }
            //设置串口数据位
            switch (ui->DataBitComboBox->currentIndex())
            {
                case 0:
                    serialPort->setDataBits(QSerialPort::Data8);
                    break;
                default:
                    break;
            }
            //设置串口奇偶校验位
            switch (ui->ParityBitComboBox->currentIndex())
            {
                case 0:
                    serialPort->setParity(QSerialPort::NoParity);
                    break;
                default:
                    break;
            }

            ui->OpenUartPushButton->setText(tr("关闭串口"));
            ui->UartPortComboBox->setEnabled(false);
            ui->BaudComboBox->setEnabled(false);
            ui->StopBitComboBox->setEnabled(false);
            ui->DataBitComboBox->setEnabled(false);
            ui->ParityBitComboBox->setEnabled(false);
            ui->SendPushButton->setEnabled(true);
            ui->SendTextRadioButton->setEnabled(true);
            ui->SendHexRadioButton->setEnabled(true);

            connect(serialPort, &QSerialPort::readyRead, this, &Widget::ReadData);
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), serialPort->errorString());
        }
    }
    else
    {
        serialPort->clear();
        serialPort->close();
        serialPort->deleteLater();

        ui->SendPushButton->setEnabled(false);
        ui->OpenUartPushButton->setText(tr("打开串口"));
        ui->UartPortComboBox->setEnabled(true);
        ui->BaudComboBox->setEnabled(true);
        ui->StopBitComboBox->setEnabled(true);
        ui->DataBitComboBox->setEnabled(true);
        ui->ParityBitComboBox->setEnabled(true);
        ui->SendHexRadioButton->setEnabled(false);
        ui->SendTextRadioButton->setEnabled(false);
    }
}


void Widget::on_ClearReceivePushButton_clicked()
{
    ui->ReceiveTextBrowser->clear();
}


void Widget::on_ClearSendPushButton_clicked()
{
    ui->SendPlainTextEdit->clear();
}


char Widget::CharToHex(char ch)
{
    if((ch >= '0') && (ch <= '9')) return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F')) return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f')) return ch-'a'+10;
    else return ch-ch;
}

void Widget::StringToHex(QString str, QByteArray &SendData)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    SendData.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len) break;
        lstr = str[i].toLatin1();
        hexdata = CharToHex(hstr);
        lowhexdata = CharToHex(lstr);
        if((hexdata == 16) || (lowhexdata == 16)) break;
        else hexdata = hexdata*16+lowhexdata;
        i++;
        SendData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    SendData.resize(hexdatalen);
}

void Widget::on_SendPushButton_clicked()
{
    QString str = ui->SendPlainTextEdit->toPlainText();

    if(!str.isEmpty())
    {
        auto isSendHex = ui->SendHexRadioButton->isChecked();

        QByteArray SendData;
        if(isSendHex)
        {
            StringToHex(str, SendData);
            serialPort->write(SendData);
        }
        else
        {
            if(serialPort->write(ui->SendPlainTextEdit->toPlainText().toLocal8Bit()) < 0)
            {
                QMessageBox::critical(this, tr("Error"), serialPort->errorString());
            }
        }
    }
}

void Widget::StringToNumber(char string[])
{
    int i=1,j=0;
    int num[1] ={0};
    std::string snum = "000";   //接收的数字位数最大三位
    for(int six = 0; six < 1; six++)
    {
        while(string[i]!=','&& string[i]!=35)  //解析单个数字位，测试用数据格式 *2,13,110,120,130#
        {
            snum[j]=string[i];
            i++;
            j++;
        }
        if(j==1) {snum[2]=snum[0];snum[0]='0';}
        if(j==2) {snum[2]=snum[1];snum[1]=snum[0];snum[0]='0';}   //根据数字位数进行顺序矫正
        num[six] = std::stoi(snum,0,10);
        i++;
        j=0;
    }
    if(ui->WaveChanalOneCheckBox->isChecked()) Data.Sensor_1 = (float)num[0];  //更新当前传感器数据组
    else Data.Sensor_1 = MAX_Y/2;

    if(count > MAX_X)
    {
        //当曲线上最早的点超出X轴的范围时，剔除最早的点，
        lineSeries1->removePoints(0,lineSeries1->count() - MAX_X);
        chart->axes(Qt::Horizontal).back()->setMin(count - MAX_X);
        chart->axes(Qt::Horizontal).back()->setMax(count);
    }
    else{
        chart->axes(Qt::Horizontal).back()->setMin(0);
        chart->axes(Qt::Horizontal).back()->setMax(MAX_X);
    }
    lineSeries1->append(count, (int)Data.Sensor_1);

    count ++;
}



//曲线设置初始化
void Widget::Chart_Init()
{
    //初始化QChart的实例
    chart = new QChart();

    lineSeries1 = new QSplineSeries();
    lineSeries1->setName("通道1");
    chart->addSeries(lineSeries1);

    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();

    //设置坐标轴显示的范围
    axisX->setMin(0);
    axisX->setMax(MAX_X);
    axisY->setMin(0);
    axisY->setMax(MAX_Y);

    //设置坐标轴上的格点
    axisX->setTickCount(10);
    axisY->setTickCount(10);

    //设置坐标轴显示的名称
    QFont font("Microsoft YaHei",8,QFont::Normal);//微软雅黑。字体大小8
    axisX->setTitleFont(font);
    axisY->setTitleFont(font);
    axisX->setTitleText("X-时间");
    axisY->setTitleText("Y-角度");

    //设置网格不显示
    axisY->setGridLineVisible(false);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    //把曲线关联到坐标轴
    lineSeries1->attachAxis(axisX);
    lineSeries1->attachAxis(axisY);

    //把chart显示到窗口上
    ui->WaveDisplayGraphicsView->setChart(chart);
    ui->WaveDisplayGraphicsView->setRenderHint(QPainter::Antialiasing); // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
}

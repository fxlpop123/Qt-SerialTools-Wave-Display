/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *UartSettingGroupBox;
    QGridLayout *gridLayout;
    QLabel *UartPortLabel;
    QLabel *BaudLabel;
    QLabel *StopBitLabel;
    QLabel *DataBitLabel;
    QLabel *ParityBitLabel;
    QPushButton *OpenUartPushButton;
    QComboBox *UartPortComboBox;
    QComboBox *BaudComboBox;
    QComboBox *StopBitComboBox;
    QComboBox *DataBitComboBox;
    QComboBox *ParityBitComboBox;
    QGroupBox *ReceiveSettingGroupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *ReceiveTextRadioButton;
    QRadioButton *ReceiveHexRadioButton;
    QCheckBox *AutoNewLineCheckBox;
    QCheckBox *ReceiveDIsplayCheckBox;
    QPushButton *ClearReceivePushButton;
    QGroupBox *SendSettingGroupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *SendTextRadioButton;
    QRadioButton *SendHexRadioButton;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *AutoRepeatCheckBox;
    QSpacerItem *horizontalSpacer;
    QLineEdit *RepeatNumberLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ClearSendPushButton;
    QPushButton *SendPushButton;
    QGroupBox *WaveSettingGroupBox;
    QPushButton *WaveDataExportPushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *WaveChanalOneCheckBox;
    QCheckBox *WaveChanalTwoCheckBox;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *WaveChanalThreeCheckBox;
    QCheckBox *WaveChanalFourCheckBox;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *WaveChanalFiveCheckBox;
    QCheckBox *WaveChanalSixCheckBox;
    QGroupBox *SendGroupBox;
    QPlainTextEdit *SendPlainTextEdit;
    QGroupBox *ReceiveGroupBox;
    QTextBrowser *ReceiveTextBrowser;
    QGroupBox *WaveGroupBox;
    QChartView *WaveDisplayGraphicsView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1303, 1006);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        UartSettingGroupBox = new QGroupBox(Widget);
        UartSettingGroupBox->setObjectName("UartSettingGroupBox");
        UartSettingGroupBox->setGeometry(QRect(20, 20, 261, 281));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setKerning(true);
        UartSettingGroupBox->setFont(font1);
        gridLayout = new QGridLayout(UartSettingGroupBox);
        gridLayout->setObjectName("gridLayout");
        UartPortLabel = new QLabel(UartSettingGroupBox);
        UartPortLabel->setObjectName("UartPortLabel");
        UartPortLabel->setFont(font1);

        gridLayout->addWidget(UartPortLabel, 0, 0, 1, 1);

        BaudLabel = new QLabel(UartSettingGroupBox);
        BaudLabel->setObjectName("BaudLabel");

        gridLayout->addWidget(BaudLabel, 1, 0, 1, 1);

        StopBitLabel = new QLabel(UartSettingGroupBox);
        StopBitLabel->setObjectName("StopBitLabel");

        gridLayout->addWidget(StopBitLabel, 2, 0, 1, 1);

        DataBitLabel = new QLabel(UartSettingGroupBox);
        DataBitLabel->setObjectName("DataBitLabel");

        gridLayout->addWidget(DataBitLabel, 3, 0, 1, 1);

        ParityBitLabel = new QLabel(UartSettingGroupBox);
        ParityBitLabel->setObjectName("ParityBitLabel");

        gridLayout->addWidget(ParityBitLabel, 4, 0, 1, 1);

        OpenUartPushButton = new QPushButton(UartSettingGroupBox);
        OpenUartPushButton->setObjectName("OpenUartPushButton");
        sizePolicy.setHeightForWidth(OpenUartPushButton->sizePolicy().hasHeightForWidth());
        OpenUartPushButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setKerning(true);
        OpenUartPushButton->setFont(font2);

        gridLayout->addWidget(OpenUartPushButton, 5, 0, 1, 3);

        UartPortComboBox = new QComboBox(UartSettingGroupBox);
        UartPortComboBox->setObjectName("UartPortComboBox");

        gridLayout->addWidget(UartPortComboBox, 0, 1, 1, 2);

        BaudComboBox = new QComboBox(UartSettingGroupBox);
        BaudComboBox->setObjectName("BaudComboBox");

        gridLayout->addWidget(BaudComboBox, 1, 1, 1, 2);

        StopBitComboBox = new QComboBox(UartSettingGroupBox);
        StopBitComboBox->setObjectName("StopBitComboBox");

        gridLayout->addWidget(StopBitComboBox, 2, 1, 1, 2);

        DataBitComboBox = new QComboBox(UartSettingGroupBox);
        DataBitComboBox->setObjectName("DataBitComboBox");

        gridLayout->addWidget(DataBitComboBox, 3, 1, 1, 2);

        ParityBitComboBox = new QComboBox(UartSettingGroupBox);
        ParityBitComboBox->setObjectName("ParityBitComboBox");

        gridLayout->addWidget(ParityBitComboBox, 4, 1, 1, 2);

        ReceiveSettingGroupBox = new QGroupBox(Widget);
        ReceiveSettingGroupBox->setObjectName("ReceiveSettingGroupBox");
        ReceiveSettingGroupBox->setGeometry(QRect(20, 330, 261, 171));
        ReceiveSettingGroupBox->setFont(font);
        gridLayout_2 = new QGridLayout(ReceiveSettingGroupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        ReceiveTextRadioButton = new QRadioButton(ReceiveSettingGroupBox);
        ReceiveTextRadioButton->setObjectName("ReceiveTextRadioButton");

        gridLayout_2->addWidget(ReceiveTextRadioButton, 0, 0, 1, 1);

        ReceiveHexRadioButton = new QRadioButton(ReceiveSettingGroupBox);
        ReceiveHexRadioButton->setObjectName("ReceiveHexRadioButton");

        gridLayout_2->addWidget(ReceiveHexRadioButton, 0, 1, 1, 1);

        AutoNewLineCheckBox = new QCheckBox(ReceiveSettingGroupBox);
        AutoNewLineCheckBox->setObjectName("AutoNewLineCheckBox");

        gridLayout_2->addWidget(AutoNewLineCheckBox, 1, 0, 1, 1);

        ReceiveDIsplayCheckBox = new QCheckBox(ReceiveSettingGroupBox);
        ReceiveDIsplayCheckBox->setObjectName("ReceiveDIsplayCheckBox");

        gridLayout_2->addWidget(ReceiveDIsplayCheckBox, 1, 1, 1, 1);

        ClearReceivePushButton = new QPushButton(ReceiveSettingGroupBox);
        ClearReceivePushButton->setObjectName("ClearReceivePushButton");
        sizePolicy.setHeightForWidth(ClearReceivePushButton->sizePolicy().hasHeightForWidth());
        ClearReceivePushButton->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(15);
        ClearReceivePushButton->setFont(font3);

        gridLayout_2->addWidget(ClearReceivePushButton, 2, 0, 1, 2);

        SendSettingGroupBox = new QGroupBox(Widget);
        SendSettingGroupBox->setObjectName("SendSettingGroupBox");
        SendSettingGroupBox->setGeometry(QRect(20, 530, 261, 171));
        SendSettingGroupBox->setFont(font);
        gridLayout_3 = new QGridLayout(SendSettingGroupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        SendTextRadioButton = new QRadioButton(SendSettingGroupBox);
        SendTextRadioButton->setObjectName("SendTextRadioButton");

        horizontalLayout->addWidget(SendTextRadioButton);

        SendHexRadioButton = new QRadioButton(SendSettingGroupBox);
        SendHexRadioButton->setObjectName("SendHexRadioButton");

        horizontalLayout->addWidget(SendHexRadioButton);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        AutoRepeatCheckBox = new QCheckBox(SendSettingGroupBox);
        AutoRepeatCheckBox->setObjectName("AutoRepeatCheckBox");

        horizontalLayout_2->addWidget(AutoRepeatCheckBox);

        horizontalSpacer = new QSpacerItem(38, 36, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_2->addItem(horizontalSpacer);

        RepeatNumberLineEdit = new QLineEdit(SendSettingGroupBox);
        RepeatNumberLineEdit->setObjectName("RepeatNumberLineEdit");

        horizontalLayout_2->addWidget(RepeatNumberLineEdit);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 10);

        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ClearSendPushButton = new QPushButton(SendSettingGroupBox);
        ClearSendPushButton->setObjectName("ClearSendPushButton");
        sizePolicy.setHeightForWidth(ClearSendPushButton->sizePolicy().hasHeightForWidth());
        ClearSendPushButton->setSizePolicy(sizePolicy);
        ClearSendPushButton->setFont(font3);

        horizontalLayout_3->addWidget(ClearSendPushButton);

        SendPushButton = new QPushButton(SendSettingGroupBox);
        SendPushButton->setObjectName("SendPushButton");
        sizePolicy.setHeightForWidth(SendPushButton->sizePolicy().hasHeightForWidth());
        SendPushButton->setSizePolicy(sizePolicy);
        SendPushButton->setFont(font3);

        horizontalLayout_3->addWidget(SendPushButton);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        WaveSettingGroupBox = new QGroupBox(Widget);
        WaveSettingGroupBox->setObjectName("WaveSettingGroupBox");
        WaveSettingGroupBox->setGeometry(QRect(20, 730, 261, 261));
        WaveSettingGroupBox->setFont(font);
        WaveDataExportPushButton = new QPushButton(WaveSettingGroupBox);
        WaveDataExportPushButton->setObjectName("WaveDataExportPushButton");
        WaveDataExportPushButton->setGeometry(QRect(13, 154, 231, 91));
        sizePolicy.setHeightForWidth(WaveDataExportPushButton->sizePolicy().hasHeightForWidth());
        WaveDataExportPushButton->setSizePolicy(sizePolicy);
        WaveDataExportPushButton->setFont(font3);
        layoutWidget = new QWidget(WaveSettingGroupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(13, 36, 231, 105));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        WaveChanalOneCheckBox = new QCheckBox(layoutWidget);
        WaveChanalOneCheckBox->setObjectName("WaveChanalOneCheckBox");

        horizontalLayout_4->addWidget(WaveChanalOneCheckBox);

        WaveChanalTwoCheckBox = new QCheckBox(layoutWidget);
        WaveChanalTwoCheckBox->setObjectName("WaveChanalTwoCheckBox");

        horizontalLayout_4->addWidget(WaveChanalTwoCheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        WaveChanalThreeCheckBox = new QCheckBox(layoutWidget);
        WaveChanalThreeCheckBox->setObjectName("WaveChanalThreeCheckBox");

        horizontalLayout_5->addWidget(WaveChanalThreeCheckBox);

        WaveChanalFourCheckBox = new QCheckBox(layoutWidget);
        WaveChanalFourCheckBox->setObjectName("WaveChanalFourCheckBox");

        horizontalLayout_5->addWidget(WaveChanalFourCheckBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        WaveChanalFiveCheckBox = new QCheckBox(layoutWidget);
        WaveChanalFiveCheckBox->setObjectName("WaveChanalFiveCheckBox");

        horizontalLayout_6->addWidget(WaveChanalFiveCheckBox);

        WaveChanalSixCheckBox = new QCheckBox(layoutWidget);
        WaveChanalSixCheckBox->setObjectName("WaveChanalSixCheckBox");

        horizontalLayout_6->addWidget(WaveChanalSixCheckBox);


        verticalLayout->addLayout(horizontalLayout_6);

        SendGroupBox = new QGroupBox(Widget);
        SendGroupBox->setObjectName("SendGroupBox");
        SendGroupBox->setGeometry(QRect(310, 880, 971, 111));
        SendGroupBox->setFont(font);
        SendPlainTextEdit = new QPlainTextEdit(SendGroupBox);
        SendPlainTextEdit->setObjectName("SendPlainTextEdit");
        SendPlainTextEdit->setGeometry(QRect(10, 20, 951, 81));
        ReceiveGroupBox = new QGroupBox(Widget);
        ReceiveGroupBox->setObjectName("ReceiveGroupBox");
        ReceiveGroupBox->setGeometry(QRect(310, 460, 971, 401));
        ReceiveGroupBox->setFont(font);
        ReceiveTextBrowser = new QTextBrowser(ReceiveGroupBox);
        ReceiveTextBrowser->setObjectName("ReceiveTextBrowser");
        ReceiveTextBrowser->setGeometry(QRect(10, 30, 951, 361));
        WaveGroupBox = new QGroupBox(Widget);
        WaveGroupBox->setObjectName("WaveGroupBox");
        WaveGroupBox->setGeometry(QRect(310, 20, 971, 431));
        WaveGroupBox->setFont(font);
        WaveDisplayGraphicsView = new QChartView(WaveGroupBox);
        WaveDisplayGraphicsView->setObjectName("WaveDisplayGraphicsView");
        WaveDisplayGraphicsView->setGeometry(QRect(10, 30, 951, 391));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        UartSettingGroupBox->setTitle(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        UartPortLabel->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", nullptr));
        BaudLabel->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        StopBitLabel->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        DataBitLabel->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        ParityBitLabel->setText(QCoreApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", nullptr));
        OpenUartPushButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        ReceiveSettingGroupBox->setTitle(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        ReceiveTextRadioButton->setText(QCoreApplication::translate("Widget", "\346\226\207\346\234\254", nullptr));
        ReceiveHexRadioButton->setText(QCoreApplication::translate("Widget", "Hex", nullptr));
        AutoNewLineCheckBox->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        ReceiveDIsplayCheckBox->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\216\245\346\224\266", nullptr));
        ClearReceivePushButton->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\346\230\276\347\244\272", nullptr));
        SendSettingGroupBox->setTitle(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
        SendTextRadioButton->setText(QCoreApplication::translate("Widget", "\346\226\207\346\234\254", nullptr));
        SendHexRadioButton->setText(QCoreApplication::translate("Widget", "Hex", nullptr));
        AutoRepeatCheckBox->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\351\207\215\345\217\221(ms)", nullptr));
        ClearSendPushButton->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        SendPushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        WaveSettingGroupBox->setTitle(QCoreApplication::translate("Widget", "\346\263\242\345\275\242\350\256\276\347\275\256", nullptr));
        WaveDataExportPushButton->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        WaveChanalOneCheckBox->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\344\270\200", nullptr));
        WaveChanalTwoCheckBox->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\344\272\214", nullptr));
        WaveChanalThreeCheckBox->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\344\270\211", nullptr));
        WaveChanalFourCheckBox->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\345\233\233", nullptr));
        WaveChanalFiveCheckBox->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\344\272\224", nullptr));
        WaveChanalSixCheckBox->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\345\205\255", nullptr));
        SendGroupBox->setTitle(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\345\206\205\345\256\271", nullptr));
        ReceiveGroupBox->setTitle(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\206\205\345\256\271", nullptr));
        WaveGroupBox->setTitle(QCoreApplication::translate("Widget", "\346\263\242\345\275\242\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

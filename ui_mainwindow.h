/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 23. Jan 13:43:19 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionDenoising;
    QAction *actionCustom_Filter;
    QAction *actionInsert_Image;
    QAction *actionExtract_Image;
    QAction *actionEncode_Image;
    QAction *actionDecode_Image;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QLabel *label_3;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;
    QSpinBox *spinBox_10;
    QSpinBox *spinBox_11;
    QSpinBox *spinBox_12;
    QSpinBox *spinBox_13;
    QSpinBox *spinBox_14;
    QSpinBox *spinBox_15;
    QSpinBox *spinBox_16;
    QSpinBox *spinBox_17;
    QSpinBox *spinBox_18;
    QSpinBox *spinBox_19;
    QSpinBox *spinBox_20;
    QSpinBox *spinBox_21;
    QSpinBox *spinBox_22;
    QSpinBox *spinBox_23;
    QSpinBox *spinBox_24;
    QSpinBox *spinBox_25;
    QPushButton *showImageCustomFilterButton;
    QLabel *label_5;
    QSpinBox *spinBox_51;
    QSpinBox *spinBox_52;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;
    QLineEdit *lineE;
    QLineEdit *lineD;
    QLineEdit *lineN;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1199, 689);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionDenoising = new QAction(MainWindow);
        actionDenoising->setObjectName(QString::fromUtf8("actionDenoising"));
        actionCustom_Filter = new QAction(MainWindow);
        actionCustom_Filter->setObjectName(QString::fromUtf8("actionCustom_Filter"));
        actionInsert_Image = new QAction(MainWindow);
        actionInsert_Image->setObjectName(QString::fromUtf8("actionInsert_Image"));
        actionExtract_Image = new QAction(MainWindow);
        actionExtract_Image->setObjectName(QString::fromUtf8("actionExtract_Image"));
        actionEncode_Image = new QAction(MainWindow);
        actionEncode_Image->setObjectName(QString::fromUtf8("actionEncode_Image"));
        actionDecode_Image = new QAction(MainWindow);
        actionDecode_Image->setObjectName(QString::fromUtf8("actionDecode_Image"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 461, 551));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(460, 30, 481, 551));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 461, 31));
        label->setScaledContents(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(460, 0, 481, 31));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(940, 0, 221, 581));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 30, 161, 16));
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 50, 41, 21));
        spinBox->setMinimum(-99);
        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(50, 50, 41, 21));
        spinBox_2->setMinimum(-99);
        spinBox_3 = new QSpinBox(frame);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(90, 50, 41, 21));
        spinBox_3->setMinimum(-99);
        spinBox_4 = new QSpinBox(frame);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(130, 50, 41, 21));
        spinBox_4->setMinimum(-99);
        spinBox_5 = new QSpinBox(frame);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(170, 50, 41, 21));
        spinBox_5->setMinimum(-99);
        spinBox_6 = new QSpinBox(frame);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(10, 70, 41, 21));
        spinBox_6->setMinimum(-99);
        spinBox_7 = new QSpinBox(frame);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(50, 70, 41, 21));
        spinBox_7->setMinimum(-99);
        spinBox_8 = new QSpinBox(frame);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setGeometry(QRect(90, 70, 41, 21));
        spinBox_8->setMinimum(-99);
        spinBox_9 = new QSpinBox(frame);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setGeometry(QRect(130, 70, 41, 21));
        spinBox_9->setMinimum(-99);
        spinBox_10 = new QSpinBox(frame);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setGeometry(QRect(170, 70, 41, 21));
        spinBox_10->setMinimum(-99);
        spinBox_11 = new QSpinBox(frame);
        spinBox_11->setObjectName(QString::fromUtf8("spinBox_11"));
        spinBox_11->setGeometry(QRect(10, 90, 41, 21));
        spinBox_11->setMinimum(-99);
        spinBox_12 = new QSpinBox(frame);
        spinBox_12->setObjectName(QString::fromUtf8("spinBox_12"));
        spinBox_12->setGeometry(QRect(50, 90, 41, 21));
        spinBox_12->setMinimum(-99);
        spinBox_13 = new QSpinBox(frame);
        spinBox_13->setObjectName(QString::fromUtf8("spinBox_13"));
        spinBox_13->setGeometry(QRect(90, 90, 41, 21));
        spinBox_13->setMinimum(-99);
        spinBox_13->setValue(1);
        spinBox_14 = new QSpinBox(frame);
        spinBox_14->setObjectName(QString::fromUtf8("spinBox_14"));
        spinBox_14->setGeometry(QRect(130, 90, 41, 21));
        spinBox_14->setMinimum(-99);
        spinBox_15 = new QSpinBox(frame);
        spinBox_15->setObjectName(QString::fromUtf8("spinBox_15"));
        spinBox_15->setGeometry(QRect(170, 90, 41, 21));
        spinBox_15->setMinimum(-99);
        spinBox_15->setValue(0);
        spinBox_16 = new QSpinBox(frame);
        spinBox_16->setObjectName(QString::fromUtf8("spinBox_16"));
        spinBox_16->setGeometry(QRect(10, 110, 41, 21));
        spinBox_16->setMinimum(-99);
        spinBox_17 = new QSpinBox(frame);
        spinBox_17->setObjectName(QString::fromUtf8("spinBox_17"));
        spinBox_17->setGeometry(QRect(50, 110, 41, 21));
        spinBox_17->setMinimum(-99);
        spinBox_18 = new QSpinBox(frame);
        spinBox_18->setObjectName(QString::fromUtf8("spinBox_18"));
        spinBox_18->setGeometry(QRect(90, 110, 41, 21));
        spinBox_18->setMinimum(-99);
        spinBox_19 = new QSpinBox(frame);
        spinBox_19->setObjectName(QString::fromUtf8("spinBox_19"));
        spinBox_19->setGeometry(QRect(130, 110, 41, 21));
        spinBox_19->setMinimum(-99);
        spinBox_20 = new QSpinBox(frame);
        spinBox_20->setObjectName(QString::fromUtf8("spinBox_20"));
        spinBox_20->setGeometry(QRect(170, 110, 41, 21));
        spinBox_20->setMinimum(-99);
        spinBox_21 = new QSpinBox(frame);
        spinBox_21->setObjectName(QString::fromUtf8("spinBox_21"));
        spinBox_21->setGeometry(QRect(10, 130, 41, 21));
        spinBox_21->setMinimum(-99);
        spinBox_22 = new QSpinBox(frame);
        spinBox_22->setObjectName(QString::fromUtf8("spinBox_22"));
        spinBox_22->setGeometry(QRect(50, 130, 41, 21));
        spinBox_22->setMinimum(-99);
        spinBox_23 = new QSpinBox(frame);
        spinBox_23->setObjectName(QString::fromUtf8("spinBox_23"));
        spinBox_23->setGeometry(QRect(90, 130, 41, 21));
        spinBox_23->setMinimum(-99);
        spinBox_24 = new QSpinBox(frame);
        spinBox_24->setObjectName(QString::fromUtf8("spinBox_24"));
        spinBox_24->setGeometry(QRect(130, 130, 41, 21));
        spinBox_24->setMinimum(-99);
        spinBox_25 = new QSpinBox(frame);
        spinBox_25->setObjectName(QString::fromUtf8("spinBox_25"));
        spinBox_25->setGeometry(QRect(170, 130, 41, 21));
        spinBox_25->setMinimum(-99);
        showImageCustomFilterButton = new QPushButton(frame);
        showImageCustomFilterButton->setObjectName(QString::fromUtf8("showImageCustomFilterButton"));
        showImageCustomFilterButton->setGeometry(QRect(70, 230, 75, 23));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 10, 141, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        spinBox_51 = new QSpinBox(frame);
        spinBox_51->setObjectName(QString::fromUtf8("spinBox_51"));
        spinBox_51->setGeometry(QRect(80, 160, 41, 21));
        spinBox_51->setMinimum(-255);
        spinBox_51->setMaximum(255);
        spinBox_51->setValue(1);
        spinBox_52 = new QSpinBox(frame);
        spinBox_52->setObjectName(QString::fromUtf8("spinBox_52"));
        spinBox_52->setGeometry(QRect(80, 190, 41, 21));
        spinBox_52->setMinimum(0);
        spinBox_52->setMaximum(255);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 160, 46, 21));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 190, 46, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(25, 600, 61, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 600, 46, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(170, 600, 51, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 600, 111, 23));
        lineE = new QLineEdit(centralWidget);
        lineE->setObjectName(QString::fromUtf8("lineE"));
        lineE->setGeometry(QRect(390, 600, 41, 20));
        lineD = new QLineEdit(centralWidget);
        lineD->setObjectName(QString::fromUtf8("lineD"));
        lineD->setGeometry(QRect(450, 600, 41, 20));
        lineN = new QLineEdit(centralWidget);
        lineN->setObjectName(QString::fromUtf8("lineN"));
        lineN->setGeometry(QRect(510, 600, 41, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(380, 600, 16, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(440, 600, 16, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(500, 600, 21, 16));
        MainWindow->setCentralWidget(centralWidget);
        graphicsView->raise();
        graphicsView_2->raise();
        label_2->raise();
        label->raise();
        frame->raise();
        label_4->raise();
        label_8->raise();
        label_9->raise();
        pushButton->raise();
        lineE->raise();
        lineD->raise();
        lineN->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1199, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuTools->addAction(actionDenoising);
        menuTools->addAction(actionCustom_Filter);
        mainToolBar->addAction(actionDenoising);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCustom_Filter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionInsert_Image);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExtract_Image);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionEncode_Image);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDecode_Image);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave_as->setToolTip(QApplication::translate("MainWindow", "Save as...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionDenoising->setText(QApplication::translate("MainWindow", "Denoising Filter", 0, QApplication::UnicodeUTF8));
        actionCustom_Filter->setText(QApplication::translate("MainWindow", "Custom Filter", 0, QApplication::UnicodeUTF8));
        actionInsert_Image->setText(QApplication::translate("MainWindow", "Insert Image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionInsert_Image->setToolTip(QApplication::translate("MainWindow", "Insert Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExtract_Image->setText(QApplication::translate("MainWindow", "Extract Image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExtract_Image->setToolTip(QApplication::translate("MainWindow", "Extract Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEncode_Image->setText(QApplication::translate("MainWindow", "Encode Image", 0, QApplication::UnicodeUTF8));
        actionDecode_Image->setText(QApplication::translate("MainWindow", "Decode Image", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">Before</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">After</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Weights Matrix for Custom Filter:", 0, QApplication::UnicodeUTF8));
        showImageCustomFilterButton->setText(QApplication::translate("MainWindow", "Show Image", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "CUSTOM FILTER", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Scale :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Offset", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Image size:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Generate e,d and n", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "e:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "d:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "n:", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

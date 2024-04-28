/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcameraviewfinder.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *logo_parkee;
    QLabel *label_12;
    QSpacerItem *verticalSpacer;
    QLabel *label_submit;
    QComboBox *List_Kendaraan;
    QLineEdit *input_plat;
    QComboBox *list_parkir;
    QVBoxLayout *verticalLayout_2;
    QLabel *date_time_label;
    QLabel *label_4;
    QLabel *label_plat;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_5;
    QCameraViewfinder *widget_camera;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(831, 496);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(13);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        logo_parkee = new QLabel(centralwidget);
        logo_parkee->setObjectName(QString::fromUtf8("logo_parkee"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        logo_parkee->setFont(font1);
        logo_parkee->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(logo_parkee, 1, 0, 1, 3);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 7, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 3);

        label_submit = new QLabel(centralwidget);
        label_submit->setObjectName(QString::fromUtf8("label_submit"));
        QFont font2;
        font2.setPointSize(14);
        label_submit->setFont(font2);
        label_submit->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color:rgb(114, 159, 207);\n"
"border:3px solid black;\n"
""));
        label_submit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_submit, 6, 0, 1, 3);

        List_Kendaraan = new QComboBox(centralwidget);
        List_Kendaraan->setObjectName(QString::fromUtf8("List_Kendaraan"));
        List_Kendaraan->setFont(font);

        gridLayout->addWidget(List_Kendaraan, 2, 1, 1, 2);

        input_plat = new QLineEdit(centralwidget);
        input_plat->setObjectName(QString::fromUtf8("input_plat"));
        input_plat->setFont(font);
        input_plat->setInputMethodHints(Qt::ImhUppercaseOnly);

        gridLayout->addWidget(input_plat, 3, 1, 1, 2);

        list_parkir = new QComboBox(centralwidget);
        list_parkir->setObjectName(QString::fromUtf8("list_parkir"));
        list_parkir->setFont(font);

        gridLayout->addWidget(list_parkir, 4, 1, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        date_time_label = new QLabel(centralwidget);
        date_time_label->setObjectName(QString::fromUtf8("date_time_label"));
        QFont font3;
        font3.setPointSize(41);
        font3.setBold(true);
        font3.setWeight(75);
        date_time_label->setFont(font3);
        date_time_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(date_time_label);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        label_plat = new QLabel(centralwidget);
        label_plat->setObjectName(QString::fromUtf8("label_plat"));
        QFont font4;
        font4.setPointSize(57);
        label_plat->setFont(font4);
        label_plat->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_plat);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(191, 192, 188);"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font5;
        font5.setPointSize(41);
        label_9->setFont(font5);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_9);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(191, 192, 188);"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        widget_camera = new QCameraViewfinder(centralwidget);
        widget_camera->setObjectName(QString::fromUtf8("widget_camera"));
        widget_camera->setMinimumSize(QSize(100, 100));

        verticalLayout_2->addWidget(widget_camera);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 831, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Jenis Kendaraan (F2)", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Jenis Parkir (F4)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nomor Kendaraan (F3)", nullptr));
        logo_parkee->setText(QCoreApplication::translate("MainWindow", "Pintu Masuk 1 - Parkee", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Atur Ulang Halaman (F5)", nullptr));
        label_submit->setText(QCoreApplication::translate("MainWindow", "Submit Ticket (F1)", nullptr));
        date_time_label->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "No Kendaraan", nullptr));
        label_plat->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Nama POS", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "PM 1 - PARKEE", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Kamera", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Exit (Alt+esc)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Member (F10)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Manual Entry (F11)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

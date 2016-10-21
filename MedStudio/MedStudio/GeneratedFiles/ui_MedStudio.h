/********************************************************************************
** Form generated from reading UI file 'MedStudio.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDSTUDIO_H
#define UI_MEDSTUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MedStudioClass
{
public:
    QAction *actionOpenDicom;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MedStudioClass)
    {
        if (MedStudioClass->objectName().isEmpty())
            MedStudioClass->setObjectName(QStringLiteral("MedStudioClass"));
        MedStudioClass->resize(1167, 859);
        actionOpenDicom = new QAction(MedStudioClass);
        actionOpenDicom->setObjectName(QStringLiteral("actionOpenDicom"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MedStudio/skin_image/OpenDicom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenDicom->setIcon(icon);
        centralWidget = new QWidget(MedStudioClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(128, 128, 128);"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MedStudioClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MedStudioClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setIconSize(QSize(35, 35));
        MedStudioClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MedStudioClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MedStudioClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionOpenDicom);

        retranslateUi(MedStudioClass);

        QMetaObject::connectSlotsByName(MedStudioClass);
    } // setupUi

    void retranslateUi(QMainWindow *MedStudioClass)
    {
        MedStudioClass->setWindowTitle(QApplication::translate("MedStudioClass", "MedStudio", 0));
        actionOpenDicom->setText(QApplication::translate("MedStudioClass", "OpenDicom", 0));
#ifndef QT_NO_TOOLTIP
        actionOpenDicom->setToolTip(QApplication::translate("MedStudioClass", "OpenDicom", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MedStudioClass: public Ui_MedStudioClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDSTUDIO_H

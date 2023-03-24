#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <iostream>

#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSplitter>
#include <QDockWidget>
#include <QTime>
#include <QSizePolicy>

MainWindow::MainWindow()
{
    QPalette pal = palette();
    QPalette blk = palette();
    pal.setColor(QPalette::Window, Qt::darkBlue);
    blk.setColor(QPalette::Window, Qt::black);
    this->setWindowTitle("Hello World!");
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    QSplitter* hSplitter = new QSplitter(Qt::Horizontal, this);
    QSplitter* vTopSplitter = new QSplitter(Qt::Vertical, this);
    QSplitter* vBottomSplitter = new QSplitter(Qt::Vertical, this);

    QWidget* topLeft = new QWidget(this);
    QWidget* topRight = new QWidget(this);
    QWidget* bottomLeft = new QWidget(this);
    QWidget* bottomRight = new QWidget(this);
    topLeft->setAutoFillBackground(true);
    topLeft->setPalette(blk);

    // QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Close"), this);
    // QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(close()));
    // button->move(10, 80);
    // button->show();

    // QComboBox *comboBox = new QComboBox(this);
    // comboBox->addItem("First");
    // comboBox->addItem("Second");
    // comboBox->addItem("Third");
    // comboBox->move(10,130);
    // connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));


    vTopSplitter->addWidget(topLeft);
    vTopSplitter->addWidget(topRight);
    vBottomSplitter->addWidget(bottomLeft);
    vBottomSplitter->addWidget(bottomRight);
    hSplitter->addWidget(vTopSplitter);
    hSplitter->addWidget(vBottomSplitter);

    QHBoxLayout *mainLay = new QHBoxLayout(this);
    mainLay->addWidget(hSplitter);

    bool debugFlag = false;
    if(debugFlag){
        this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    }

    this->show();
}

void MainWindow::handleSelectionChanged(int index)
{
    qInfo() << "Item:" << index << "was selected.";
}

MainWindow::~MainWindow()
{
}


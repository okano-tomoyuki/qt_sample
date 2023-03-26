#include "MainWindow.hpp"
#include "SideMenu.hpp"

#include <iostream>

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSplitter>
#include <QLayout>
#include <QMenu>

using namespace HumanMachineInterface;

MainWindow::MainWindow()
{
    QPalette pal = palette();
    QPalette blk = palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setWindowTitle("Sample");
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowState(windowState() ^ Qt::WindowMaximized);

    QSplitter* horizontalSplitter = new QSplitter(Qt::Horizontal, this);
    QSplitter* verticalRightSplitter = new QSplitter(Qt::Vertical, this);

    SideMenu* leftWidget = new SideMenu(this);
    QWidget* centralWidget = new QWidget(this);
    QWidget* rightTopWidget = new QWidget(this);
    rightTopWidget->setObjectName("RightTopWidget");
    QWidget* rightBottomWidget = new QWidget(this);

    centralWidget->setStyleSheet(
        "background-color:black"
    );
    rightBottomWidget->setStyleSheet(
        "background-color:black"
    );


    verticalRightSplitter->addWidget(rightTopWidget);
    verticalRightSplitter->addWidget(rightBottomWidget);

    horizontalSplitter->addWidget(leftWidget);
    horizontalSplitter->addWidget(centralWidget);
    horizontalSplitter->addWidget(verticalRightSplitter);

    QVBoxLayout* vBoxlay = new QVBoxLayout(rightTopWidget);
    vBoxlay->setContentsMargins(0,0,0,0);

    QLabel* title = new QLabel("XXXXX",rightTopWidget);
    title->setObjectName("Title");
    QPushButton* okButton = new QPushButton("OK", rightTopWidget);
    QPushButton* cancelButton = new QPushButton("Cancel", rightTopWidget);

    QHBoxLayout* okCancel = new QHBoxLayout();
    okCancel->addWidget(okButton);
    okCancel->addWidget(cancelButton);
    okCancel->addStretch();

    vBoxlay->addWidget(title);
    vBoxlay->addLayout(okCancel);
    vBoxlay->addStretch();
    rightTopWidget->setStyleSheet(
        "QWidget#RightTopWidget {background-color:black;}"
        "QLabel#Title {background-color:darkblue;color:white;font-size:36px;padding:4px;}"
        "QPushButton {margin:5px;color:white;background:qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 cyan, stop:1 blue);border-radius:5px;font-size:24px;width:100px;height:30px;padding:2px;}"
        "QPushButton:hover {color:black;background-color:white;}"
        "QPushButton:pressed {background-color:white;}"
    );

    
    horizontalSplitter->setStretchFactor(0,1);
    horizontalSplitter->setStretchFactor(1,6);
    horizontalSplitter->setStretchFactor(2,2);
    verticalRightSplitter->setStretchFactor(0,1);
    verticalRightSplitter->setStretchFactor(1,1);

    this->setCentralWidget(horizontalSplitter);


    bool releaseFlag = false;
    if(releaseFlag){
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


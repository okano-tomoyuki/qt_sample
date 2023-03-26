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
    blk.setColor(QPalette::Window, Qt::gray);
    this->setWindowTitle("Sample");
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setWindowState(windowState() ^ Qt::WindowMaximized);

    QSplitter* horizontalSplitter = new QSplitter(Qt::Horizontal, this);
    QSplitter* verticalRightSplitter = new QSplitter(Qt::Vertical, this);

    QWidget* leftWidget = new QWidget(this);
    QWidget* centralWidget = new QWidget(this);
    QWidget* rightTopWidget = new QWidget(this);
    rightTopWidget->setObjectName("RightTopWidget");
    QWidget* rightBottomWidget = new QWidget(this);

    leftWidget->setStyleSheet(
        "background-color:black"
    );
    centralWidget->setStyleSheet(
        "background-color:black"
    );
    // rightTopWidget->setStyleSheet(
    //     "background-color:black"
    // );
    rightBottomWidget->setStyleSheet(
        "background-color:black"
    );


    verticalRightSplitter->addWidget(rightTopWidget);
    verticalRightSplitter->addWidget(rightBottomWidget);
    verticalRightSplitter->setSizes({1,1});

    horizontalSplitter->addWidget(leftWidget);
    horizontalSplitter->addWidget(centralWidget);
    horizontalSplitter->addWidget(verticalRightSplitter);
    horizontalSplitter->setSizes({1,6,3});

    QVBoxLayout* vBoxlay = new QVBoxLayout(rightTopWidget);
    QLabel* title = new QLabel("XXXXX",rightTopWidget);
    title->setObjectName("Title");
    QPushButton* okButton = new QPushButton("OK", rightTopWidget);
    QPushButton* cancelButton = new QPushButton("Cancel", rightTopWidget);

    QHBoxLayout* okCancel = new QHBoxLayout();
    okCancel->addWidget(okButton);
    okCancel->addWidget(cancelButton);
    okCancel->addStretch();

    vBoxlay->setContentsMargins(0,0,0,0);
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

    this->setCentralWidget(horizontalSplitter);

    // QComboBox *comboBox = new QComboBox(this);
    // comboBox->addItem("First");
    // comboBox->addItem("Second");
    // comboBox->addItem("Third");
    // comboBox->move(10,130);
    // connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));

    // QHBoxLayout *mainLay = new QHBoxLayout(this);
    // mainLay->addWidget(hSplitter);

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


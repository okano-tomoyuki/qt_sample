#include "Window/Primary.hpp"
#include "Widget/SideMenu.hpp"
#include "Widget/Actuator.hpp"
#include "Widget/AlertLog.hpp"
#include "Widget/SamplePainter.hpp"
#include "Widget/NavChart.hpp"

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSplitter>
#include <QLayout>
#include <QMenu>
#include <QApplication>

using namespace HMI;

PrimaryWindow::PrimaryWindow()
{
    this->setWindowTitle("Sample");
    this->setAutoFillBackground(true);
    this->setWindowState(windowState() ^ Qt::WindowMaximized);
    QIcon icon = QApplication::style()->standardIcon(QStyle::SP_DesktopIcon);
    this->setWindowIcon(icon);

    QSplitter* horizontalSplitter = new QSplitter(Qt::Horizontal, this);
    QSplitter* verticalRightSplitter = new QSplitter(Qt::Vertical, this);

    QWidget* leftWidget = new SideMenuWidget(this);
    leftWidget->setMinimumWidth(250);
    QWidget* centralWidget = new SamplePainter(this);
    QWidget* rightTopWidget = new ActuatorWidget(this);
    rightTopWidget->setMinimumWidth(450);
    QWidget* rightBottomWidget = new AlertLogWidget(this);

    verticalRightSplitter->addWidget(rightTopWidget);
    verticalRightSplitter->addWidget(rightBottomWidget);

    horizontalSplitter->addWidget(leftWidget);
    horizontalSplitter->addWidget(centralWidget);
    horizontalSplitter->addWidget(verticalRightSplitter);
    
    horizontalSplitter->setStretchFactor(0,1);
    horizontalSplitter->setStretchFactor(1,6);
    horizontalSplitter->setStretchFactor(2,2);
    verticalRightSplitter->setStretchFactor(0,1);
    verticalRightSplitter->setStretchFactor(1,2);

    this->setCentralWidget(horizontalSplitter);


    bool release = false;
    if(release){
        this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    }

    this->show();
}

void PrimaryWindow::handleSelectionChanged(int index)
{
    qInfo() << "Item:" << index << "was selected.";
}

PrimaryWindow::~PrimaryWindow()
{
}


#include "Widget/Actuator.hpp"
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QToolBar>

using namespace HMI;

ActuatorWidget::ActuatorWidget(QWidget* parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    auto vBoxlay = new QVBoxLayout(this);
    vBoxlay->setContentsMargins(0,0,0,0);

    /** Tool Bar Definition.*/
    auto actuatorToolBar = new QToolBar("Actuator", this);
    auto title = new QLabel("Actuator Info", this);
    title->setObjectName("Title");
    actuatorToolBar->addWidget(title);
    actuatorToolBar->addAction(new QAction("Switch", this));
    actuatorToolBar->addAction(new QAction("Config", this));

    // vBoxlay->addWidget(title);
    vBoxlay->addWidget(actuatorToolBar);
    vBoxlay->addStretch();

    this->setStyleSheet(
        "QLabel#Title {"
            "background-color:darkblue;"
            "color:white;"
            "font-size:36px;"
            "padding:4px;"
        "}"
        "QToolBar {"
            "background-color:darkblue;"
            "color:white;"
            "font-size:36px;"
            "padding:4px;"
        "}"
        "QToolButton {"
            "background:qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 aliceblue, stop:1 deepskyblue);"
            "border-radius:5px;"
            "color:black;"
            "font-size:18px;"
            "padding:4px;"
            "margin:5px;"
        "}"
        "QToolButton::hover {"
            "color:black;"
            "background-color:white;"
        "}"
        "QPushButton {"
            "margin:5px;"
            "color:black;"
            "background:qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 aliceblue, stop:1 deepskyblue);"
            "border-radius:5px;"
            "font-size:24px;"
            "width:100px;"
            "height:30px;"
            "padding:2px;"
        "}"
        "QPushButton::hover {"
            "color:black;"
            "background-color:white;"
        "}"
        "QPushButton::pressed {"
            "background-color:white;"
        "}"
    );
}

ActuatorWidget::~ActuatorWidget()
{

}
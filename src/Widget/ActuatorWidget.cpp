#include "Widget/ActuatorWidget.hpp"
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>

using namespace HumanMachineInterface;

ActuatorWidget::ActuatorWidget(QWidget* parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    QVBoxLayout* vBoxlay = new QVBoxLayout(this);
    vBoxlay->setContentsMargins(0,0,0,0);

    QLabel* title = new QLabel("Actuator Info",this);
    title->setObjectName("Title");
    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    QHBoxLayout* okCancel = new QHBoxLayout();
    okCancel->addWidget(okButton);
    okCancel->addWidget(cancelButton);
    okCancel->addStretch();

    vBoxlay->addWidget(title);
    vBoxlay->addLayout(okCancel);
    vBoxlay->addStretch();
    this->setStyleSheet(
        "QLabel#Title {background-color:darkblue;color:white;font-size:36px;padding:4px;}"
        "QPushButton {margin:5px;color:white;background:qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 cyan, stop:1 blue);border-radius:5px;font-size:24px;width:100px;height:30px;padding:2px;}"
        "QPushButton:hover {color:black;background-color:white;}"
        "QPushButton:pressed {background-color:white;}"
    );
}

ActuatorWidget::~ActuatorWidget()
{

}
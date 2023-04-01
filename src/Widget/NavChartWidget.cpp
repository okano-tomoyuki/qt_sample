#include "Widget/NavChart.hpp"
#include "Widget/SamplePainter.hpp"
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <QRect>

using namespace HMI;

NavChartWidget::NavChartWidget(QWidget* parent)
{

    QVBoxLayout* vBoxlay = new QVBoxLayout(this);
    vBoxlay->setContentsMargins(0,0,0,0);

    QLabel* title = new QLabel("Chart",this);
    title->setObjectName("Title");

    QWidget* paint = new SamplePainter(this);

    vBoxlay->addWidget(title);
    vBoxlay->addWidget(paint);
    vBoxlay->addStretch();


    this->setStyleSheet(
        "QLabel#Title {"
            "background-color:darkblue;"
            "color:white;"
            "font-size:36px;"
            "padding:4px;"
        "}"
        "QTableWidget {"
            "background-color:white;"
            "margin:20px;"
        "}"
        "QHeaderView::section {"
            "background-color:darkBlue;"
            "color:white;"
            "font-size:18px;"
        "}"
        "QPushButton {"
            "margin:5px;"
            "color:white;"
            "background:qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 cyan, stop:1 blue);"
            "border-radius:5px;"
            "font-size:24px;"
            "width:100px;"
            "height:30px;"
            "padding:2px;"
        "}"
        "QPushButton:hover {"
            "color:black;"
            "background-color:white;"
        "}"
        "QPushButton:pressed {"
            "background-color:white;"
        "}"
    );


    this->show();
}

NavChartWidget::~NavChartWidget()
{

}
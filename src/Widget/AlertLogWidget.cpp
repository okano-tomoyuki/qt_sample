#include "Widget/AlertLog.hpp"
#include <QBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>

using namespace HMI;

AlertLogWidget::AlertLogWidget(QWidget* parent) 
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    QVBoxLayout* vBoxlay = new QVBoxLayout(this);
    vBoxlay->setContentsMargins(0,0,0,0);

    QLabel* title = new QLabel("Alert Log",this);
    title->setObjectName("Title");

    QVBoxLayout* vTableBox = new QVBoxLayout(this);
    QTableWidget* table = new QTableWidget(10,4,this);
    // table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setHorizontalHeaderLabels({"No.","Code","Date & Time","Description"});
    table->verticalHeader()->hide();
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    
    QPushButton* click = new QPushButton("Detail");
    table->setCellWidget(0,0,click);

    vBoxlay->addWidget(title);
    vBoxlay->addWidget(table);
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
            "font-size:14px;"
            "width:20px;"
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
}

AlertLogWidget::~AlertLogWidget()
{

}
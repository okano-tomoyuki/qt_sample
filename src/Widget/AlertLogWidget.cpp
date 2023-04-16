#include "Widget/AlertLog.hpp"
#include <QBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QDateTime>
#include <QLineEdit>
#include <QCoreApplication>

using namespace HMI;

AlertLogWidget::AlertLogWidget(QWidget* parent) 
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    auto vBoxlay = new QVBoxLayout(this);
    vBoxlay->setContentsMargins(0,0,0,0);

    auto title = new QLabel("Alert Log",this);
    title->setObjectName("Title");

    auto vTableBox = new QVBoxLayout(this);

    auto res = findAlert();
    auto table = new QTableWidget(res.size(), res[0].size() + 1,this);
    // table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->horizontalHeader()->setStretchLastSection(true);
    table->setHorizontalHeaderLabels({"","Code","Date & Time","Description"});
    table->verticalHeader()->hide();
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    for (int i=0; i<res.size(); i++){
        auto btn = new QPushButton("Detail");
        btn->setIcon(style()->standardIcon(QStyle::SP_ArrowRight));
        table->setCellWidget(i, 0, btn);
        table->setItem(i, 1, new QTableWidgetItem(res[i][0]));
        table->setItem(i, 2, new QTableWidgetItem(res[i][1]));
        table->setItem(i, 3, new QTableWidgetItem(res[i][2]));
        
    }

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
            "margin:5px;"
            "background-color:white;"
            "color:black;"
            "font-size:14px;"
        "}"
        "QHeaderView:section {"
            "background-color:darkBlue;"
            "color:white;"
            "font-size:18px;"
        "}"
    );
}

AlertLogWidget::~AlertLogWidget()
{

}

QList<QList<QString>> AlertLogWidget::findAlert()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.sql");
    db.open();  
    QSqlQuery query(db);
    query.exec("select code, created_at, description from alert_log;");

    QList<QList<QString>> result;
    while(query.next()){
        result.append(
            {
                query.value(0).toString(), 
                query.value(1).toString(),
                query.value(2).toString()
            }
        );
    }
    db.close();

    return result;
}
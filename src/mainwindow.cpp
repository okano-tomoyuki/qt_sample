#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::darkBlue);
    this->setWindowTitle("Hello World!");
    QPushButton *button = new QPushButton(
        QApplication::translate("childwidget", "Close"), this);
    QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(close()));
    button->move(10, 10);
    button->show();

    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItem("First");
    comboBox->addItem("Second");
    comboBox->addItem("Third");
    comboBox->move(10,50);
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));    


    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setFixedHeight(600);
}

void MainWindow::handleSelectionChanged(int index)
{
    qDebug() << "Item:" << index << "was selected.";
}

MainWindow::~MainWindow()
{
    delete ui;
}


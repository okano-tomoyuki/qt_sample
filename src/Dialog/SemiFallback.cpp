/**
 * @file SemiFallback.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Dialog/SemiFallback.hpp"

#include <QWidget>
#include <QDialog>
#include <QDateTime>
#include <QLineEdit>

using namespace HMI;

SemiFallbackDialog::SemiFallbackDialog(QWidget* parent)
{
    this->setWindowTitle("Dialog");
    this->setMinimumSize(450,300);

    auto dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");
    auto dateTimeValue =  new QLineEdit(dateTime, this);

}
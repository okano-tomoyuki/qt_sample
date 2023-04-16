/**
 * @file AlertLog.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ALERT_LOG_WIDGET_HPP
#define ALERT_LOG_WIDGET_HPP

#include <QWidget>
#include <QString>

namespace HMI
{

/**
 * @brief 
 * 
 */
class AlertLogWidget : public QWidget
{
    Q_OBJECT

public:
    AlertLogWidget(QWidget* parent);
    ~AlertLogWidget();

    QList<QList<QString>> findAlert();
    
};

}
#endif
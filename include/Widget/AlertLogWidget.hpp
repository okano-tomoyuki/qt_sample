/**
 * @file AlertLogWidget.hpp
 * @author okano tomoyuki (okano.development@gmail.com)
 * @brief アラート情報表示用ウィジェット
 * @version 0.1
 * @date 2023-03-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ALERT_LOG_WIDGET_HPP
#define ALERT_LOG_WIDGET_HPP

#include <QWidget>

namespace HumanMachineInterface
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
};

}
#endif
/**
 * @file SemiFallback.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SEMI_FALLBACK_DIALOG_HPP
#define SEMI_FALLBACK_DIALOG_HPP

#include <QDialog>
#include <QWidget>

namespace HMI
{

class SemiFallbackDialog : public QDialog
{
    Q_OBJECT
private:

private slots:

public:
    SemiFallbackDialog(QWidget* parent=nullptr);
};

}

#endif
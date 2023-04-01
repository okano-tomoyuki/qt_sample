/**
 * @file Primary.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PRIMARY_WINDOW_HPP
#define PRIMARY_WINDOW_HPP

#include <QMainWindow>

namespace HMI
{

class PrimaryWindow : public QMainWindow
{
    Q_OBJECT

public:
    PrimaryWindow();
    ~PrimaryWindow();

private slots:

    /**
     * @brief ドロップダウンした値の取得 
     * 
     * @param index 
     */
    void handleSelectionChanged(int index);

};

}
#endif

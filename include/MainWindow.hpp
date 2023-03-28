/**
 * @file MainWindow.hpp
 * @author okano tomoyuki (okano.development@gmail.com)
 * @brief メインウィンドウ
 * @version 0.1
 * @date 2023-03-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

namespace HumanMachineInterface
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

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

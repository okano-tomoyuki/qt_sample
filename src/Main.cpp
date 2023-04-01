#include "Window/Primary.hpp"

#include <QApplication>

using namespace HMI;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrimaryWindow w;
    return a.exec();
}

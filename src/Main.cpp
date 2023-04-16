#include "Window/Primary.hpp"

#include <QApplication>

using namespace HMI;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PrimaryWindow window;
    return app.exec();
}

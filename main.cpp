#include "rustspawn.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    RustSpawn *app = RustSpawn::instance(argc, argv);

    app->setup();

    return app->exec();
}

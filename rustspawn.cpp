#include "rustspawn.h"


RustSpawn* RustSpawn::m_instance = 0;


RustSpawn::RustSpawn(int argc, char **argv)
    : QApplication(argc, argv)
{
    this->argc = argc;
    this->argv = new QStringList();
    for (int i = 0; i < argc; ++i) {
        this->argv->append(argv[i]);
    }
}

void RustSpawn::newFileAction()
{
    this->mainWin->newTextEditorTab();
}

void RustSpawn::requestCloseTab(int index)
{
    //check and save first
    this->mainWin->closeTab(index);
}

void RustSpawn::setup()
{
    this->mainWin = new MainWindow();
    this->mainWin->show();

    connect(mainWin, SIGNAL(newFileAction()), this, SLOT(newFileAction()));
    connect(mainWin, SIGNAL(tabCloseRequested(int)), this, SLOT(requestCloseTab(int)));
}

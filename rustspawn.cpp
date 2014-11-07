#include "rustspawn.h"
#include <QFileDialog>

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

void RustSpawn::openFileAction()
{
    QFileDialog *dialog = new QFileDialog(this->mainWin,tr("File Open ..."));

    dialog->setAcceptMode(QFileDialog::AcceptOpen);
    dialog->setFileMode(QFileDialog::ExistingFile);

    if (dialog->exec()) {
        this->mainWin->openFile(dialog->selectedFiles().at(0));
    }
}

void RustSpawn::requestCloseTab(int index)
{
    //check and save first
    this->mainWin->closeTab(index);
}

void RustSpawn::setup()
{
    this->_textEditorBaseUrl = new QString( QApplication::applicationDirPath() + "/../html/editors/texteditor.html");

    this->mainWin = new MainWindow();
    this->mainWin->show();

    connect(mainWin, SIGNAL(newFileAction()), this, SLOT(newFileAction()));
    connect(mainWin, SIGNAL(tabCloseRequested(int)), this, SLOT(requestCloseTab(int)));
    connect(mainWin, SIGNAL(openFileAction()), this, SLOT(openFileAction()));
}

QString *RustSpawn::textEditorBaseUrl()
{
    return this->_textEditorBaseUrl;
}

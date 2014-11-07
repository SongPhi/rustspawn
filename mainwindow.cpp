#include "mainwindow.h"
#include "tabs/editors/texteditortab.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file(":/res/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromUtf8(file.readAll());

    qApp->setStyleSheet(styleSheet);
    ui->editorsTabWidget->clear();
    this->newTextEditorTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_editorsTabWidget_tabBarDoubleClicked(int )
{
    emit newFileAction();
}

void MainWindow::on_action_Quit_triggered()
{
    qApp->quit();
}

void MainWindow::on_action_New_triggered()
{
    emit newFileAction();
}

void MainWindow::newTextEditorTab()
{
    TextEditorTab *newTextEditor = new TextEditorTab( this->ui->editorsTabWidget  );
    this->ui->editorsTabWidget->addTab(newTextEditor, tr("Untitled"));
    this->ui->editorsTabWidget->setCurrentWidget(newTextEditor);
}

void MainWindow::closeTab(int index)
{
    this->ui->editorsTabWidget->widget(index)->close();
    this->ui->editorsTabWidget->removeTab(index);
    if (this->ui->editorsTabWidget->count()==0)
        this->newTextEditorTab();
}

bool MainWindow::openFile(QString filename)
{
    TextEditorTab *newTextEditor = new TextEditorTab( this->ui->editorsTabWidget, filename );
    this->ui->editorsTabWidget->addTab(newTextEditor, tr("Untitled"));
    this->ui->editorsTabWidget->setCurrentWidget(newTextEditor);
}

void MainWindow::on_editorsTabWidget_tabCloseRequested(int index)
{
    emit tabCloseRequested(index);
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionClose_tab_triggered()
{
    emit tabCloseRequested(this->ui->editorsTabWidget->currentIndex());
}

void MainWindow::on_action_Open_triggered()
{
    emit openFileAction();
}

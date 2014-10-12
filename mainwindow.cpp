#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file("res/style.qss");
    //QFile file(":/res/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromUtf8(file.readAll());

    qApp->setStyleSheet(styleSheet);

    ui->webView->setUrl(QUrl::fromLocalFile(QDir::currentPath()+"/html/editors/texteditor.html"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_editorsTabWidget_tabBarDoubleClicked(int )
{

}

void MainWindow::on_action_Quit_triggered()
{
    qApp->quit();
}

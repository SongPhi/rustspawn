#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_editorsTabWidget_tabBarDoubleClicked(int index);


    void on_action_Quit_triggered();

    void on_action_New_triggered();

    void on_editorsTabWidget_tabCloseRequested(int index);

    void on_actionAbout_Qt_triggered();

    void on_actionClose_tab_triggered();

    void on_action_Open_triggered();

private:
    Ui::MainWindow *ui;

signals:
    void newFileAction();
    void openFileAction();
    void tabCloseRequested(int index);

public slots:
    void newTextEditorTab();
    void closeTab(int index);
    bool openFile(QString filename);
};

#endif // MAINWINDOW_H

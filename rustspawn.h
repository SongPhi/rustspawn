#ifndef RUSTSPAWN_H
#define RUSTSPAWN_H

#include <QApplication>
#include <QStringList>
#include "mainwindow.h"
#include <QMutex>

class RustSpawn : public QApplication
{
    Q_OBJECT
public:
    static RustSpawn* instance(int argc = 0, char **argv = 0) {
        static QMutex mutex;
        if (!m_instance)
        {
            mutex.lock();

            if (!m_instance)
                 m_instance = new RustSpawn(argc, argv);

            mutex.unlock();
        }

        return m_instance;
    }
    void setup();


protected:
    RustSpawn(int argc = 0, char **argv = 0);

private:
    static RustSpawn *m_instance;

    int argc;
    QStringList *argv;
    MainWindow *mainWin;

signals:

public slots:
    void newFileAction();
    void requestCloseTab(int index);

};

#endif // RUSTSPAWN_H

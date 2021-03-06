#ifndef THREADLOOP_H
#define THREADLOOP_H

#include <QObject>
#include <QThread>
#include <QFileSystemWatcher>
#include "mainwindow.h"
#include "socket.h"

class threadLoop : public QThread
{
    Q_OBJECT
public:
    threadLoop(Mainwindow *window);
    threadLoop();
    ~threadLoop();

signals:
    void        labelValueChanged(QString);
    void        browserValueChanged(QString);
    void        listChanged();

public slots:
    void        stopOnQuit();
    void        changeListDone(int value);
    void        ChangeDirectory(QString dir);        /* 目录改变，包括：
                                                      * 文件增加
                                                      * 目录增加,修改
                                                      * 文件、目录删除的情况未考虑
                                                      */
protected:
    void        run();

private:
    Mainwindow  *w;
    QFileSystemWatcher *watcher ;
    Socket      *thread_s;

    bool        isChangeListDone;
    bool        isDirChanged ;
};

#endif // THREADLOOP_H

﻿#ifndef QTODOMANAGER_H
#define QTODOMANAGER_H

#include "uiframe/qpurecolorbutton.h"
#include "todo/qtodocontent.h"

#include <QWidget>
#include <QStackedWidget>
#include <QLabel>



class QTodoManager : public QWidget
{
    Q_OBJECT
public:

    enum    TaskManager{ ALLTask,ToDoTask,DoneTask};
    explicit QTodoManager(QWidget *parent = 0);

    void                initUI();

signals:

private:

    void                initUI2();
public slots:
    void                stack_change(int i);
private:

    QStackedWidget      *m_stacked;
    QPureColorButton    *m_allcando;
    QPureColorButton    *m_todobtn;
    QPureColorButton    *m_donebtn;
    QLabel              *m_lbtip;
public:
    QToDoContent             *m_wid_alldo;
    QToDoContent             *m_wid_todo;
    QToDoContent             *m_wid_done;

};

#endif // QTODOMANAGER_H

#ifndef MY_PROGRESS_H
#define MY_PROGRESS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"


namespace Ui {
class my_progress ;
}


class my_progress : public QMainWindow
{
    Q_OBJECT
public:

    explicit my_progress(QWidget *parent = nullptr);
    ~my_progress();

signals:

public slots:

private:

    Ui::FitFriend *ui;
};

#endif // MY_PROGRESS_H



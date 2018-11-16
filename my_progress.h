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

    explicit my_progress(QWidget *parent = nullptr, FitFriend* i_parent_window = nullptr);
    ~my_progress();

signals:

public slots:

    //exits my_progress and returns to the main menu
    void return_to_main();

private:

    Ui::FitFriend *ui;
    FitFriend* parent_window;
};

#endif // MY_PROGRESS_H

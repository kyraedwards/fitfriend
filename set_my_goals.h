#ifndef SET_MY_GOALS_H
#define SET_MY_GOALS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"
#include <QVBoxLayout>
#include <QPushButton>

namespace Ui {
class set_my_goals ;
}

class set_my_goals : public QMainWindow
{
    Q_OBJECT

public:
    explicit set_my_goals(QWidget *parent = nullptr, FitFriend* i_parent_window = nullptr);
    ~set_my_goals();

signals:

public slots:

    //exits set my goals window and returns to main menu of app
    void return_to_main();



private:
    Ui::FitFriend *ui;
    FitFriend* parent_window;
};

#endif // SET_MY_GOALS_H

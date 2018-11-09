#ifndef SET_MY_GOALS_H
#define SET_MY_GOALS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"

namespace Ui {
class previous_workouts ;
}

class set_my_goals : public QMainWindow
{
    Q_OBJECT

public:
    explicit set_my_goals(QWidget *parent = nullptr);
    ~set_my_goals();

signals:

public slots:

private:
    Ui::FitFriend *ui;
};

#endif // SET_MY_GOALS_H

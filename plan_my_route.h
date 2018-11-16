#ifndef PLAN_MY_ROUTE_H
#define PLAN_MY_ROUTE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"
#include <QVBoxLayout>
#include <QPushButton>

namespace Ui {
class plan_my_route ;
}

class plan_my_route : public QMainWindow
{
    Q_OBJECT

public:

    explicit plan_my_route(QWidget *parent = nullptr, FitFriend* i_parent_window = nullptr);
    ~plan_my_route();

signals:


public slots:

    //exits window and returns to main menu of app
    void return_to_main();

private:
    Ui::FitFriend *ui;
    FitFriend* parent_window;

};

#endif // PLAN_MY_ROUTE_H

#ifndef PLAN_MY_ROUTE_H
#define PLAN_MY_ROUTE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"

namespace Ui {
class plan_my_route ;
}

class plan_my_route : public QMainWindow
{
    Q_OBJECT

public:

    explicit plan_my_route(QWidget *parent = nullptr);
    ~plan_my_route();

signals:

public slots:

private:
    Ui::FitFriend *ui;

};

#endif // PLAN_MY_ROUTE_H


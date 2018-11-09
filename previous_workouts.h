#ifndef PREVIOUS_WORKOUTS_H
#define PREVIOUS_WORKOUTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"

namespace Ui {
class previous_workouts ;
}

class previous_workouts : public QMainWindow
{
    Q_OBJECT

public:
    explicit previous_workouts(QWidget *parent = nullptr);
    ~previous_workouts();

signals:

public slots:

private:
    Ui::FitFriend *ui;

};

#endif // PREVIOUS_WORKOUTS_H

#ifndef PREVIOUS_WORKOUTS_H
#define PREVIOUS_WORKOUTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class previous_workouts ;
}

class previous_workouts : public QMainWindow
{
    Q_OBJECT

public:
    explicit previous_workouts(QWidget *parent = nullptr, FitFriend* i_parent_window = nullptr);
    ~previous_workouts();

signals:

public slots:

    //exits window and returns to main menu of app
    void return_to_main();

private:
    Ui::FitFriend *ui;
    FitFriend* parent_window;

};

#endif // PREVIOUS_WORKOUTS_H

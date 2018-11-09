#include "previous_workouts.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>

previous_workouts::previous_workouts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{

    QLabel* intro_label = new QLabel("Coming soon");
    intro_label->show();

}

previous_workouts::~previous_workouts(){
    delete ui;
}



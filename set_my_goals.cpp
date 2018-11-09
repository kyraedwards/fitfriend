#include "set_my_goals.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>

set_my_goals::set_my_goals(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{
    QLabel* intro_label = new QLabel("Coming soon");
    intro_label->show();
}

set_my_goals::~set_my_goals(){
    delete ui;
}


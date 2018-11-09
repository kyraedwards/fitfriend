#include "plan_my_route.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>

plan_my_route::plan_my_route(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{
    ui->setupUi(this);
    QLabel* intro_label = new QLabel("Coming soon");
    intro_label->show();
}


plan_my_route::~plan_my_route()
{
    delete ui;
}



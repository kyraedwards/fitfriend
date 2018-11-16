#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "input_data_window.h"
#include "advice_from_kyra.h"
#include "my_progress.h"
#include "previous_workouts.h"
#include "plan_my_route.h"
#include "set_my_goals.h"



FitFriend::FitFriend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{
    ui->setupUi(this);


QPixmap background(":/runner_road");
background= background.scaled(this->size(), Qt::IgnoreAspectRatio);

QPalette palette;
palette.setBrush(QPalette::Background, background);
this->setPalette(palette);

//background music
QMediaPlayer* music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/music.mp3"));

music->play();


}


FitFriend::~FitFriend()
{
    delete ui;
}


void FitFriend::open_input_data() {
    this->hide();
    input_data_window* input_data_ptr = new input_data_window(nullptr, this);
}


void FitFriend::open_advice_from_kyra(){
    this->hide();
    advice_from_kyra* advice_from_kyra_ptr = new advice_from_kyra(nullptr, this);
}


void FitFriend::open_my_progress(){
    this->hide();
    my_progress* my_progress_ptr = new my_progress(nullptr, this);
}


void FitFriend::open_previous_workouts(){
    this->hide();
    previous_workouts* previous_workouts_ptr = new previous_workouts(nullptr, this);
}

void FitFriend::open_plan_my_route(){
    this->hide();
    plan_my_route* plan_my_route_ptr = new plan_my_route(nullptr, this);
}

void FitFriend::open_set_my_goals(){
    this->hide();
    set_my_goals* set_my_goals_ptr = new set_my_goals(nullptr, this);
}


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
//music->setMedia(QUrl("qrc:/music"));
music->setMedia(QUrl::fromLocalFile("qrc:/../../Music/iTunes/iTunes Media/Music/Talk Talk/Unknown Album/It's My Life.mp3"));

music->play();


}


FitFriend::~FitFriend()
{
    delete ui;
}


void FitFriend::open_input_data() {
    input_data_window* input_data_ptr = new input_data_window;
}


void FitFriend::open_advice_from_kyra(){
    advice_from_kyra* advice_from_kyra_ptr = new advice_from_kyra;
}


void FitFriend::open_my_progress(){
    my_progress* my_progress_ptr = new my_progress;
}


void FitFriend::open_previous_workouts(){
    previous_workouts* previous_workouts_ptr = new previous_workouts;
}

void FitFriend::open_plan_my_route(){
    plan_my_route* plan_my_route_ptr = new plan_my_route;
}

void FitFriend::open_set_my_goals(){
    set_my_goals* set_my_goals_ptr = new set_my_goals;
}





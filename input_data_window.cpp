#include "fitfriend.h"
#include "ui_fitfriend.h"
#include "input_data_window.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

input_data_window::input_data_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{
    ui->setupUi(this);

    //introductory label
    QLabel* intro_label = new QLabel("Select what you wish to input.");


    //buttons to add different types of fitness data
    QPushButton* add_meal_button = new QPushButton("Meal");
    QPushButton* add_workout_button = new QPushButton("Workout");
    QPushButton* add_weight_button = new QPushButton("Weight");
    QPushButton* add_run_button = new QPushButton("Run");


    //connect 4 add buttons to their respective SLOTS
    QObject::connect(add_meal_button, SIGNAL(pressed()), this, SLOT(add_meal()));
    QObject::connect(add_workout_button, SIGNAL(pressed()), this, SLOT(add_workout()));
    QObject::connect(add_weight_button, SIGNAL(pressed()), this, SLOT(add_weight()));
    QObject::connect(add_run_button, SIGNAL(pressed()), this, SLOT(add_run()));


    //layout to structure the intro label and buttons to add fitness data
    QVBoxLayout* label_and_buttons = new QVBoxLayout;
    label_and_buttons->addWidget(intro_label);
    label_and_buttons->addWidget(add_meal_button);
    label_and_buttons->addWidget(add_workout_button);
    label_and_buttons->addWidget(add_weight_button);
    label_and_buttons->addWidget(add_run_button);


    //hosts entire data input window
    QWidget* wid = new QWidget;
    wid->setLayout(label_and_buttons);
    setCentralWidget(wid);
    this->show();

}


input_data_window::~input_data_window()
{
    delete ui;
}




void input_data_window::add_workout(){

    QLabel* workout= new QLabel("Add yout workout");
    workout->show();

};

void input_data_window::add_meal(){
   QLabel* meal= new QLabel("Add yout meal");
   meal->show();
}

void input_data_window::add_run(){
    QLabel* run= new QLabel("Add yout run");
    run->show();
}

void input_data_window::add_weight(){
    QLabel* weight= new QLabel("Add yout weight");
    weight->show();
}

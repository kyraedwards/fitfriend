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


    QLabel* workout= new QLabel("Congrats on finishing your workout! Add the workout info below");
    QLabel* time_and_date = new QLabel("What were the time and date of this workout");
    QLabel* time_of_workout = new QLabel("How long was your workout");

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(workout);
    layout->addWidget(time_and_date);
    layout->addWidget(time_of_workout);

    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    this->setCentralWidget(wid);

};

void input_data_window::add_meal(){
   //this layout will hold the question labels and the answer input boxes
   QVBoxLayout* layout = new QVBoxLayout;


   QLabel* meal= new QLabel("Add yout meal below");
   //need corresponding input text boxes and such
   QLabel* time_and_date = new QLabel("What were the time and date of this meal");
   QLabel* name_of_food = new QLabel("What food did you eat");
   QLabel* calories_of_food = new QLabel("How many calories were in the food");
   QLabel* fat_of_food = new QLabel("How many grams of fat were in the food");
   QLabel* protein_of_food = new QLabel("How many grams of protein were in the food");

   //need corresponding input text boxes
   QLabel* name_of_drink = new QLabel("What was your drink");
   QLabel* calories_of_drink = new QLabel("How many calories were in the drink");
   QLabel* fat_of_drink = new QLabel("How many grams of fat were in the drink");
   QLabel* protein_of_drink = new QLabel("How many grams of protein were in the drink");

   layout->addWidget(meal);
   layout->addWidget(time_and_date);
   layout->addWidget(name_of_food);
   layout->addWidget(calories_of_food);
   layout->addWidget(fat_of_food);
   layout->addWidget(protein_of_food);
   layout->addWidget(name_of_drink);
   layout->addWidget(calories_of_drink);
   layout->addWidget(fat_of_drink);
   layout->addWidget(protein_of_drink);

   QWidget* wid = new QWidget;
   wid->setLayout(layout);
   this->setCentralWidget(wid);
}

void input_data_window::add_run(){
    QLabel* run= new QLabel("Add yout run");
    run->show();
}

void input_data_window::add_weight(){
    QLabel* weight= new QLabel("Add yout weight");
    weight->show();
}

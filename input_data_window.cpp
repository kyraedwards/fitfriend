#include "fitfriend.h"
#include "ui_fitfriend.h"
#include "input_data_window.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>

input_data_window::input_data_window(QWidget *parent, FitFriend* i_parent_window) :
    QMainWindow(parent), parent_window(i_parent_window),
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

void input_data_window::return_to_main(){
    this->close();
    parent_window->show();
}


input_data_window::~input_data_window()
{
    delete ui;
}



void input_data_window::add_workout(){


    QLabel* workout= new QLabel("Congrats on finishing your workout! Add the workout info below");
    QLabel* time_and_date = new QLabel("What were the time and date of this workout");
    QLabel* time_of_workout = new QLabel("How long was your workout");
    QPushButton* submit_run = new QPushButton("Submit workout");
    QObject::connect(submit_run, SIGNAL(clicked()), this, SLOT(return_to_main()));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(workout);
    layout->addWidget(time_and_date);
    layout->addWidget(time_of_workout);
    layout->addWidget(submit_run);



    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    this->setCentralWidget(wid);

};

void input_data_window::add_meal(){
   //this layout will hold the question labels and the answer input boxes
   QVBoxLayout* layout = new QVBoxLayout;

   QLabel* meal= new QLabel("Add yout meal below");
   QLabel* time_and_date = new QLabel("What were the time and date of this meal?");

   QLabel* name_of_food = new QLabel("What food did you eat?");
   //need text box
   QLineEdit* food_name_input_box = new QLineEdit("Type name of food here");


   QLabel* calories_in_food = new QLabel("How many calories were in the food?");
   QSpinBox *calories_in_food_spin_box = new QSpinBox;
   calories_in_food_spin_box->setRange(0, 2000);
   calories_in_food_spin_box->setValue(500);

   QLabel* fat_in_food = new QLabel("How many grams of fat were in the food?");
   QSpinBox *fat_in_food_spin_box = new QSpinBox;
   fat_in_food_spin_box->setRange(0, 100);
   fat_in_food_spin_box->setValue(5);

   QLabel* protein_in_food = new QLabel("How many grams of protein were in the food?");
   QSpinBox *protein_in_food_spin_box = new QSpinBox;
   protein_in_food_spin_box->setRange(0, 100);
   protein_in_food_spin_box->setValue(5);

   //need corresponding input text boxes
   QLabel* name_of_drink = new QLabel("What was your drink?");
   QLineEdit* drink_name_input_box = new QLineEdit("Type name of drink here");


   QLabel* calories_in_drink = new QLabel("How many calories were in the drink?");
   QSpinBox *calories_in_drink_spin_box = new QSpinBox;
   calories_in_drink_spin_box->setRange(0, 100);
   calories_in_drink_spin_box->setValue(200);


   QLabel* fat_in_drink = new QLabel("How many grams of fat were in the drink?");
   QSpinBox *fat_in_drink_spin_box = new QSpinBox;
   fat_in_drink_spin_box->setRange(0, 100);
   fat_in_drink_spin_box->setValue(0);


   QLabel* protein_in_drink = new QLabel("How many grams of protein were in the drink?");
   QSpinBox *protein_in_drink_spin_box = new QSpinBox;
   protein_in_drink_spin_box->setRange(0, 100);
   protein_in_drink_spin_box->setValue(0);


   QPushButton* submit = new QPushButton("Submit meal");
   QObject::connect(submit, SIGNAL(clicked()), this, SLOT(return_to_main()));

   layout->addWidget(meal);
   layout->addWidget(time_and_date);
   layout->addWidget(name_of_food);
   layout->addWidget(food_name_input_box);
   layout->addWidget(calories_in_food);
   layout->addWidget(calories_in_food_spin_box);
   layout->addWidget(fat_in_food);
   layout->addWidget(fat_in_food_spin_box);
   layout->addWidget(protein_in_food);
   layout->addWidget(protein_in_food_spin_box);
   layout->addWidget(name_of_drink);
   layout->addWidget(drink_name_input_box);
   layout->addWidget(calories_in_drink);
   layout->addWidget(calories_in_drink_spin_box);
   layout->addWidget(fat_in_drink);
   layout->addWidget(fat_in_drink_spin_box);
   layout->addWidget(protein_in_drink);
   layout->addWidget(protein_in_drink_spin_box);
   layout->addWidget(submit);

   QWidget* wid = new QWidget;
   wid->setLayout(layout);
   this->setCentralWidget(wid);
}

void input_data_window::add_run(){
    QVBoxLayout* buttons= new  QVBoxLayout;
    QLabel* add_run= new QLabel("Add yout run");
    QPushButton* submit= new QPushButton("Submit run");
    QObject::connect(submit, SIGNAL(clicked()), this, SLOT(return_to_main()));

    buttons->addWidget(add_run);
    buttons->addWidget(submit);

    //hosts entire data input window
    QWidget* wid = new QWidget;
    wid->setLayout(buttons);
    setCentralWidget(wid);

}

void input_data_window::add_weight(){
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel* weight= new QLabel("Add yout weight");
    QPushButton* submit= new QPushButton("Submit weight");
    QObject::connect(submit, SIGNAL(clicked()), this, SLOT(return_to_main()));

    layout->addWidget(weight);
    layout->addWidget(submit);


    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    this->setCentralWidget(wid);
}

#include "previous_workouts.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>

previous_workouts::previous_workouts(QWidget *parent, FitFriend* i_parent_window) :
    QMainWindow(parent), parent_window(i_parent_window),
    ui(new Ui::FitFriend)
{

    QLabel* intro_label = new QLabel("Coming soon");
    QPushButton* return_to_main = new QPushButton("Return to main");
    QObject::connect(return_to_main, SIGNAL(clicked()), this, SLOT(return_to_main()));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(intro_label);
    layout->addWidget(return_to_main);

    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    setCentralWidget(wid);
    this->show();
}

void previous_workouts::return_to_main(){
    this->close();
    parent_window->show();
}


previous_workouts::~previous_workouts(){
    delete ui;
}

#include "set_my_goals.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>

set_my_goals::set_my_goals(QWidget *parent, FitFriend* i_parent_window) :
    QMainWindow(parent), parent_window(i_parent_window),
    ui(new Ui::FitFriend)
{
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel* intro_label = new QLabel("Coming soon");
    QPushButton* return_to_main = new QPushButton("Return to main menu");

    QObject::connect(return_to_main, SIGNAL(clicked()), this, SLOT(return_to_main()));

    layout->addWidget(intro_label);
    layout->addWidget(return_to_main);

    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    setCentralWidget(wid);
    this->show();
}

void set_my_goals::return_to_main(){
    this->close();
    parent_window->show();
}


set_my_goals::~set_my_goals(){
    delete ui;
}

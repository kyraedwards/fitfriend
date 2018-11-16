#include "plan_my_route.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>

plan_my_route::plan_my_route(QWidget *parent, FitFriend* i_parent_window) :
    QMainWindow(parent), parent_window(i_parent_window),
    ui(new Ui::FitFriend)
{
    ui->setupUi(this);
    QLabel* intro_label = new QLabel("Coming soon");
    QPushButton* return_to_main_button = new QPushButton("Return to main");
    QObject::connect(return_to_main_button, SIGNAL(clicked()), this, SLOT(return_to_main()));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(intro_label);
    layout->addWidget(return_to_main_button);

    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    setCentralWidget(wid);
    this->show();

}


void plan_my_route::return_to_main(){
    this->close();
    parent_window->show();
}


plan_my_route::~plan_my_route()
{
    delete ui;
}

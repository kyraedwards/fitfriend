#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

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

}



FitFriend::~FitFriend()
{
    delete ui;
}


void FitFriend::input_data(){

    FitFriend w;
    w.show();


    QLabel* welcome = new QLabel("Hello! What do you want to input?");
    QPushButton* button = new QPushButton("Push me");
    QWidget* wid = new QWidget;
    QVBoxLayout* layout= new QVBoxLayout;
    //welcome->show();

    wid->setLayout(layout);
    layout->addWidget(welcome);
    layout->addWidget(button);

    wid->show();

    QObject::connect(button, SIGNAL(clicked()), &w, SLOT(Add_Workout()) );




    //why dont these lines of code work?
//    w.setCentralWidget(wid);

   // w.setLayout(layout);

   //  w.show();



}

void FitFriend::add_workout(){
    QLabel* workout= new QLabel("Add yout workout");
    workout->show();

};

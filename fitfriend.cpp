#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>


FitFriend::FitFriend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{
    ui->setupUi(this);



QPixmap background(":/runners");
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
    //FitFriend input;
    //input.show();
    QLabel* welcome= new QLabel("Hey! What do you want to input?");
    QWidget* wid = new QWidget;
    QVBoxLayout* layout= new QVBoxLayout;

    layout->addWidget(welcome);
    wid->setLayout(layout);
    //input.setCentralWidget(wid);

    wid->show();
   welcome->show();


};

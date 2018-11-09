#include "my_progress.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>


my_progress::my_progress(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{

    ui->setupUi(this);

    QLabel* intro_label = new QLabel("Coming soon");
    intro_label->show();
}


my_progress::~my_progress()
{
    delete ui;
}



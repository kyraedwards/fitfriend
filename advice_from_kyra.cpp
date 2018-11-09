#include "advice_from_kyra.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>

advice_from_kyra::advice_from_kyra(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)

{
    ui->setupUi(this);


    QLabel* intro_label = new QLabel("Coming soon");
    intro_label->show();
}








advice_from_kyra::~advice_from_kyra()
{
    delete ui;
}

#include "advice_from_kyra.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>
#include <QHBoxLayout>


advice_from_kyra::advice_from_kyra(QWidget *parent, FitFriend* i_parent_window) :
    QMainWindow(parent), parent_window(i_parent_window),
    ui(new Ui::FitFriend)

{
    ui->setupUi(this);

    QHBoxLayout* layout= new QHBoxLayout;

    QWidget* wid= new QWidget;
    QLabel* intro_label = new QLabel("Coming soon");
    layout->addWidget(intro_label);

    QPixmap pic_of_kyra(":/Kyra");
    QLabel* pic_label= new QLabel;

    pic_label->setPixmap(pic_of_kyra);
    layout->addWidget(pic_label);
    pic_label->setScaledContents(true);
    pic_label->setFixedSize(300, 400);

    QPushButton* return_to_main = new QPushButton("Return to main");
    QObject::connect(return_to_main, SIGNAL(clicked()), this, SLOT(return_to_main()));
    layout->addWidget(return_to_main);
    wid->setLayout(layout);
    this->setCentralWidget(wid);
    this->show();

}

//exits the input data window and returns to the apps main window
void advice_from_kyra::return_to_main(){
    this->close();
    parent_window->show();
}


advice_from_kyra::~advice_from_kyra()
{
    delete ui;
}

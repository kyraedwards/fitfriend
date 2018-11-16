#include "my_progress.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>


my_progress::my_progress(QWidget *parent, FitFriend* i_parent_window) :
    QMainWindow(parent), parent_window(i_parent_window),
    ui(new Ui::FitFriend)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout;

    QLabel* graph_label = new QLabel("Graph of progress made coming soon");
    QLabel* intro_label = new QLabel("Here is all the progress you've made!");
    QPushButton* exit = new QPushButton("Exit");

    layout->addWidget(intro_label);
    layout->addWidget(graph_label);
    layout->addWidget(exit);

    QObject::connect(exit, SIGNAL(clicked()), this, SLOT(return_to_main()));


    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    setCentralWidget(wid);
    this->show();
}


my_progress::~my_progress()
{
    delete ui;
}

void my_progress::return_to_main(){
    this->close();
    parent_window->show();
}

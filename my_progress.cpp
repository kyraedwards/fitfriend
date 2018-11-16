#include "my_progress.h"
#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>
#include <QVBoxLayout>


my_progress::my_progress(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitFriend)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout;

    QLabel* graph_label = new QLabel("Graph of progress made coming soon");
    QLabel* intro_label = new QLabel("Here is all the progress you've made!");

    layout->addWidget(intro_label);
    layout->addWidget(graph_label);

    QWidget* wid = new QWidget;
    wid->setLayout(layout);
    setCentralWidget(wid);
    this->show();
}


my_progress::~my_progress()
{
    delete ui;
}

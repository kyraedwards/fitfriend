#include "fitfriend.h"
#include "ui_fitfriend.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "input_data_window.h"
#include "advice_from_kyra.h"




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

//background music
QMediaPlayer* music = new QMediaPlayer();
//music->setMedia(QUrl("qrc:/music"));
music->setMedia(QUrl::fromLocalFile("qrc:/../../../../../Downloads/Rocky Theme Tune.mp3"));

music->play();


}



FitFriend::~FitFriend()
{
    delete ui;
}


void FitFriend::open_input_data() {

    input_data_window* window= new input_data_window;
}


void FitFriend::open_advice_from_kyra(){

    advice_from_kyra* advice = new advice_from_kyra;

}


#include "fitfriend.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FitFriend w;
    QWidget *wid = new QWidget;
    w.show();


    QVBoxLayout* overall_layout= new QVBoxLayout;
    QLabel* Intro = new QLabel("Hi, I'm your Fit Friend");
    QFont intro_font("Helvetica", QFont::Bold,  18);
       Intro->setFont(intro_font);
    overall_layout->addWidget(Intro);
    overall_layout->setAlignment(Intro, Qt::AlignCenter);


    //will hold the options on the left side of the main menu
    QVBoxLayout* options = new QVBoxLayout;
    QVector<QPushButton*> main_menu;
    main_menu.push_back(new QPushButton("Input Data"));
    main_menu.push_back(new QPushButton("My Progress"));
    main_menu.push_back(new QPushButton("Previous Workouts"));
    main_menu.push_back(new QPushButton("Advice From Kyra"));
    main_menu.push_back(new QPushButton("Plan My Route"));
    main_menu.push_back(new QPushButton("Set My Goals"));



    for(size_t i=0; i < main_menu.length(); ++i){
        options->addWidget(main_menu[i]);
    }


    //input menu
    QObject::connect(main_menu[0], SIGNAL(clicked()), &w, SLOT(FitFriend::input_data()));

               QPixmap runners(":/../../../../../Downloads/download.jpeg");
               QLabel* picture= new QLabel;
              picture->setPixmap(runners);

    //will layout the buttons on the left side of the main menu and the photo on the right side of the main menu
    QHBoxLayout* options_and_picture = new QHBoxLayout;
    options_and_picture->addLayout(options);
    overall_layout->addLayout(options_and_picture);

    options_and_picture->addWidget(picture);



    QPushButton* quit = new QPushButton("QUIT");
    overall_layout->addWidget(quit);
    overall_layout->setAlignment(quit, Qt::AlignRight);
    QObject::connect(quit, SIGNAL(clicked()), &a, SLOT(quit()) );



    wid->setLayout(overall_layout);
    w.setCentralWidget(wid);



    return a.exec();
}


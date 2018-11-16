#ifndef ADVICE_FROM_KYRA_H
#define ADVICE_FROM_KYRA_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"
#include <QPushButton>

namespace Ui {
class advice_from_kyra ;
}

class advice_from_kyra: public QMainWindow


{
    Q_OBJECT


public:

    explicit advice_from_kyra(QWidget *parent = nullptr, FitFriend* i_parent_window = nullptr);
    ~advice_from_kyra();


signals:

public slots:

    //exits the window and returns to the app's main window
    void return_to_main();

private:
    Ui::FitFriend *ui;
    FitFriend* parent_window;


};

#endif // ADVICE_FROM_KYRA_H


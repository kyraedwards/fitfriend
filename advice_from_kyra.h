#ifndef ADVICE_FROM_KYRA_H
#define ADVICE_FROM_KYRA_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "fitfriend.h"


namespace Ui {
class advice_from_kyra ;
}

class advice_from_kyra: public QMainWindow


{
    Q_OBJECT


public:

    explicit advice_from_kyra(QWidget *parent = nullptr);
    ~advice_from_kyra();


signals:


public slots:

private:
    Ui::FitFriend *ui;






};

#endif // ADVICE_FROM_KYRA_H

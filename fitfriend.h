#ifndef FITFRIEND_H
#define FITFRIEND_H

#include <QMainWindow>

namespace Ui {
class FitFriend;
}

class FitFriend : public QMainWindow
{
    Q_OBJECT


public:
    explicit FitFriend(QWidget *parent = nullptr);
    ~FitFriend();


public slots:
    void input_data();



private:
    Ui::FitFriend *ui;
};

#endif // FITFRIEND_H

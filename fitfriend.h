#ifndef FITFRIEND_H
#define FITFRIEND_H

#include <QMainWindow>

namespace Ui {
class FitFriend;
}

class FitFriend : public QMainWindow
{
    Q_OBJECT


public slots:

      //opens window that gives user the options of different types of fitness data to input
      void input_data();

//    //opens window to allow user to input workout
 //  void add_workout();

//    //opens window to allow user to input meal
      //void add_meal();

//    //opens window to allow user to input run
//    void add_run();

//    //opens window to allow user to input weight
//    void add_weight();


public:
    explicit FitFriend(QWidget *parent = nullptr);
    ~FitFriend();




private:
    Ui::FitFriend *ui;
};

#endif // FITFRIEND_H

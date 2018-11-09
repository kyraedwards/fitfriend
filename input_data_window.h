#ifndef INPUT_DATA_WINDOW_H
#define INPUT_DATA_WINDOW_H


#include <QMainWindow>
#include <fitfriend.h>

namespace Ui {
class input_data_window;
}

class input_data_window : public QMainWindow
{
    Q_OBJECT


public slots:

    //opens window to allow user to input workout
    void add_workout();

    //opens window to allow user to input meal
    void add_meal();

    //opens window to allow user to input run
    void add_run();

    //opens window to allow user to input weight
    void add_weight();


public:
    explicit input_data_window(QWidget *parent = nullptr);
    ~input_data_window();




private:
    Ui::FitFriend *ui;
};


#endif // INPUT_DATA_WINDOW_H

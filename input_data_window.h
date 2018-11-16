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

public:
    explicit input_data_window(QWidget *parent = nullptr, FitFriend* i_parent_window = nullptr);
    ~input_data_window();


public slots:

    //exits the input data window and returns to the apps main window
    void return_to_main();

    //opens window to allow user to input workout
    void add_workout();

    //opens window to allow user to input meal
    void add_meal();

    //opens window to allow user to input run
    void add_run();

    //opens window to allow user to input weight
    void add_weight();


private:
    Ui::FitFriend *ui;
    FitFriend* parent_window;
};


#endif // INPUT_DATA_WINDOW_H


#ifndef FITFRIEND_H
#define FITFRIEND_H

#include <QMainWindow>

namespace Ui {
class FitFriend;
}

class FitFriend : public QMainWindow
{
    Q_OBJECT

    
private slots:
    void input_data();
    

public:
    explicit FitFriend(QWidget *parent = nullptr);
    ~FitFriend();


private:
    Ui::FitFriend *ui;
};

#endif // FITFRIEND_H


#ifndef FITFRIEND_H
#define FITFRIEND_H

#include <QMainWindow>
#include <QDir>
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QBitmap>
#include <QPainter>
#include <QDir>
#include <QObject>
#include <QMediaPlayer>



namespace Ui {
class FitFriend;
}

class FitFriend : public QMainWindow
{
    Q_OBJECT


public slots:

      //opens window that gives user the options of different types of fitness data to input
      void open_input_data();

      //open the "advice from kyra" window
      void open_advice_from_kyra();

public:
    explicit FitFriend(QWidget *parent = nullptr);
    ~FitFriend();




private:
    Ui::FitFriend *ui;
};

#endif // FITFRIEND_H

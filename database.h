#ifndef DATABASE_H
#define DATABASE_H
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDateTime>
#include <QDir>
#include <QtDebug>
#include <QSqlError>
#include "input_data_window.h"
#include "input_data_types.h"



class database{

public:
    database();
    //adds run
    //adds to Run tbale in database from the SQL connection (member field).
    //@param dist= distance run in kms
    //@param taken= time object which specifies how long the run took to complete.
    //Created previously then passed by const reference to be added to the SQL database.
    //The function will implicity extract date from computer date and add to database.

    void add_run( double dist, const Time & taken);

    void add_meal();
    //adds to worokut table in datbase from SQL connection (member field).
    //@param taken= time object which specifies how long the run took to complete.
    //Created previously then passed by const reference to be added to the SQL database.
    //The function will implicity extract date from computer date and add to database.
    void add_workout( const Time & taken) ;

    //adds to weight table from SQL connection (member field)
    //@ kgs is weight value in kgs.
    void add_weight( const double &  kgs) ;



    void add_profile(); //new label that gives instuctions and sets up profile.

    ~database(){
        db.close();
    }




private:
    QSqlDatabase db;

};

//we could make this a member field of profile or something.
//use constructor either constructor of fitfriend or just at the begging fo the code.
database::database() {

db = QSqlDatabase::addDatabase("QSQLITE");
//db.setDatabaseName("/Users/Kyra/Documents/UCLA/fitfriend.db");
db.setDatabaseName(":/fitfriend.db");
//QDir
db.open();


/*
 *
 *for new computers, if they have SQL installed, you can un comment this to create the specifc tables
 * SQlQuery qry;
 * qry.prepare(create table run(distance float, taken time, on_date date)
 * qry.prepare("create table weight(kgs float, on_date date);")
 *
 *
 *
 * /
*/



};



void database::add_run(double dist,  const Time & taken){
//SQL database: fitfriend.
    //table name = run, with cols= dist float, taken time, on_date date.
    //time are  stored as '00:50:00'
    //dates are stored '2018-11-27'

  QDateTime current=  QDateTime::currentDateTime();
  QString date= current.toString("yyyy-MM-dd");
  QString time = taken.to_string();



   QSqlQuery qry;

   qry.prepare("insert into run(dist, taken, on_date) values (:dist, :taken, :date)");

  qry.bindValue(":dist", dist );
  qry.bindValue(":taken", time);
  qry.bindValue(":date", date);

  qDebug()<< time<< date;


  if(qry.exec()){

  }else {

  qDebug()<< qry.lastError();

  }

};


void add_weight( const double & kgs){
    //SQL database: fitfriend.
        //table name = run, with cols= dist float, taken time, on_date date.
        //time are  stored as '00:50:00'
        //dates are stored '2018-11-27'
        //need a member functi

      QDateTime current=  QDateTime::currentDateTime();
      QString date= current.toString("yyyy-MM-dd");
      QString kgs_string = QString::number(kgs);

      QSqlQuery qry;

    qry.prepare("insert into weight(kgs, on_date) values (:kgs, :date)");
    qry.bindValue(":kgs", kgs_string);
    qry.bindValue(":date", date);



    if(qry.exec()){

    }else {

    qDebug()<< qry.lastError();

    }



}


void add_workout(const Time & taken){

    //SQL database: fitfriend.
        //table name = workout, with cols= dist float, taken time, on_date date.
        //time are  stored as '00:50:00'
        //dates are stored '2018-11-27'

      QDateTime current=  QDateTime::currentDateTime();
      QString date= current.toString("yyyy-MM-dd");
      QString time = taken.to_string();
       QSqlQuery qry;

       qry.prepare("insert into workout(taken, on_date) values (:taken, :date)");


      qry.bindValue(":taken", time);
      qry.bindValue(":date", date);

      qDebug()<< time<< date;


      if(qry.exec()){

      }else {

      qDebug()<< qry.lastError();

      }




};






#endif // DATABASE_H

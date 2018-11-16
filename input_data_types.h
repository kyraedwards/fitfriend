#ifndef INPUT_DATA_TYPES_H
#define INPUT_DATA_TYPES_H
#include <string>

class Time{

public:

//default
Time();

//copy ctor
//member-wise copy
Time(const Time& i_time);

//3 parameters
Time(int i_hours, int i_minutes, double i_seconds);


//less than operator for two time objects
//@param left is a time object on the left side of the comparison operator
//@param right is a time object on the right side of the comparison operator
//@return true if lhs is less than rhs
//@return false otherwise
friend bool operator< (const Time& left, const Time& right);


//subtraction operator for two time objects
//@return the difference of the left time and right time
//left is the Time object on the left side of the - operator
//right is the Time object on the right side of the - operator
friend Time operator- (const Time& left, const Time& right);

private:

//military time
int m_hours;
int m_minutes;
double m_seconds;

};

class Date{

public:

    //default ctor
    Date();

    //copy ctor
    //member-wise copy
    Date(const Date& i_date);

    //ctor with 3 parameters
    Date(int i_day, int i_month, int i_year);

private:

    int m_day;
    int m_month;
    int m_year;

};

class input_data
{
public:

    //default ctor
    input_data();

    //ctor with 2 parameters
    //set parameters to respective member variables
    input_data(const Time& i_start_time, const Date& i_date);

private:

    Time m_start_time;
    Date m_date;

};


//class declerations

class Profile{
public:
     Profile();
    Profile(double );
    double to_imperial();
    double to_metric();
    double calc_cals(Time length);
     //updates daily cals burned, used in update weight.
    void update_daily_cals(double kgs);
     //used in input weight to change profile.
     void update_weight(double kgs){
        weight= kgs;
        //weight change will change daily cals and calc cals.
        update_daily_cals(kgs);
    }

 private:
    friend class Weight;
    friend class Workout;
    friend class Run;
    double weight;
    double height;
    char sex;
    char imperial;
    int age;
    double daily_cals;
 };
class Run: public input_data{
public:

    //default, sets all vals =0
    Run();

    //constructs base class object and user input.
    Run(const Time &start_time, const Date &start_date,  double d, const Time &len);

private:
    double distance, cals_burned;
    Time length;
 };



 //Meal
class Meal: public input_data{
public:
     //construct, base classs objecy and member fields initialized.
    Meal(const Time &start_time, const Date& start_date, std::string i_food, std::string i_bev, double i_food_cals=0,
         double i_bev_cals=0, double i_food_fat=0,double i_bev_fat=0, double i_food_prot=0, double i_bev_prot=0);
  private:
        std::string food, bev;
        double food_cals, bev_cals, food_fat, bev_fat, food_prot, bev_prot;
 };




class Weight: public input_data{
public:
    //defualt
    Weight();

    //gives daily weight to profile
    void update_profile() ;

    //constructer with base class
    Weight(const Time &start_time, const Date & start_date, double w);

private:
    double kgs;
};



class Workout: public input_data{
public:

    //default
    Workout();

    //constructor w/ params
    Workout(const Time &start_time, const Date& start_date, const Time &len);

 private:

    //note, this member field is not initialized inconstructor, it is done through profile class fn, calc_cal.
    //which can be called inside the constructor.
    double cals_burned;

    //user entered
    Time length;
 };



#endif // INPUT_DATA_TYPES_H

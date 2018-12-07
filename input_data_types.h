#ifndef INPUT_DATA_TYPES_H
#define INPUT_DATA_TYPES_H

#include <string>
#include <QString>


//Hours, Minutes, and Seconds. Will be used to store information about workouts
class Time{

public:

    //default
    Time();

    //copy ctor
    //member-wise copy
    Time(const Time& i_time);

    //3 parameters
    Time(int i_hours, int i_minutes, double i_seconds);

    //converts to string to add to database in form 'yyyy-mm-dd'
    QString to_string() const;

    int to_mins() const;

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


//Month, Day, and Year. Will be used to store information about workouts
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


class Profile{
public:

    Profile();
    Profile(double);
    double to_imperial();
    double to_metric();
    double calc_cals(Time length);

    //updates daily cals burned, used in update weight.
    void update_daily_cals(double kgs);

    //used in input weight to change profile.
    void update_weight(double kgs){
       weight = kgs;
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


//a run object will be created when the user inputs info about a run he or she took
class Run{

public:

    //default ctor, sets all vals = 0
    Run();

    //ctor with 3 parameters
    //all member variables will be set to respective parameters
    Run(double i_distance, const Time& i_time_spent_running, const Date& i_start_date);

private:

    //m_distance in meters
    //m_cals to be calculated according to person's information
    double m_distance, m_cals_burned;
    Time m_time_spent_running;
    Date m_date;
 };


//will be created when the user inputs info about his/her weight
class Weight {

public:

    //defualt ctor, set all member fields to 0
    Weight();

    //constructor with 3 parameters
    //all member variables will be set to respective parameters
    Weight(double i_kgs, const Date& i_date);

    //gives daily weight to profile
    void update_profile();

private:

    double m_kgs;
    Date m_date;

};


//will be created when the user inputs info about his/her workout
class Workout {

public:

    //default
    Workout();

    //constructor w/ params
    //all member variables will be set to respectice parameters
    Workout(const Time& i_length, const Date& i_start_date);

private:

    //note, this member field is not initialized in constructor, it is done through profile class fn, calc_cal.
    //which can be called inside the constructor.
    double cals_burned;

    //user entered
    Time length;

    Date m_date;

 };



//a meal object will be created when the user inputs information regarding a meal he or she ate
class Meal{

public:

    //construct, base classs object and initialize member fields.
    //@params are the information about the meal. their respective member fields will be set to them
    Meal(const Date& start_date, std::string i_food, std::string i_bev,
         double i_food_cals = 0,double i_bev_cals = 0, double i_food_fat = 0,
         double i_bev_fat = 0, double i_food_prot = 0, double i_bev_prot = 0);

private:

        QString food, bev;
        double food_cals, bev_cals, food_fat, bev_fat, food_prot, bev_prot;
        Date m_date;
};


#endif // INPUT_DATA_TYPES_H

#include "input_data_types.h"


//default ctor for Time object
Time::Time() : m_hours(0), m_minutes(0), m_seconds(0) {};


//copy ctor for time object
Time::Time(const Time& i_time) : m_hours(i_time.m_hours), m_minutes(i_time.m_minutes), m_seconds(i_time.m_seconds) {};


//3 parameter ctor for Time object
Time::Time(int i_hours, int i_minutes, double i_seconds) :
    m_hours(i_hours), m_minutes(i_minutes), m_seconds(i_seconds){};

QString Time::to_string() const{

    //output
    QString out;

    //temporary strigs used for conversion
    QString hours;
    QString mins;
    QString secs;

    //convert for the purpose of SQL database readability, SQL needs 00 not 0.
    if(m_hours<10){
        hours = "0"+ QString::number(m_hours);
    }

    else {
        hours = QString::number(m_hours);
    }

    if(m_minutes<10){
        mins = "0"+ QString::number(m_minutes);
    }

    else {
        mins = QString::number(m_minutes);
    }

    if(m_seconds<10){
        secs = "0"+ QString::number(m_seconds);
    }

    else {
        secs = QString::number(m_seconds);
    }

    out =  hours +":" + mins +":" + secs;

    return out;

};

//less than operator for 2 time objects
bool operator< (const Time& left, const Time& right){
    if (left.m_hours >= right.m_hours){
        return false;
    }

    else if (left.m_minutes >= right.m_minutes){
        return false;
    }

    else if (left.m_seconds >= right.m_seconds){
        return false;
    }

    return true;

}

//subtraction operator for 2 Time objects
Time operator- (const Time& left, const Time& right){
    Time left_copy = left;
    Time right_copy = right;

    //result of subtraction will be negative, swap left and right then make the returned Time object negative
    if(left < right){
        right_copy = left;
        left_copy = right;
    }

    //will be values of returned time
    int hours = 0;
    int minutes = 0;
    double seconds = 0;


        //right hand time has more seconds, need to borrow from hours/minutes
        if(right_copy.m_seconds > left_copy.m_seconds){
            //no minutes to borrow from, borrow from hours instead
            if(left_copy.m_minutes == 0){
                --left_copy.m_hours;
                left_copy.m_minutes += 59;
                left_copy.m_seconds += 60;
            }
        }

        //right time has more minutes than left, need to borrow minutes from hours
        if (right_copy.m_minutes > left_copy.m_minutes) {
            --left_copy.m_hours;
            left_copy.m_minutes += 60;
        }

        minutes = left_copy.m_minutes - right_copy.m_minutes;
        hours = left_copy.m_hours - right_copy.m_hours;
        seconds = left_copy.m_seconds - right_copy.m_seconds;

    //account for subtractions reversal in beginning
    if(left < right){
        return Time(-hours, -minutes, -seconds);
    }

    return Time(hours, minutes, seconds);

}


//default ctor for Date
Date::Date() : m_day(0), m_month(0), m_year(0) {};


//copy ctor for Date object
Date::Date(const Date& i_date) : m_day(i_date.m_day), m_month(i_date.m_month), m_year(i_date.m_year) {};


//Date ctor with 3 parameters
Date::Date(int i_day, int i_month, int i_year) : m_day(i_day), m_month(i_month), m_year(i_year) {};


//default ctor for input_data object
//input_data::input_data() : m_date (Date()) {};


//ctor with 2 parameters for input_data object
//set parameters to respective member variables
//input_data::input_data(const Date& i_date) : m_date(i_date) {};


//default ctor for Run object
Run::Run() : m_distance(0), m_cals_burned(0), m_time_spent_running(Time()), m_date(Date()) {};


//ctor with 4 parameters for run object
Run::Run(double i_distance, const Time& i_time_spent_running, const Date& i_start_date) :
    m_distance(i_distance), m_time_spent_running(i_time_spent_running), m_date(i_start_date) {
    //how can we construct calories burned ie how should we determine how many calories burned
};


//defualt ctor
Weight::Weight() : m_kgs(0), m_date(Date()) {};


//constructer with base class
Weight::Weight(double i_kgs, const Date& i_date) :
    m_kgs(i_kgs), m_date(i_date) {};


//need to write this
void Weight::update_profile(){};


//default
Workout::Workout() : cals_burned(0), length(Time()), m_date(Date()) {};


//constructor with 3 parameters
Workout::Workout(const Time& i_length, const Date& i_start_date) :
    length(i_length), m_date(i_start_date)
{
    //need to calculate cals_burned here
    cals_burned = 0;
}

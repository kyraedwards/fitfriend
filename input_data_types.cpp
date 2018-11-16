#include "input_data_types.h"


//default ctor for Time object
Time::Time() : m_hours(0), m_minutes(0), m_seconds(0) {};


//3 parameter ctor for Time object
Time::Time(int i_hours, int i_minutes, double i_seconds) :
    m_hours(i_hours), m_minutes(i_minutes), m_seconds(i_seconds){};

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
    int seconds = 0;


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



input_data::input_data()
{


}

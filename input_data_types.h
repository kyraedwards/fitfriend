#ifndef INPUT_DATA_TYPES_H
#define INPUT_DATA_TYPES_H

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





#endif // INPUT_DATA_TYPES_H

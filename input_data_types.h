

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
    };




private:
    friend class weight;
    friend Workout;
    friend Run;
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


Run::Run():

Run::Run(const Time &start_time, const Date & start_date, double d, double cals, const Time &len)
:input_data(start_time,start_date),distance(d), length(len){
    cals_burned= Profile::cals_burned(len);

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


Meal::Meal( const Time &start_time, const Date& start_date, std::string i_food, std::string i_bev, double i_food_cals=0,
     double i_bev_cals=0, double i_food_fat=0,double i_bev_fat=0, double i_food_prot=0, double i_bev_prot=0 ):
    input_data(start_time, start_date):food(i_food), bev(i_bev), food_cals(i_food_cals), bev_cals(i_bev_cals),
    food_fat(i_food_fat), bev_fat(i_bev_fat), food_prot(i_food_prot), bev_prot(i_bev_prot){};


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


Weight::Weight(const Time &start_time, const Date & start_date, double w):input_data(start_time, start_date)kgs(w) {};
Weight::update_profile(){


}


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

Workout(const Time &start_time, const Date& start_date, const Time &len){

    cals_burned = Profile::calc_cals(len);

};




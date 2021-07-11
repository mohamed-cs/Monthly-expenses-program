#ifndef MOTHALYEXPANCES_datee_cl_H
#define MOTHALYEXPANCES_datee_cl_H
#include "bits/stdc++.h"
                                        //time_t t = time(0);   // Get time now
                                        //tm * now = localtime(&t);
                                        //date d(now);
                                        //cout<<d.getdate();
class datee_cl{

    private:
            int months;
            int year;
            int day;
            int hours;
            int minutes;
            int second;
    public:

    datee_cl(){}
    datee_cl( tm *ltm){

        this->year= 1900 + ltm->tm_year;
        this->months=1 + ltm->tm_mon;
        this->day=ltm->tm_mday;
        this->hours=ltm->tm_hour ;
        this->minutes=30+ltm->tm_min ;
        this->second=ltm->tm_sec;
    }

    int getmonths(){
        return this->months;
    }
    int getyear(){
        return this->year;
    }
    int getday(){
        return this->day;
    }
    int gethours(){
        return this->hours;
    }
    int getminuts(){
        return this->minutes;
    }
    int getseconds(){
        return this->second;
    }

    void setMonths(int months) {
        datee_cl::months = months;
    }

    void setYear(int year) {
        datee_cl::year = year;
    }

    void setDay(int day) {
        datee_cl::day = day;
    }

    string get_date(){
        char date_concatination[50];
        sprintf(date_concatination, "%04d - %02d - %02d  %02d:%02d:%02d ", this->year, this->months, this->day,this->hours,this->minutes,this->second);

        return date_concatination;

    }
    static datee_cl get_date_now()
    {
        time_t t = time(0);   // Get time now
        tm * now = localtime(&t);
        datee_cl d(now);

        return d;
    }

    static bool check_month_start()
    {
        time_t t = time(0);   // Get time now
        tm * now = localtime(&t);
        datee_cl d(now);

//        cout<<d.getday();

        if(d.getday()==1)
        {
            return true;
        }
        else
        {
            return false;
        }


    }

    static datee_cl take_date()
    {
        int day;
        int month;
        int year;
        datee_cl datee;
        cout<<"                                               "<<"Entre day"<<endl;
        cin>>day;
        cout<<"                                               "<<"Enter month"<<endl;
        cin>>month;
        cout<<"                                               "<<"Enter year"<<endl;
        cin>>year;

        datee.setDay(day);
        datee.setMonths(month);
        datee.setYear(year);

        return datee;
    }



};

#endif
#ifndef MOTHALYEXPANCES_User_H
#define MOTHALYEXPANCES_User_H

#include "Expance.h"
#include "income.h"
#include "bits/stdc++.h"
//********************.*********************************************************************************************
                                           //class of USER
//*****************************************************************************************************************




class User {

private:

        string name;
        string password;
        string E_mail;
        vector<income>monthly_income;
        vector<Expance>expance_data;

    public:
    int id;
    User(int ,string ,string ,string);
    User(int,string,string  ,string, vector<income>);

    void set_id(int);
    int get_id();

    string getName() ;

    void setName(string name);

    void setId(int id);

    string getPassword() ;

    void setPassword(string password);

    vector<income>& getMonthlyIncome();

    void setMonthlyIncome(vector<income> monthlyIncome);

    vector<Expance>& getExpanceData();

    void setExpanceData(vector<Expance> expanceData);

    string getEMail() ;

    void setEMail( string eMail);

   static bool login_validition(string,string ,string,vector<User>&,int&);

   static void users_full_data(vector<User>&users,vector<Expance>,vector<income>);
   static void add_expanse_tovector(vector<Expance> &expanses ,vector<User> &users , int, string,string,double);

};

#endif
#ifndef MOTHALYEXPANCES_Expance_H
#define MOTHALYEXPANCES_Expance_H

#include "datee_cl.h"
#include "bits/stdc++.h"
//*****************************************************************************************************************
                                             //class of EXPANCE
//*****************************************************************************************************************

class Expance {

    private:
        int id;
        string category;
        string wallet;
        double amount_Price;
        datee_cl expanse_Date;

    public:
    Expance();
    Expance(string , string , double ,datee_cl );
     string getCategory() ;
    string getWallet() ;
    double getAmountPrice();
     datee_cl getExpanseDate() ;
    int  get_id();
    void set_id(int);

    static void display(vector<Expance>);

    static vector<Expance> filter_by_id(vector<Expance>,int);
   static vector<Expance> filter_by_wallet(vector<Expance>, string );
    static vector<Expance> filter_by_date(vector<Expance>, datee_cl );
     static vector<Expance> filter_by_category(vector<Expance>,string);
    static vector<Expance> filter_by_amount(vector<Expance>,double);

  static  vector<Expance> filter_by_date_category(vector<Expance>,datee_cl,string);
   static vector<Expance> filter_by_date_amount(vector<Expance>,datee_cl,double);
   static vector<Expance> filter_by_date_wallet(vector<Expance>,datee_cl,string);

   static vector<Expance> filter_by_amount_category(vector<Expance>,double ,string);
    static vector<Expance> filter_by_amount_wallet(vector<Expance>,double ,string);

    static vector<Expance> filter_by_amount_category_date(vector<Expance>,double ,string,datee_cl);

    static vector<Expance> filter_by_amount_category_date_wallet(vector<Expance>,double ,string,datee_cl,string);


};

#endif
#include "Expance.h"

Expance::Expance() {}

Expance::Expance( string category, string wallet, double amountPrice,  datee_cl expanseDate) : category(
        category), wallet(wallet), amount_Price(amountPrice), expanse_Date(expanseDate) {}

string Expance::getCategory() {
    return category;
}

 string Expance::getWallet()  {
    return wallet;
}

double Expance::getAmountPrice() {
    return amount_Price;
}

datee_cl Expance::getExpanseDate()  {
    return expanse_Date;
}
int Expance::get_id() {
    return this->id;
}
void Expance::set_id(int id) {
    this->id=id;
}

void Expance::display(vector<Expance>expances){
    for(int i=0;i<expances.size();i++)
    {
        cout<<"  Category  "<<" :: "<<" Price "<<" :: "<<" Date "<<" :: "<<"Wallet"<<endl;
        cout<<expances[i].getCategory()<<" :: "<<expances[i].getAmountPrice()<<
        " :: "<<expances[i].getExpanseDate().get_date()<<" :: "<<expances[i].getWallet()<<endl;
    }

}

vector<Expance> Expance::filter_by_id(vector<Expance>expances, int id){

    vector<Expance>filtered_expances;

    for(int i=0;i<expances.size();i++) {
        if (expances[i].get_id() == id) {
            filtered_expances.push_back(expances[i]);
        } else {
            continue;
        }
    }
    return filtered_expances;

}
vector<Expance> Expance::filter_by_date(vector<Expance>expances, datee_cl Date) {

                        //    output ==> should be the vector filtered_expance
//   filtered_expance  ==> equal to expances vector after filtered it
//   you should make for loop and check if ( expances[index]->getExpanseDate().getdate()).compare(Date.getdate()))
//    then you should insert expances[index] in filtered_expances vector   using insert(object) function
//    else continue

    vector<Expance>filtered_expances;

    for(int i=0;i<expances.size();i++)
    {
        if(expances[i].getExpanseDate().getyear()==Date.getyear() &&
        expances[i].getExpanseDate().getmonths()==Date.getmonths() &&
        expances[i].getExpanseDate().getday()==Date.getday())
        {
            filtered_expances.push_back(expances[i]);
        }
        else {
            continue;
        }
    }

    return filtered_expances;
}
vector<Expance> Expance::filter_by_category(vector<Expance>expances, string category) {
    //   filtered_expance  ==> equal to expances vector after filtered it
//   you should make for loop and check if ( expances[index]->getCategory()).compare(category))
//    then you should insert expances[index] in filtered_expances vector   using insert(object) function
//    else continue

    vector<Expance>filtered_expances;

    for(int i=0;i<expances.size();i++)
    {
        if(!expances[i].getCategory().compare(category))
        {
            filtered_expances.push_back(expances[i]);
        }
        else
        {
            continue;
        }
    }


    return filtered_expances;
}

vector<Expance> Expance::filter_by_amount(vector<Expance>expances, double amount) {
                    //   filtered_expance  ==> equal to expances vector after filtered it
//   you should make for loop and check if ( expances[index]->getAmountPrice()==amount)
//    then you should insert expances[index] in filtered_expances vector   using insert(object) function
//    else continue


    vector<Expance>filtered_expances;

    for(int i=0;i<expances.size();i++)
    {
        if(expances[i].getAmountPrice()==amount)
        {
            filtered_expances.push_back(expances[i]);
        }
        else{
            continue;
        }
    }

    return filtered_expances;
}
vector <Expance> Expance::filter_by_wallet(vector<Expance>expances, string wallet) {

                 //   filtered_expance  ==> equal to expances vector after filtered it
//   you should make for loop and check if ( expances[index]-> getWallet().compare(wallet))
//    then you should insert expances[index] in filtered_expances vector   using insert(object) function
//    else continue

    vector<Expance>filtered_expances;

    for(int i=0;i<expances.size();i++)
    {
        if(!expances[i].getWallet().compare(wallet))
        {
            filtered_expances.push_back(expances[i]);
        }
        else{
            continue;
        }
    }

    return filtered_expances;
}


vector<Expance> Expance::filter_by_date_category(vector<Expance>expances, datee_cl Date, string category) {

                    //   filtered_expance1  ==> equal to expances vector after filtered it
                    //   filtered_expance2  ==> equal to expances1 vector after filtered it
                            //you can use any of filterition function that we decalare

    vector<Expance>filtered_expances1;
    vector<Expance>filtered_expances2;

    filtered_expances1=Expance::filter_by_date(expances,Date);
    filtered_expances2=Expance::filter_by_category(filtered_expances1,category);

    return filtered_expances2;
}

vector<Expance> Expance::filter_by_date_amount(vector<Expance>expances, datee_cl Date, double amount) {

                    //   filtered_expance1  ==> equal to expances vector after filtered it
                    //   filtered_expance2  ==> equal to expances1 vector after filtered it
                    //you can use any of filterition function that we decalare

    vector<Expance>filtered_expances1;
    vector<Expance>filtered_expances2;

    filtered_expances1=Expance::filter_by_date(expances,Date);
    filtered_expances2=Expance::filter_by_amount(filtered_expances1,amount);


    return filtered_expances2;
}

vector<Expance> Expance::filter_by_amount_category(vector<Expance>expances, double amount, string category) {

                        //   filtered_expance1  ==> equal to expances vector after filtered it
                        //   filtered_expance2  ==> equal to expances1 vector after filtered it
                        //you can use any of filterition function that we decalare

    vector<Expance>filtered_expances1;
    vector<Expance>filtered_expances2;

    filtered_expances1=Expance::filter_by_amount(expances,amount);
    filtered_expances2=Expance::filter_by_category(filtered_expances1,category);

    return filtered_expances2;
}

vector<Expance> Expance::filter_by_date_wallet(vector<Expance>expances, datee_cl Date, string wallet) {
    //   filtered_expance1  ==> equal to expances vector after filtered it
    //   filtered_expance2  ==> equal to expances1 vector after filtered it
    //you can use any of filterition function that we decalare

    vector<Expance>filtered_expances1;
    vector<Expance>filtered_expances2;

    filtered_expances1=Expance::filter_by_date(expances,Date);
    filtered_expances2=Expance::filter_by_wallet(filtered_expances1,wallet);


    return filtered_expances2;
}

vector<Expance> Expance::filter_by_amount_wallet(vector<Expance>expances, double amount, string wallet) {
    vector<Expance>filtered_expances1;
    vector<Expance>filtered_expances2;

    //   filtered_expance1  ==> equal to expances vector after filtered it
    //   filtered_expance2  ==> equal to expances1 vector after filtered it
    //you can use any of filterition function that we decalare

    filtered_expances1=Expance::filter_by_amount(expances,amount);
    filtered_expances2=Expance::filter_by_wallet(filtered_expances1,wallet);

    return filtered_expances2;
}

vector<Expance> Expance::filter_by_amount_category_date(vector<Expance>expances, double amount, string category, datee_cl Date) {
    //   filtered_expance1  ==> equal to expances vector after filtered it
    //   filtered_expance2  ==> equal to expances1 vector after filtered it
    //   filtered_expance3  ==> equal to expances2 vector after filtered it
    //you can use any of filterition function that we decalare

    vector<Expance>filtered_expances1;
    vector<Expance>filtered_expances2;

    filtered_expances1=Expance::filter_by_amount_category(expances,amount,category);
    filtered_expances2=Expance::filter_by_date(filtered_expances1,Date);

    return filtered_expances2;
}

vector<Expance> Expance::filter_by_amount_category_date_wallet(vector<Expance>expances, double amount, string category, datee_cl Date, string wallet) {
    //   filtered_expance1  ==> equal to expances vector after filtered it
    //   filtered_expance2  ==> equal to expances1 vector after filtered it
    //   filtered_expance3  ==> equal to expances2 vector after filtered it
    //   filtered_expance4  ==> equal to expances3 vector after filtered it
    //you can use any of filterition function that we decalare

    vector<Expance>filtered_expances1;
    vector<Expance>filtered_expances2;

    filtered_expances1=Expance::filter_by_amount_category_date(expances,amount,category,Date);
    filtered_expances2=Expance::filter_by_wallet(filtered_expances1,wallet);


    return filtered_expances2;
}





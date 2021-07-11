#include "User.h"


User::User( int id,string name, string E_mail ,string Password,  vector<income> monthlyIncome) : id(id),name(name),E_mail(E_mail),password(password)
,monthly_income(monthlyIncome) {}

void User::set_id(int id ) {
    this->id=id;
}

int User::get_id() {
    return this->id;
}
 string User::getName() {
    return name;
}

void User::setName( string name) {
    User::name = name;
}
string User::getPassword() {
    return password;
}

void User::setPassword(string password) {
    User::password = password;
}

vector<income>& User::getMonthlyIncome(){
    return monthly_income;
}

void User::setMonthlyIncome(vector<income> monthlyIncome) {
    monthly_income = monthlyIncome;
}
vector<Expance>& User::getExpanceData() {
    return expance_data;
}

void User::setExpanceData(vector<Expance> expanceData) {
    expance_data = expanceData;
}

string User::getEMail()  {
    return E_mail;
}

void User::setEMail( string eMail) {
    E_mail = eMail;
}

bool User::login_validition(string name, string e_mail ,string password, vector<User>&users,int &index) {

                        //    idex entry first value is -1
     bool check=false;
//        cout<<users.size()<<endl;
    for(int i=0;i<users.size();i++)
    {
        if(users[i].getName().compare(name)==0 &&
        users[i].getEMail().compare(e_mail)==0 &&
        users[i].getPassword().compare(password)==0)
        {
            index=i;
            check=true;
            break;
        }
        else
        {
            continue;
        }

    }

    return check;
}

void User::users_full_data(vector<User> &users , vector<Expance>expances, vector<income>incomes) {
    for(int i=0;i<users.size();i++)
    {
        for(int j=0;j<expances.size();j++)
        {
            if(users[i].get_id()==expances[j].get_id())
            {
                users[i].getExpanceData().push_back(expances[j]);
            }
            else
            {
                continue;
            }
        }
    }

    for(int i=0;i<users.size();i++)
    {
        for(int j=0;j<incomes.size();j++)
        {
            if(users[i].get_id()==incomes[i].get_id())
            {
                users[i].getMonthlyIncome().push_back(incomes[j]);
            }
        }
    }

}

User::User(int id, string name, string email, string password) {
    this->name=name;
    this->password=password;
    this->id=id;
    this->E_mail=email;

}
void User::add_expanse_tovector(vector<Expance> &expanses,vector<User> & users,int valid_index, string category, string wallet, double amount) {

    Expance expan(category, wallet, amount, datee_cl::get_date_now());

    expanses.push_back(expan);

    users[valid_index].getExpanceData().push_back(expan);

}

void User::setId(int id) {
    User::id = id;
}



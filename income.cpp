#include "income.h"
#include "bits/stdc++.h"

income::income() {}
income::income(int id, datee_cl incomeDate, double cashWallet, double creditCardWallet, double debitCardWallet,
               double cash_depit, double credit_depit, double depit_depit) {

//first log-in
    this->id=id;
    this->cash_Wallet=cashWallet;
    this->credit_Card_Wallet=creditCardWallet;
    this->debit_Card_Wallet=debitCardWallet;
    this->cash_Check= (this->cash_Wallet > 0.0);
    this->debit_Card_Check= (this->debit_Card_Wallet > 0.0);
    this->credit_Card_Check= (this->credit_Card_Wallet > 0.0);
    this->income_Date=incomeDate;

    this->remaning_cash=this->cash_Wallet-cash_depit;
    this->remaining_credit=this->credit_Card_Wallet-credit_depit;
    this->remaining_depit=this->debit_Card_Wallet-depit_depit;

}

income::income(int id, datee_cl incomeDate, double cashWallet, double creditCardWallet, double debitCardWallet,
               double remaning_cash_lastmonth, double remaining_credit_lastmonth, double remaning_depit_lastmonth,
               double cash_depit, double credit_depit, double depit_depit) {
    // start of month
    this->id=id;
    this->cash_Wallet=cashWallet;
    this->credit_Card_Wallet=creditCardWallet;
    this->debit_Card_Wallet=debitCardWallet;
    this->cash_Check= (this->cash_Wallet > 0.0);
    this->debit_Card_Check= (this->debit_Card_Wallet > 0.0);
    this->credit_Card_Check= (this->credit_Card_Wallet > 0.0);
    this->cash_dept=0.0;
    this->credit_Card_debit=0.0;
    this->debit_Card_debit=0.0;
    this->income_Date=incomeDate;
    this->remaning_cash=this->cash_Wallet+remaning_cash_lastmonth-cash_depit;
    this->remaining_credit=this->credit_Card_Wallet+remaining_credit_lastmonth-credit_depit;
    this->remaining_depit=this->debit_Card_Wallet+remaning_depit_lastmonth-depit_depit;


}

void income::set_id(int id) {
    this->id=id;
}

int income::get_id() {
    return id;
}

datee_cl income::getIncomeDate()  {
    return income_Date;
}

void income::setIncomeDate( datee_cl incomeDate) {
    income_Date = incomeDate;
}

double income::getCashWallet()  {
    return cash_Wallet;
}

void income::setCashWallet(double cashWallet) {
    cash_Wallet = cashWallet;
}

double income::getCreditCardWallet() {
    return credit_Card_Wallet;
}

void income::setCreditCardWallet(double creditCardWallet) {
    credit_Card_Wallet = creditCardWallet;
}

double income::getDebitCardWallet()  {
    return debit_Card_Wallet;
}

void income::setDebitCardWallet(double debitCardWallet) {
    debit_Card_Wallet = debitCardWallet;
}

bool income::isCashCheck() {
    return cash_Check;
}

void income::setCashCheck(bool cashCheck) {
    cash_Check = cashCheck;
}

bool income::isCreditCardCheck() {
    return credit_Card_Check;
}

void income::setCreditCardCheck(bool creditCardCheck) {
    credit_Card_Check = creditCardCheck;
}

bool income::isDebitCardCheck()  {
    return debit_Card_Check;
}

void income::setDebitCardCheck(bool debitCardCheck) {
    debit_Card_Check = debitCardCheck;
}

double income::getCashDept()  {
    return cash_dept;
}

void income::setCashDept(double cashDept) {
    cash_dept = cashDept;
}

double income::getCreditCardDebit()  {
    return credit_Card_debit;
}

void income::setCreditCardDebit(double creditCardDebit) {
    credit_Card_debit = creditCardDebit;
}

double income::getDebitCardDebit()  {
    return debit_Card_debit;
}

void income::setDebitCardDebit(double debitCardDebit) {
    debit_Card_debit = debitCardDebit;
}
vector<income> income::filter_by_id(vector<income> incomes, int id ) {
    vector<income> filtered_incomes;

    for(int i=0;i<incomes.size();i++)
    {
        if(incomes[i].get_id()==id)
        {
            filtered_incomes.push_back(incomes[i]);
        }
        else{
            continue;
        }
    }

    return filtered_incomes;
}

double income::getRemaningCash() {
    return remaning_cash;
}

void income::setRemaningCash(double remaningCash) {
    remaning_cash = remaningCash;
}

double income::getRemainingCredit()  {
    return remaining_credit;
}

void income::setRemainingCredit(double remainingCredit) {
    remaining_credit = remainingCredit;
}

double income::getRemainingDepit() {
    return remaining_depit;
}

void income::setRemainingDepit(double remainingDepit) {
    remaining_depit = remainingDepit;
}


void income::addexpanseamount(string wallet,double amount ) {

    if(!wallet.compare("cash")||!wallet.compare("CASH"))
    {
        this->remaning_cash-=amount;
    }
    else if(!wallet.compare("credit")||!wallet.compare("CREDIT"))
    {
        this->remaining_credit-=amount;
    }
    else if(!wallet.compare("depit")||!wallet.compare("DEPIT"))
    {
        this->remaining_depit-=amount;
    }
}

void income::addexpanseamount_to_depit(string wallet, double amount) {

    if(wallet.compare("cash")||wallet.compare("CASH"))
    {
        this->cash_dept+=amount;
    }
    else if(wallet.compare("credit")||wallet.compare("CREDIT"))
    {
        this->credit_Card_debit+=amount;
    }
    else if(wallet.compare("depit")||wallet.compare("DEPIT"))
    {
        this->debit_Card_debit+=amount;
    }

}

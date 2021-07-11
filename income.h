#ifndef MOTHALYEXPANCES_income_H
#define MOTHALYEXPANCES_income_H
//*****************************************************************************************************************
                                         //class of INCOME
//*****************************************************************************************************************
#include "datee_cl.h"

class income{

    private:

    int id;

    datee_cl income_Date;

    double cash_Wallet;
    double credit_Card_Wallet;
    double debit_Card_Wallet;

    bool cash_Check;//not store
    bool credit_Card_Check;//not store
    bool debit_Card_Check;//not store

    double remaning_cash;    // remaining=cashwallet+remining-depit
    double remaining_credit;
    double remaining_depit;

    double cash_dept;
    double credit_Card_debit;
    double debit_Card_debit;

    public:

    income();
    income(int id ,datee_cl incomeDate, double cashWallet, double creditCardWallet, double debitCardWallet,
           double cash_depit,double credit_depit,double depit_depit);

    income(int id ,datee_cl incomeDate, double cashWallet, double creditCardWallet, double debitCardWallet,
           double remaning_cash_lastmonth,double remaining_credit_lastmonth,double remaning_depit_lastmonth,
           double cash_depit,double credit_depit,double depit_depit);

    void set_id(int );
    int get_id();

    double getRemaningCash() ;

    void setRemaningCash(double remaningCash);

    double getRemainingCredit() ;

    void setRemainingCredit(double remainingCredit);

    double getRemainingDepit() ;

    void setRemainingDepit(double remainingDepit);

    datee_cl getIncomeDate() ;

    void setIncomeDate(datee_cl incomeDate);

    double getCashWallet() ;

    void setCashWallet(double cashWallet);

    double getCreditCardWallet() ;

    void setCreditCardWallet(double creditCardWallet);

    double getDebitCardWallet() ;

    void setDebitCardWallet(double debitCardWallet);

    bool isCashCheck() ;

    void setCashCheck(bool cashCheck);

    bool isCreditCardCheck() ;

    void setCreditCardCheck(bool creditCardCheck);

    bool isDebitCardCheck() ;

    void setDebitCardCheck(bool debitCardCheck);

    double getCashDept() ;

    void setCashDept(double cashDept);

    double getCreditCardDebit() ;

    void setCreditCardDebit(double creditCardDebit);

    double getDebitCardDebit() ;

    void setDebitCardDebit(double debitCardDebit);

    static vector<income> filter_by_id(vector<income>,int );

    void addexpanseamount(string,double);
    void addexpanseamount_to_depit(string,double);

};
#endif
#include<bits/stdc++.h>
#include "User.h"
#include <stdlib.h>
#include <conio.h>
#include "stff.h"

//here we will get data from files to files one for user and the another one for expances
vector<User>Users;
vector<Expance>Expances;
vector<income>incomes;

void display_pattern();
void take_amount(int valid_user_index,const string& category,bool cash,bool depit,bool credit,double amount);
void display_remaining_money(int valid_user_index,int index,bool cash,bool credit,bool depit);
void display_dept_money(int valid_user_index,int index,bool cash,bool credit,bool depit);
void display_dept_of_lastmonth(int valid_user_index,bool cash,bool depit,bool credit);

int main()
{
    //full all data before anything
    User::users_full_data(Users,Expances,incomes);

    log:
    int start_choice;
    while(true)
    {
        display_pattern();
        cout<<" If you have decided to take control of your financial situation you will need a powerful finance software that will let you create a monthly budget, track spending, and present the data to you in a way that will allow you to have insights about your habit and know how to manage your money better."<<"\n\n";

        cout<<"                                               "<<"Enter your choice"<<endl;
        cout<<"                                               "<<"1-Log-in"<<endl;
        cout<<"                                               "<<"2-Sign-up"<<endl;
        cout<<"                                               ";
        cin>>start_choice;
        if(start_choice==1||start_choice==2)
        {
            break;
        }
        else
        {
            system("CLS");
            continue;
        }
    }
    if(start_choice==1)
    {
          // log
      system("CLS");
      display_pattern();
        cout << "\n                                             " << "Log-in" <<"\n\n";
      bool check_valid=false;
      int valid_user_index;

      while(true) {
          string username_log;
          string email_log;
          string password_log;

          cout << "                                             " << "Enter your User Name" << endl;
          cin >> username_log;
          cout << "                                             " << "Enter your Email" << endl;
          cin >> email_log;
          cout << "                                             " << "Enter your Password" << endl;
          cin >> password_log;

          check_valid = User::login_validition(username_log, email_log, password_log, Users, valid_user_index);

          if(check_valid)
          {
              break;
          }
          else{
              int choice;
              cout << "                                               " <<"wrong information" << endl;
              while(true) {
                  cout << "                                               " << "Enter your choice " << endl;
                  cout << "                                               " << "1- Try again " << endl;
                  cout << "                                               " << "2- Exit " << endl;
                  cin>>choice;

                  if(choice==1)
                  {
                      break;
                  }
                  else if(choice==2)
                  {
                      fileeee::write_user(Users);
                        exit(0);
                  }
                  else
                  {
                      system("CLS");
                      continue;
                  }


              }
          }
      }

      if(Users[valid_user_index].getMonthlyIncome().empty())
      {
          double credit=0.0,cash=0.0,depit=0.0;
          double cash_depit=0.0,credit_dept=0.0,depit_depit=0.0;

          system("CLS");
          display_pattern();
          cout << "\n                                          " << "Enter your income of month " <<datee_cl::get_date_now().getmonths()<< endl;
          cout<< "                                              "<<"Enter credit card wallet amount "<<endl;
          cin>>credit;
          cout<< "                                              "<<"Enter depit card wallet amount "<<endl;
          cin>>depit;
          cout<< "                                              "<<"Enter cash wallet amount "<<endl;
          cin>>cash;
          cout<< "                                              "<<"Enter your credit card depit or Enter 0 if you not have  "<<endl;
          cin>>credit_dept;
          cout<< "                                              "<<"Enter your depit card depit or Enter 0 if you not have "<<endl;
          cin>>depit_depit;
          cout<< "                                              "<<"Enter your cash card depit or Enter 0 if you not have "<<endl;
          cin>>cash_depit;

          income start_month_income(Users[valid_user_index].get_id(),datee_cl::get_date_now(),cash,credit,depit,cash_depit,credit_dept,depit_depit);

          incomes.push_back(start_month_income);
          Users[valid_user_index].getMonthlyIncome().push_back(start_month_income);

      }

      if(datee_cl::check_month_start()&&!Users[valid_user_index].getMonthlyIncome().empty())
      {
          double credit=0.0,cash=0.0,depit=0.0;
          double remain_cash_lastmonth=0.0;
          double remain_credit_lastmonth=0.0;
          double remain_depit_lastmonth=0.0;
          double cash_depit=0.0,credit_dept=0.0,depit_depit=0.0;

          system("CLS");
          display_pattern();
          cout << "\n                                          " << "Enter your income of month " <<datee_cl::get_date_now().getmonths()<< endl;
          cout<< "                                              "<<"Enter credit card wallet amount "<<endl;
          cin>>credit;
          cout<< "                                              "<<"Enter depit card wallet amount "<<endl;
          cin>>depit;
          cout<< "                                              "<<"Enter cash wallet amount "<<endl;
          cin>>cash;

          if(Users[valid_user_index].getMonthlyIncome().back().isCashCheck())
          {
              remain_cash_lastmonth=Users[valid_user_index].getMonthlyIncome().back().getRemaningCash();
              cash_depit=Users[valid_user_index].getMonthlyIncome().back().getCashDept();
          }

          if(Users[valid_user_index].getMonthlyIncome().back().isCreditCardCheck())
          {
              remain_credit_lastmonth=Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit();
              credit_dept=Users[valid_user_index].getMonthlyIncome().back().getCreditCardDebit();
          }
          if(Users[valid_user_index].getMonthlyIncome().back().isDebitCardCheck())
          {
              remain_depit_lastmonth=Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit();
              depit_depit=Users[valid_user_index].getMonthlyIncome().back().getDebitCardDebit();
          }


          income start_month_income(Users[valid_user_index].get_id(),datee_cl::get_date_now(),cash,credit,depit,
                                    remain_cash_lastmonth,remain_credit_lastmonth,remain_depit_lastmonth,cash_depit,credit_dept,depit_depit);

          incomes.push_back(start_month_income);
          Users[valid_user_index].getMonthlyIncome().push_back(start_month_income);

      }
      while(true)
      {
          menu:
          int choice;
        system("CLS");
        display_pattern();
        cout << "                                               " << "Enter your choice " << endl;
        cout << "                                               " << "1-Add expanses" << endl; //finished
        cout << "                                               " << "2-show all expanses" << endl; //finished
        cout << "                                               " << "3-Filter expanses" << endl;  //finished
        cout << "                                               " << "4-show remaining money in wallets for this month" << endl;//finished
        cout << "                                               " << "5-show dept or saving money from last month" << endl;
        cout << "                                               " << "6- Log_out" << endl; //finished
        cout << "                                               " << "7- Exit" << endl; //finished

        cin>>choice;
          switch (choice) {
              case 1:
              {
                  exp:

                  bool cash=false,credit=false,depit=false;
                  string category;
                  string wallet;
                  double amount;


                  system("CLS");
                  display_pattern();
                  cash=Users[valid_user_index].getMonthlyIncome().back().isCashCheck();
                  credit=Users[valid_user_index].getMonthlyIncome().back().isCreditCardCheck();
                  depit=Users[valid_user_index].getMonthlyIncome().back().isDebitCardCheck();

                  cout << "\n                                               " << "Adding your Expanse " << endl;
                  cout << "                                               " << "Enter category of Expanse " << endl;
                  cin>>category;
                  cout << "                                               " << "Enter Price of Expanse " << endl;
                  cin>>amount;

                  take_amount(valid_user_index,category,cash,depit,credit,amount);

                  int ch;
                  system("CLS");
                  display_pattern();
                  cout << "\n                                     " << "Enter your choice" << endl;
                  cout << "                                     " << "1-Adding another expanse" << endl;
                  cout << "                                     " << "2-Main Menu" << endl;
                  cout << "                                     " << "3- Log out" << endl;
                  cout<<  "                                     " << "4- Exit"<<endl;
                  cin>>ch;
                  if(ch==1)
                      goto exp;
                  else if(ch==2)
                      goto menu;
                  else if(ch==3)
                      goto log;
                  else if(ch==4) {
                      fileeee::write_user(Users);

                      exit(0);
                  }
                  else
                      goto menu;
              }
              break;
              case 2:
              {

                      int choice1;

                      system("CLS");
                      display_pattern();
                      cout<<"\n  ";

                      Expance::display(Users[valid_user_index].getExpanceData());
                      while(true)
                      {
                      cout << "                                               " << "Enter your choice " << endl;
                      cout << "                                               " << "1- Menu " << endl;
                      cout << "                                               " << "2- Log_out" << endl;
                      cout << "                                               " << "3- Exit" << endl;
                      cin >> choice1;

                      switch (choice1)
                      {
                          case 1:
                              goto menu;
                          break;
                          case 2:
                              goto log;
                          break;
                          case 3: {
                              fileeee::write_user(Users);
                              exit(0);
                          }
                          break;
                          default: {
                              cout << "                                               " << "wrong choice try again"<< endl;
                              continue;
                          }
                      }

                  }

              }
              break;
              case 3:
              {
                  filtt:
                  while (true) {
                      int choice1;
                      system("CLS");
                      display_pattern();
                      cout << "                                               " << "Enter your choice1 " << endl;
                      cout << "                                               " << "1-Filter expanses by date" << endl;
                      cout << "                                               " << "2-Filter expanses by category "
                           << endl;
                      cout << "                                               " << "3-Filter expanses by amount"
                           << endl;
                      cout << "                                               " << "4-Filter expanses by wallet"
                           << endl;
                      cout << "                                               "
                           << "5-Filter expanses by date and category" << endl;
                      cout << "                                               "
                           << "6-Filter expanses by date and amount" << endl;
                      cout << "                                               "
                           << "7-Filter expanses by amount and category" << endl;
                      cout << "                                               "
                           << "8-Filter expanses by date,category and amount " << endl;
                      cin >> choice1;

                      switch (choice1) {
                          case 1: {
                              datee_cl datee;

                              system("CLS");
                              display_pattern();
                              cout << "                                               " << "Filter expanses by date"
                                   << endl;

                              datee = datee_cl::take_date();
                              Expance::display(
                                      Expance::filter_by_date(Users[valid_user_index].getExpanceData(), datee));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);
                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }
                          }
                              break;
                          case 2: {
                              string category;
                              system("CLS");
                              display_pattern();
                              cout << "                                               "
                                   << "Filter expanses by category " << endl;
                              cout << "                                               " << "Enter category " << endl;
                              cin >> category;

                              Expance::display(
                                      Expance::filter_by_category(Users[valid_user_index].getExpanceData(), category));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);
                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }
                          }
                              break;
                          case 3: {
                              double amount;
                              system("CLS");
                              display_pattern();
                              cout << "                                               " << "Filter expanses by amount"
                                   << endl;
                              cout << "                                               " << "Enter amount" << endl;
                              cin >> amount;

                              Expance::display(
                                      Expance::filter_by_amount(Users[valid_user_index].getExpanceData(), amount));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);

                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }
                          }
                              break;
                          case 4: {
                              string wallet;
                              system("CLS");
                              display_pattern();
                              cout << "                                               " << "Filter expanses by wallet"
                                   << endl;
                              cout << "                                               "
                                   << "wallet should be cash or credit-card  or depit-card" << endl;
                              cout << "                                               " << "Enter wallet type" << endl;
                              cin >> wallet;

                              Expance::display(
                                      Expance::filter_by_wallet(Users[valid_user_index].getExpanceData(), wallet));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);
                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }

                          }
                              break;
                          case 5: {
                              datee_cl datee;
                              string category;
                              system("CLS");
                              display_pattern();
                              cout << "                                               "
                                   << "Filter expanses by date and category" << endl;
                              datee = datee_cl::take_date();
                              cout << "                                               " << "Enter Category" << endl;
                              cin >> category;

                              Expance::display(
                                      Expance::filter_by_date_category(Users[valid_user_index].getExpanceData(), datee,
                                                                       category));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);
                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }
                          }
                              break;
                          case 6 : {
                              datee_cl datee;
                              double amount;
                              system("CLS");
                              display_pattern();
                              cout << "                                               "
                                   << "Filter expanses by date and amount" << endl;
                              datee = datee_cl::take_date();
                              cout << "                                               " << "Enter amount" << endl;
                              cin >> amount;

                              Expance::display(
                                      Expance::filter_by_date_amount(Users[valid_user_index].getExpanceData(), datee,
                                                                     amount));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);
                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }
                          }
                              break;
                          case 7: {
                              string category;
                              double amount;
                              system("CLS");
                              display_pattern();

                              cout << "                                               "
                                   << "Filter expanses by amount and category" << endl;
                              cout << "                                               " << "Enter amount" << endl;
                              cin >> amount;
                              cout << "                                               " << "Enter Category" << endl;
                              cin >> category;
                              Expance::display(
                                      Expance::filter_by_amount_category(Users[valid_user_index].getExpanceData(),
                                                                         amount, category));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);
                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }
                          }
                              break;
                          case 8: {
                              datee_cl datee;
                              string category;
                              double amount;
                              system("CLS");
                              display_pattern();
                              cout << "                                               "
                                   << "Filter expanses by date,category and amount " << endl;
                              cout << "                                               " << "Enter amount" << endl;
                              cin >> amount;
                              cout << "                                               " << "Enter Category" << endl;
                              cin >> category;
                              datee = datee_cl::take_date();
                              Expance::display(
                                      Expance::filter_by_amount_category_date(Users[valid_user_index].getExpanceData(),
                                                                              amount, category, datee));

                              int choice2;
                              while (true) {
                                  cout << "                                               " << "Enter your choice1 "
                                       << endl;
                                  cout << "                                               " << "1- Try another filter "
                                       << endl;
                                  cout << "                                               " << "2- Menu " << endl;
                                  cout << "                                               " << "3- Log_out" << endl;
                                  cout << "                                               " << "4- Exit" << endl;
                                  cin >> choice2;

                                  switch (choice2) {
                                      case 1:
                                          goto filtt;
                                          break;
                                      case 2:
                                          goto menu;
                                          break;
                                      case 3:
                                          goto log;
                                          break;
                                      case 4: {
                                          fileeee::write_user(Users);
                                          exit(0);
                                      }
                                          break;
                                      default: {
                                          cout << "                                               "
                                               << "wrong choice1 try again" << endl;
                                          continue;
                                      }

                                  }

                              }
                          }
                              break;
                          default:
                              cout << "                                               " << "wrong choice1" << endl;
                              continue;

                      }

                      int choic;
                      while(true) {
                          cout << "                                               " << "Enter choice" << endl;
                          cout << "                                               " << "1-Try another filter" << endl;
                          cout << "                                               " << "2-Main Menu" << endl;
                          cout << "                                               " << "3- Log-out" << endl;
                          cout << "                                               " << "4- Exit" << endl;
                          cin >> choic;

                          if (choic == 1) {
                              break;
                          } else if (choic == 2) {
                              goto menu;
                          } else if (choic == 3) {
                              goto log;
                          } else if (choic == 4) {
                              fileeee::write_user(Users);
                              exit(0);
                          } else {
                              continue;
                          }

                      }
                      if(choic==1)
                      {
                          continue;
                      }
                  }
              }
              break;
              case 4 :
              {
                  bool cash=false,credit=false,depit=false;
                  system("CLS");
                  display_pattern();
                  cash=Users[valid_user_index].getMonthlyIncome().back().isCashCheck();
                  credit=Users[valid_user_index].getMonthlyIncome().back().isCreditCardCheck();
                  depit=Users[valid_user_index].getMonthlyIncome().back().isDebitCardCheck();


                  display_remaining_money(valid_user_index,Users[valid_user_index].getMonthlyIncome().size()-1,cash,credit,depit);


                  int choic;
                  while(true) {
                      cout << "                                               " << "Enter choice" << endl;
                      cout << "                                               " << "1-Main Menu" << endl;
                      cout << "                                               " << "2- Log-out" << endl;
                      cout << "                                               " << "3- Exit" << endl;
                      cin >> choic;


                      if (choic == 1) {
                          goto menu;
                      } else if (choic == 2) {
                          goto log;
                      } else if (choic == 3) {
                          fileeee::write_user(Users);
                          exit(0);
                      } else {
                          continue;
                      }

                  }

              }
              break;
              case 5:
              {
                  bool cash=false,credit=false,depit=false;
                  system("CLS");
                  display_pattern();
                  cash=Users[valid_user_index].getMonthlyIncome().back().isCashCheck();
                  credit=Users[valid_user_index].getMonthlyIncome().back().isCreditCardCheck();
                  depit=Users[valid_user_index].getMonthlyIncome().back().isDebitCardCheck();
                  display_dept_of_lastmonth(valid_user_index,cash,depit,credit);

                  int choic;
                  while(true) {
                      cout << "                                               " << "Enter choice" << endl;
                      cout << "                                               " << "1-Main Menu" << endl;
                      cout << "                                               " << "2- Log-out" << endl;
                      cout << "                                               " << "3- Exit" << endl;
                      cin >> choic;


                      if (choic == 1) {
                              goto menu;
                      } else if (choic == 2) {
                          goto log;
                      } else if (choic == 3) {
                          fileeee::write_user(Users);
                          exit(0);
                      } else {
                          continue;
                      }

                  }


              }
              break;
              case 6:
              {
                goto log;
              }
              break;
              case 7:{
                  fileeee::write_user(Users);
                  exit(0);
              }

              default: {
                  cout << "                                               " << "wrong choice try again" << endl;
                  continue;
              }
          }


      }


    }
    else
    {   sign:
        string username_log;
        string email_log;
        string password_log;

        bool exist=false;

         system("CLS");
      display_pattern();
        cout << "\n                                             " << "Sign-UP" <<"\n\n";

        cout << "                                             " << "Enter your User Name" << endl;
        cin >>username_log;
        cout << "                                             " << "Enter your Email" << endl;
        cin >>email_log;
        cout << "                                             " << "Enter your Password" << endl;
        cin >>password_log;

        for(int i=0;i<Users.size();i++)
        {
            if(Users[i].getEMail().compare(email_log)==0)
            {
                exist=true;
                break;
            }
            else
            {
                continue;
            }
        }

        if(exist) {
            cout << "                                             " << "There are exist an account with this E-Mail"
                 << endl;
            int choic;
            while (true) {
                cout << "                                               " << "Enter choice" << endl;
                cout << "                                               " << "1- Sign-UP again" << endl;
                cout << "                                               " << "2- Log-IN" << endl;
                cout << "                                               " << "3- Exit" << endl;
                cin >> choic;


                if (choic == 1) {
                    goto sign;
                } else if (choic == 2) {
                    goto log;
                } else if (choic == 3) {
                    fileeee::write_user(Users);
                    exit(0);
                } else {
                    continue;
                }


            }
        }
        else {
            int id=0;
            if (Users.size()==0) {
                id = 1;
            } else {
                id = Users.back().get_id() + 1;
            }

            User newuser(id, username_log,email_log, password_log);
            Users.push_back(newuser);

            cout << "                                             " << "Account created successfully" << endl;

            int choic;
            while (true) {
                cout << "\n                                               " << "Enter choice" << endl;
                cout << "                                               " << "1- Menu" << endl;
                cout << "                                               " << "2- Exit" << endl;
                cin >> choic;


                if (choic == 1) {
                    goto log;
                } else if (choic == 2) {
                    fileeee::write_user(Users);
                    exit(0);
                } else {
                    continue;
                }

            }
        }
    }


//    fileeee::write_user(Users);

    return 0;
}

void display_pattern()
{
    cout<<"***********************************************************************************************************************";
    cout<<"                                                Monthly expenses system                                                  ";
    cout<<"***********************************************************************************************************************";

}
void take_amount(int valid_user_index,const string& category,bool cash,bool depit,bool credit,double amount)
{
    if(cash&&depit&&credit)
    {
        int choice;

        while(true) {
            cout << "                                               "
                 << "choice wallet to take Price of Expanses From " << endl;
            cout << "                                               " << "1-cash" << endl;
            cout << "                                               " << "2-credit card" << endl;
            cout << "                                               " << "3-depit card" << endl;
            cin>>choice;

            switch (choice)
            {
                case 1:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemaningCash()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);
                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in cash wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to cash-depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemaningCash();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount-sub);
                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("cash",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);

                        }
                        else{
                            continue;
                        }
                    }

                }
                    break;
                case 2:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in credit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to credit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("credit",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);

                        }
                        else{
                            continue;
                        }
                    }
                }
                    break;
                case 3:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in depit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to depit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("depit",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);

                        }
                        else{
                            continue;
                        }
                    }
                }
                    break;
                default:
                    continue;
            }

            break;

        }
    }
    else if(cash&&!depit&&credit)
    {
        int choice;

        while(true) {
            cout << "                                               "
                 << "choice wallet to take Price of Expanses From " << endl;
            cout << "                                               " << "1-cash" << endl;
            cout << "                                               " << "2-credit card" << endl;
            cin>>choice;

            switch (choice)
            {
                case 1:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemaningCash()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in cash wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to cash-depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemaningCash();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("cash",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);

                        }
                        else{
                            continue;
                        }
                    }

                }
                    break;
                case 2:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in credit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to credit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("credit",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);

                        }
                        else{
                            continue;
                        }
                    }
                }
                    break;
               default:
                    continue;
            }

                break;
        }
    }
    else if(cash&&depit&&!credit)  ///****************************************************************************
    {
        int choice;

        while(true) {
            cout << "                                               "
                 << "choice wallet to take Price of Expanses From " << endl;
            cout << "                                               " << "1-cash" << endl;
            cout << "                                               " << "2-depit card" << endl;
            cin>>choice;

            switch (choice)
            {
                case 1:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemaningCash()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);
                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in cash wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to cash-depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemaningCash();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount-sub);


                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("cash",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);
                        }
                        else{
                            continue;
                        }
                    }

                }
                    break;
                case 2:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in depit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to depit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {

                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("depit",amount);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);

                        }
                        else{
                            continue;
                        }
                    }
                }
                    break;
                default:
                    continue;
            }

            break;

        }

    }
    else if(cash&&!depit&&!credit)
    {
        int choice;

        while(true) {
            cout << "                                               "
                 << "choice wallet to take Price of Expanses From " << endl;
            cout << "                                               " << "1-cash" << endl;
            cin>>choice;

            switch(choice)
            {
                case 1:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemaningCash()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in cash wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to cash-depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {

                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemaningCash();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("cash",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("cash",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"cash",amount);

                        }
                        else{
                            continue;
                        }
                    }

                }
                    break;
                default:
                    continue;
            }

            break;
        }
    }
    else if(!cash&&depit&&credit)
    {
        int choice;

        while(true) {
            cout << "                                               "
                 << "choice wallet to take Price of Expanses From " << endl;
            cout << "                                               " << "1-credit card" << endl;
            cout << "                                               " << "2-depit card" << endl;
            cin>>choice;

            switch (choice)
            {
                case 1:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in credit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to credit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("credit",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                }
                    break;
                case 2:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);

                        break;
                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in depit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to depit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount-sub);

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("depit",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                }
                    break;
                default:
                    continue;
            }

            break;
        }
    }
    else if(!cash&&depit&&!credit)
    {
        int choice;

        while(true) {
            cout << "                                               "
                 << "choice wallet to take Price of Expanses From " << endl;
            cout << "                                               " << "1-depit card" << endl;
            cin>>choice;

            switch (choice)
            {
                case 1:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);

                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in depit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to depit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {   int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("depit",amount-sub);
                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("depit",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"depit-card",amount);
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                }
                    break;
                default:
                    continue;
            }

            break;
        }
    }
    else if(!cash&&!depit&&credit)
    {
        int choice;

        while(true) {
            cout << "                                               "
                 << "choice wallet to take Price of Expanses From " << endl;
            cout << "                                               " << "1-credit card" << endl;

            cin>>choice;

            switch (choice)
            {
                case 1:
                {
                    if(Users[valid_user_index].getMonthlyIncome().back().getRemainingCredit()>=amount)
                    {
                        Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount);
                        User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);
                    }
                    else
                    {
                        int choice1;
                        cout << "                                          " << "ATTENTION" << endl;
                        cout << "                                     " << "you Don't have enough money in credit card wallet" << endl;
                        cout << "                                     " << "1-Do you want to add exoanse amount to credit card -depit" << endl;
                        cout << "                                     " << "2-Try another pay option" << endl;
                        cin >> choice1;
                        if(choice1 == 1)
                        {
                            int sub=amount-Users[valid_user_index].getMonthlyIncome().back().getRemainingDepit();

                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount("credit",amount-sub);
                            Users[valid_user_index].getMonthlyIncome().back().addexpanseamount_to_depit("credit",sub);
                            User::add_expanse_tovector(Expances,Users,valid_user_index,category,"credit-card",amount);
                            break;
                        }
                        else{
                            continue;
                            continue;
                        }
                    }
                }
                    break;
                    break;
                default:
                    continue;
            }

            break;
        }
    }
}

void display_remaining_money(int valid_user_index,int index,bool cash,bool credit,bool depit)
{
    if(cash&&depit&&credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemaningCash()<< endl;
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingCredit()<< endl;
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingDepit()<< endl;
    }
    else if(cash &&!depit&&credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemaningCash()<< endl;
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingCredit()<< endl;

    }
    else if(cash && depit&&!credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemaningCash()<< endl;
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingDepit()<< endl;
    }
    else if(!cash &&depit&&credit)
    {
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingCredit()<< endl;
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingDepit()<< endl;
    }
    else if(cash && !depit&&!credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemaningCash()<< endl;

    }
    else if(!cash &&depit&&!credit)
    {
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingDepit()<< endl;
    }
    else if(!cash &&!depit&&credit)
    {
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getRemainingCredit()<< endl;

    }
}
void display_dept_money(int valid_user_index,int index,bool cash,bool credit,bool depit)
{
    if(cash&&depit&&credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCashDept()<< endl;
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCreditCardDebit()<< endl;
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getDebitCardDebit()<< endl;
    }
    else if(cash &&!depit&&credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCashDept()<< endl;
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCreditCardDebit()<< endl;

    }
    else if(cash && depit&&!credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCashDept()<< endl;
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getDebitCardDebit()<< endl;
    }
    else if(!cash &&depit&&credit)
    {
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCreditCardDebit()<< endl;
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getDebitCardDebit()<< endl;
    }
    else if(cash && !depit&&!credit)
    {
        cout << "                                      " << "cash :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCashDept()<< endl;

    }
    else if(!cash &&depit&&!credit)
    {
        cout << "                                      " << "depit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getDebitCardDebit()<< endl;
    }
    else if(!cash &&!depit&&credit)
    {
        cout << "                                      " << "credit-card :" <<
             Users[valid_user_index].getMonthlyIncome()[index].getCreditCardDebit()<< endl;

    }
}

void display_dept_of_lastmonth(int valid_user_index,bool cash,bool depit,bool credit)
{
    if(Users[valid_user_index].getMonthlyIncome().size()>1) {
        cout << "\n                                      " << "Your saving money from last month" << "\n\n";
        display_remaining_money(valid_user_index, Users[valid_user_index].getMonthlyIncome().size() - 2, cash, credit,
                                depit);
        cout << "\n\n                                      " << "Your depit from last month" << "\n\n";
        display_dept_money(valid_user_index, Users[valid_user_index].getMonthlyIncome().size() - 2, cash, credit,
                           depit);

    }
    else{
        cout << "\n "<< "Sorry this is your first month with us so you don't have saving or debit money "<<endl;
    }
}

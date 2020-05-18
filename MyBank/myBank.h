#ifndef _MYBANK_H_
#define _MYBANK_H_

#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM_OF_ACCOUNTS (50)
#define ACCOUNT_ID_OFFSET (901)
#define STATUS_OPENED (true)
#define STATUS_CLOSED (false)

//cdoublereat accounts double array in size 50x2
//double AccountsBalanceArray [MAX_NUM_OF_ACCOUNTS] = {0};
//bool AccountsStatusArray [MAX_NUM_OF_ACCOUNTS] = {0};


extern char key;
extern double AccountsBalanceArray[];
extern bool AccountsStatusArray[];

bool openAccount(double first_deposit , int* account_number);
bool getBalance(int account_number, double* balance);//2
bool deposit(int account_number,double ammount);//3
bool withdraw(int account_number, double ammount);//4
bool closeAccount( int account_number);//5
void printAccounts();//6
void interst_rate(double rate);//7
void exitBank();//1
int accountToIndex(int account_number);
int indexToAccount(int index);
bool isOpenedAccount(int account_number);
bool isInKeyWord(char c);

#endif

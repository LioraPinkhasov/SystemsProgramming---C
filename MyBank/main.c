#include <stdio.h>
#include <ctype.h>
#include "myBank.h"
#include <stdbool.h>

//extern double AccountsArray ;
//extern char key;

int main()
{

	setbuf(stdout,NULL);
	key = 'P';
	double deposite = 0;
	int interest = 0;
 	int accountNumber = 0;
	int i = 0;

	printf("Welcome to GML Bank!\n");
	while(key != 'E'){
		printf("Please enter key:\n");
		scanf("%c", &key);

		while(!isInKeyWord(key) || key == '\n'){
			if(key != '\n'){
				printf("Error, invalid key entered\n");
				printf("Please enter key:\n");
			}
			scanf("%c", &key);
		}
		switch (key) {
			case 'O':

				printf("Enter deposite:\n");
				scanf("%lf", &deposite);
				openAccount(deposite, &accountNumber);
				i = accountToIndex(accountNumber);
				printf("The account number %d current balance %0.2lf: \n", accountNumber, AccountsBalanceArray[i]);
				break;

			case 'P':
				printAccounts();
				break;

			case 'C':
				printf("Enter Your Account Number please:\n");
				scanf("%d",&accountNumber);
				printf(closeAccount(accountNumber) == false ? "Account doesnt exist\n" : "Account delete succesfully\n");
				break;
			case 'B':
				printf("Enter Account number:\n");
				scanf("%d", &accountNumber);
				getBalance(accountNumber, &deposite);
				i = accountToIndex(accountNumber);
				printf("The account number %d current balance %0.2lf: \n", accountNumber, AccountsBalanceArray[i]);
				break;
			case 'I':
				printf("Please enter interest rate:\n");
				scanf("%d", &interest);
				interst_rate(interest);
				break;
			case 'W':
				printf("Enter Account number:\n");
				scanf("%d", &accountNumber);
				while(!isOpenedAccount(accountNumber)){
					printf("Please enter valid account number:\n");
					scanf("%d", &accountNumber);
				}
				printf("Enter how much money would you like to withdraw?\n");
				scanf("%lf", &deposite);
				i = accountToIndex(accountNumber);
				if(withdraw(accountNumber, deposite)){
					printf("Your current balance is %0.2lf\n",AccountsBalanceArray[i]);
				}else{
					printf("You dont have enough money for this withraw\n");
				}
				break;
			case 'D':
				printf("Enter Account number:\n");
				scanf("%d", &accountNumber);
				while(!isOpenedAccount(accountNumber)){
					printf("Please enter valid account number:\n");
					scanf("%d", &accountNumber);
				}
				printf("Enter how much money would you like to deposite?\n");
				scanf("%lf", &deposite);
				i = accountToIndex(accountNumber);
				if(deposit(accountNumber, deposite)){
					printf("Your current balance is %0.2lf\n",AccountsBalanceArray[i]);
				}else{
					printf("You cant deposite negative numbers\n");
				}
				break;
			case 'E':
				exitBank();
				break;
			default:
				break;
		}
		printf("Thank you for your visit at the bank!\n");
	}



	return 0;
}

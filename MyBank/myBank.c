#include "myBank.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


//int FreeSpace=0;
//int CorrectFreeSpace=0;



char key = ' ';

double AccountsBalanceArray [MAX_NUM_OF_ACCOUNTS] = {0};
bool AccountsStatusArray [MAX_NUM_OF_ACCOUNTS] = {0};


bool openAccount(double first_deposit , int* account_number)
{
	//return false if the first deposit is negative or Zero.
	if(first_deposit <= 0)
	{
		return false;
	}
	int i;//index
	for(i = 0; i < MAX_NUM_OF_ACCOUNTS; i++)//run over the account array, until you find a closed account, and do not search any further!
	{
		if(AccountsStatusArray[i] == STATUS_CLOSED)
		{//if you found a free space for the new account
			
			AccountsStatusArray[i] = STATUS_OPENED;//change status to "open account"
			AccountsBalanceArray[i] = first_deposit;//now add the first_deposit to the balance
			*account_number = (ACCOUNT_ID_OFFSET + i);
			//printing the massege
			//printf("Congratulation youve opened a new account in M&P.ltd digital bank! your account number is %d and it's current balance is %lf\n",account_number,AccountsArray[i][1]);
			return true;
		}
    }
	return false;
	//	printf("We are very sorry but we cannot except your money due to lack of storage space in out bank...yes we are That rich!\n");
}

bool getBalance(int account_number, double* balance)
{
	// check if account number recived is valid
	if(!isOpenedAccount(account_number))
		return false;
	// Recived a valid account ID, put the balance in the pointer
	*balance = AccountsBalanceArray[account_number - ACCOUNT_ID_OFFSET];
	return true;
}


bool deposit(int account_number,double ammount)//3
{

	if(ammount < 0)
	return STATUS_CLOSED;//if you try to deposit a negative number, return false;

	int index = accountToIndex(account_number);//function that help us find the correct index of an account in out array.
	if(AccountsStatusArray[index] == STATUS_OPENED)
	{//if this account is a valid open account.
		AccountsBalanceArray[index] = (AccountsBalanceArray[index]+ammount);//you can deposit the ammount in it.
	}
	else //this account is closed, tell the user about it
	{
		return STATUS_CLOSED;
	}

return true;
}


bool withdraw(int account_number, double ammount)//4
{
	int index = accountToIndex(account_number);//function that help us find the correct index of an account in out array.
	if((ammount < 0)|| (ammount > AccountsBalanceArray[index]))
	return STATUS_CLOSED;//if you try to withdraw a negative number,or more then this account has, return false;

	if(AccountsStatusArray[index] == STATUS_OPENED)
	{//if this account is a valid open account.
		AccountsBalanceArray[index] = (AccountsBalanceArray[index]-ammount);//you can deposit the ammount in it.
	}
	else //this account is closed, tell the user about it
	{
		return STATUS_CLOSED;
	}

return true;
}
/**
 * this boolean method returns true only if an account_number given is in STATUS_OPENED
 * zeroing its balance , and changing the Status to STATUS_CLOSED
*/

bool closeAccount( int account_number)//5
{
	int index = accountToIndex(account_number);//function that help us find the correct index of an account in out array.
	if (isOpenedAccount(account_number))//if account is exist and open
	{
			AccountsBalanceArray[index] = 0;//the balnce restored to Zero
			AccountsStatusArray[index] = STATUS_CLOSED;//Account is now closed
			return true;
	}
	//the account is not valid to be closed
	return false;
}
/**
 * this method will print all the opened accounts with their current Balance to the Console
 */

void printAccounts()//6
{
	for (int i=0;i<=MAX_NUM_OF_ACCOUNTS;i++)
	{
		if (AccountsStatusArray[i] == STATUS_OPENED)// check account status if open
		{
			printf("AccountNumber: %d, AccountBalance is: %0.2lf\n", (indexToAccount(i)),AccountsBalanceArray[i] ); //print account number + balance
		}
	}
}
/**
 * this method revcide a rate to be added into an accounts balance
 * the "updateRAteVAlue" uses the given rate,that will be multyplied by the current balance and devided by 100
 * this "updatedRateVAlue" will be added to your current balance
 * example with rate = 5, and balance 300
 * updateRateVAlue = 5*300/100 = 15
 * balance now is 315.
 */
void interst_rate(double rate)//7
{
	double updateRateVAlue = 0;
	for (int i=0;i< MAX_NUM_OF_ACCOUNTS;i++)//run on all elements in the array
	{
		if(AccountsStatusArray[i] == STATUS_OPENED ) // check if the account STATUS
			{//if its STATUS_OPENED
				updateRateVAlue =  ((rate)*AccountsBalanceArray[i]); //multiplay rate with the balance
				updateRateVAlue = updateRateVAlue/((double)100); //divirte with 100 float
				AccountsBalanceArray[i] = AccountsBalanceArray[i] + updateRateVAlue; //added balance with the rate
			}
	}

}
/**
 * this method will set all accounts to STATUS_CLOSED,and Zeroing all their balances
 */
void exitBank ()
{
	for( int i=0; i<=MAX_NUM_OF_ACCOUNTS; i++)//
		    {
			AccountsBalanceArray[i] = 0 ; //blance Zeroed
			AccountsStatusArray[i] = STATUS_CLOSED; //account is now STATUS_CLOSED
		    }
	key='E';
}


/**
 * this method recives an account number , and returns the correct index of this account in our data structure;
 * for example Account number  905 will return 4 .
 */

int accountToIndex(int account_number)
{
	int ans = (account_number - ACCOUNT_ID_OFFSET);
	return ans;
}
/**
 * this method recives an index in the account Array, and turn it into a valid account number
 * example: index = 5 return 906.
 */
int indexToAccount(int index)
{
	int ans = (index + ACCOUNT_ID_OFFSET);
	return ans;
}
/**
 * this boolean method checks if the account number we recived is indeed [901,950] and also if its status is opened
 * and ready to do a transaction
 */

bool isOpenedAccount(int account_number)
{
	// If recived invalid account number
	if ((account_number < ACCOUNT_ID_OFFSET) || (account_number > ACCOUNT_ID_OFFSET + MAX_NUM_OF_ACCOUNTS)
	 || (AccountsStatusArray[account_number - ACCOUNT_ID_OFFSET] == STATUS_CLOSED))
	{
		return false;
	}
	return true;
}

bool isInKeyWord(char c){
	return (c == 'E' || c == 'O' || c == 'B' || c == 'W' || c == 'D' || c == 'P' || c == 'I' || c == 'C');
}

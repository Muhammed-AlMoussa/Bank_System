#include<iostream>
#include"clsBankClient.h"
using namespace std;



int main()
{
	clsBankClient Client1 = clsBankClient::FindClient("A101");
	Client1.Print();

	clsBankClient Client2 = clsBankClient::FindClient("A101" , "12345");
	Client2.Print();


	return 0;
}
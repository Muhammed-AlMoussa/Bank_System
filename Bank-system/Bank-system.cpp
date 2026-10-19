#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();
	
	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\nEnter AccountBalance: ";
	Client.AccountBalance = clsInputValidate::ReadDblNumber("Invalide,Enter another one: ");
}

void UpdateClient()
{
	string AccountNumber = "";
	
	AccountNumber = clsInputValidate::ReadString();

	while (!(clsBankClient::IsClientExist(AccountNumber)))
	{
		cout << "\nClient Account Number is not found , Enter another one: ";
		AccountNumber = clsInputValidate::ReadString();

	}
	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\nUpdate Client Info:\n";
	cout << "\n----------------------\n";
	ReadClientInfo(Client1);
	//Client1.Email = "Mhf@gmail.com";

	//Client1.Save();
	clsBankClient::enSaveResult SaveResult;
	SaveResult = Client1.Save();

	switch (SaveResult)
	{

	case clsBankClient::enSaveResult::enSvSucceeded:
	{
		cout << "\nAccount Update it Successfuly\n";
		Client1.Print();
		break;
	}

	case clsBankClient::enSaveResult::enSvFailEmptyProject:
	{
		cout << "\nError account was not saved because it's Empty\n";
		break;
	}
	}
}

int main()
{
	UpdateClient();


	return 0;
}
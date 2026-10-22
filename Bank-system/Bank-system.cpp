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

void AddClient()
{
	cout << "\nEnter AccountNumber: ";
	string AccountNumber = clsInputValidate::ReadString();

	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccountNumber is found , please enter another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}
	
	clsBankClient Client1 = clsBankClient::GetNewClientObject(AccountNumber);

	ReadClientInfo(Client1);

	clsBankClient::enSaveResult SaveResult = Client1.Save();

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
	case clsBankClient::enSaveResult::enSvFailAccountNumberExist:
	{
		cout << "\nError account was not saved because the AccoutNumber Exist.\n";
		break;
	}
	}

		
}

void DeleteClient()
{
	char Accept = false;

	cout << "\nEnter AccountNumber: ";
	string AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccountNumber is not found , please enter another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();

	cout << "\nAre you sure? y/n";
	cin >> Accept;
	if (tolower(Accept) == 'y')
	{
		Client.Delete();
		cout << "\nClient Delete Successfuly\n";
		Client.Print();
	}
}
int main()
{
	DeleteClient();

	return 0;
}
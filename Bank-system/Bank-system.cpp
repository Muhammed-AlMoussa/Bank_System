#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>

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

void PrintClientRecordLine(clsBankClient Client)
{

	cout << "| " << setw(15) << left << Client.getAccountNumber();
	cout << "| " << setw(20) << left << Client.getFullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(12) << left << Client.AccountBalance << endl;;

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

void ShowClientList()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;



	if (vClients.size() == 0)
		cout << "\t\t\tClient List is Empty!\n";
	else
		for (clsBankClient& C : vClients)
		{
			PrintClientRecordLine(C);
		}
}
int main()
{
	
	ShowClientList();
	return 0;
}
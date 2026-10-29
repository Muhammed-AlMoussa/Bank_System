#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsBankClient.h"
#include<string>

using namespace std;

class clsShowClientListScreen : protected clsScreen
{
	//when u want to use a base class method u have to put it inside the drived class
private :
    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.Phone ;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

    static void _PrintClientListHeader()
    {
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

public :
	static void ShowClientListScreen()
	{
        if (!CheckUserPermissonsScreen(clsUser::enPermissions::pListClients))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "Client List Screen";
        string Subtitle = ("(" + to_string(vClients.size()) + " )Clients");
		_DrawScreenHeader(Title , Subtitle);

        _PrintClientListHeader();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (const clsBankClient& Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        
    };

};


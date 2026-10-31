#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

class clsShowTransferLogScreen :protected clsScreen
{
private:
	static void _PrintTransferLogRecord(clsBankClient::stTransferLog TransferLog)
	{
		cout << setw(8) << left << "" << "| " << left << setw(25) << TransferLog.DataTimeTransfer;
		cout << "| " << left << setw(10) << TransferLog.SourceAccNum ;
		cout << "| " << left << setw(10) << TransferLog.DestinationAccNum;
		cout << "| " << left << setw(8) << TransferLog.Amount;
		cout << "| " << left << setw(12) << TransferLog.SourceBalance ;
		cout << "| " << left << setw(12) << TransferLog.DestinationBalance ;
		cout << "| " << left << setw(10) << TransferLog.UserName;
	}
public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLog> vTransferInfo
			= clsBankClient::GetTransferLogList();

		string Title = "Transfer Log List Screen";
		string Subtitle = ("(" + to_string(vTransferInfo.size()) + ") Record(s)");

		_DrawScreenHeader(Title, Subtitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vTransferInfo.size() == 0)
		{
			cout << "Invalide Operation\n";
			return;
		}

		for (clsBankClient::stTransferLog& s : vTransferInfo)
		{
			_PrintTransferLogRecord(s);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}
};


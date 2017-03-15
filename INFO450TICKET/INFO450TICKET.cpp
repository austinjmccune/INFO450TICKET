// INFO450TICKET.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char answer;
int ticketCounter;
int sLowCount = 0;
int sMedCount = 0;
int sHighCount = 0;
int aLowCount = 0;
int aMedCount = 0;
int aHighCount = 0;
int cLowCount = 0;
int cMedCount = 0;
int cHighCount = 0;

class Ticket 
{
	static int IDGenerator;
	int ID;
	int usersImpacted;
	char issueType;
	string issueTypeS;
	string issueStatus;
	string issuePriority;
	string callerName;
	string description;

public:

	
	Ticket()
	{
		ID = IDGenerator++;
		ticketCounter++;
	}

	int getID() 
	{
		return ID;

	}
	void CaptureTicket()
	{
		
		cout << "What is your name?" << endl;
		getline (cin,callerName);
		cout << "Is this affecting a (S)erver,(A)pplication, or a(C)cess?" << endl;
		cin >> issueType;
		if (issueType == 'S' || issueType == 's')
		{
			issueTypeS = "Server";
		}
		else if (issueType == 'A' || issueType == 'a')
		{
			issueTypeS = "Application";
		}
		else if (issueType == 'C' || issueType == 'c')
		{
			issueTypeS = "Access";
		}
		else
		{
			issueTypeS = "Not submitted";
		}
		cin.ignore();
		cout << "Provide a description of the issue" << endl;
		getline(cin, description);

		cout << "How many users are impacted?" << endl;
		cin >> usersImpacted;
		if (usersImpacted < 10 && issueTypeS == "Server")
		{
			issuePriority = "Low";
			sLowCount++;
		}
		else if (usersImpacted < 10 && issueTypeS == "Application")
		{
			issuePriority = "Low";
			aLowCount++;
		}
		else if (usersImpacted < 10 && issueTypeS == "Access")
		{
			issuePriority = "Low";
			cLowCount++;
		}
		else if (usersImpacted >= 10 && usersImpacted < 50 && issueTypeS == "Server")
		{
			issuePriority = "Medium";
			sMedCount++;
		}
		else if (usersImpacted >= 10 && usersImpacted < 50 && issueTypeS == "Application")
		{
			issuePriority = "Medium";
			aMedCount++;
		}
		else if (usersImpacted >= 10 && usersImpacted < 50 && issueTypeS == "Access")
		{
			issuePriority = "Medium";
			cMedCount++;
		}
		else if (usersImpacted >= 50 && issueTypeS == "Server")
		{
			issuePriority = "High";
			sHighCount++;
		}
		else if (usersImpacted >= 50 && issueTypeS == "Application")
		{
			issuePriority = "High";
			aHighCount++;
		}
		else if (usersImpacted >= 50 && issueTypeS == "Access")
		{
			issuePriority = "High";
			cHighCount++;
		}
		cin.ignore();

		issueStatus = "Open";
		cout << "Your Ticket number is: " << ID  << endl;
		

	}


	void ShowTicket()
	{
		
		cout << "Ticket number: " << ID << endl;
		cout << "Ticket Information: " << endl;
		cout << "Caller name: " << callerName << endl;
		cout << "Type of issue: " << issueTypeS << endl;
		cout << "Description: " << description << endl;
		cout << "Users impacted: " << usersImpacted << endl;
		cout << "Ticket status is: " << issueStatus << endl;
		cout << "Ticket priority is: " << issuePriority << endl << endl;
		cout << "----------------------------------------------------------------------------" << endl;

	}
	void CloseTicket()
	{
		issueStatus = "closed";
		cout << "Ticket number " << ID << " has been closed" << endl << "----------------------------------------------------------------------------" << endl;
	}

};

int Ticket::IDGenerator = 1;


int main()
{
	Ticket* ticks[100];
	
	
	for (int i = 0; i < 100; i++)
	{
		cout << "Do you want to enter a ticket? Y/N " << endl;
		cin >> answer;
		cin.ignore();
		if (answer == 'Y' || answer == 'y')
		{
			ticks[i] = new Ticket();
			ticks[i]->CaptureTicket();
			
		}
		else if (answer == 'N' || answer == 'n')
		{
			break;
		}
		else
		{
			break;
		}


	}
	

	system("cls");

	cout << "                    LOW          MED          High" << endl << endl;
	cout << "SERVER               " << sLowCount << "             " << sMedCount << "             " << sHighCount << endl;
	cout << "APPLICATION          " << aLowCount << "             " << aMedCount << "             " << aHighCount << endl;
	cout << "ACCESS               " << cLowCount << "             " << cMedCount << "             " << cHighCount << endl;
	cout << "----------------------------------------------------------------------------" << endl << endl;
	


	for (int i = 0; i < ticketCounter; i++)
	{
		
		ticks[i]->ShowTicket();
	}

	ticks[0]->CloseTicket();
	
	

    return 0;
}


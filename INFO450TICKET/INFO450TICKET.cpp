// INFO450TICKET.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char answer;
int id = 1;
class Ticket 
{

	int tid;
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
		if (usersImpacted < 10)
		{
			issuePriority = "Low";
		}
		else if (usersImpacted >= 10 && usersImpacted < 50)
		{
			issuePriority = "Medium";
		}
		else if (usersImpacted >= 50)
		{
			issuePriority = "High";
		}
		cin.ignore();

		issueStatus = "Open";
		cout << "Your Ticket number is: " << tid << endl;
		

	}

	void getID(int i)
	{
		tid = i;
	}
	void ShowTicket()
	{
		cout << "Ticket number: " << tid << endl;
		cout << "Ticket Information: " << endl;
		cout << "Caller name: " << callerName << endl;
		cout << "Type of issue: " << issueTypeS << endl;
		cout << "Description: " << description << endl;
		cout << "Users impacted: " << usersImpacted << endl;
		cout << "Ticket status is: " << issueStatus << endl;
		cout << "Ticket priority is: " << issuePriority << endl << endl;

	}
	void CloseTicket()
	{
		issueStatus = "closed";
		cout << "Ticket number " << tid << " has been closed" << endl;
	}

};




int main()
{
	Ticket* ticks[100];
	
	
	for (int i = 0; i < 100; i++)
	{
		cout << "Do you want to enter a ticket? " << endl;
		cin >> answer;
		cin.ignore();
		if (answer == 'Y' || answer == 'y')
		{
			ticks[i] = new Ticket();
			ticks[i]->getID(id);
			ticks[i]->CaptureTicket();
			id++;
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
	


	for (int i = 0; i < id; i++)
	{
		ticks[i]->ShowTicket();
	}

	ticks[0]->CloseTicket();
	
	//testing testerson

    return 0;
}


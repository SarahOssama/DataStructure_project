#include "Parser.h"
#include"Rest/Restaurant.h"
Parser::Parser()
{

}


void Parser::setFileName(string fn)
{
	fileName = fn;
}

bool Parser::OpenFile(GUI* pGUI)
{
	pGUI->PrintMessage("Please enter File name you want to open = ");
	string fn = pGUI->GetString();
	setFileName(fn + ".txt");
	InFile.open(fileName, ios::in);
	if (InFile.is_open())
	{
		return true;
	}
	pGUI->PrintMessage("Cannot open the file..");
	return false;

}




void Parser::ReadFile(int& nN, int& nG, int& nV, int& sN, int& sG, int& sV, int& bo, int& bN, int& bG, int& bV, int& AutoP, int& M, Restaurant* pRest,Event*pEv)
{
	InFile >> nN >> nG >> nV; // number of normal/ vegan/ VIP cooks
	InFile >> sN >> sG >> sV; // speed of normal/ vegan/ VIP cooks
	InFile >> bo >> bN >> bG >> bV; // number of dishes before taking break/ break of normal/ vegan/ VIP cooks
	InFile >> AutoP; // limit for autopromotion
	InFile >> M; // number of events
	char evtype_line[25]; // event type whole line read once and then transformed into integers to be use as wrapper parameters
	int TS; //time step
	int id; // order id
	int money; // order paid money
	int size; // order size
	ORD_TYPE OT; //order type .. (enum)..parameter of arrival_event_constructor
	char ot;// order type ..(char)..loaded from the file
	for (int i = 0; i < M; i++)// calls wrapper function of pRest which by its turn calls the events_constructors
	{
		InFile.getline(evtype_line,25,'\0');
		int n = 0;
		char* newstr = new char[25]; //used to ignore spaces
		for (int i = 0; i < strlen(evtype_line); i++)
		{
			if (evtype_line[i] != ' ')
			{
				newstr[n] = evtype_line[i];
				n++;
			}
		}
		newstr[n] = '\0';


		switch (newstr[0])
		{
		case 'R':
			if (newstr[1] == 'N')//case for normal order
			{
				OT = TYPE_NRM;
			}
			else if (newstr[1] == 'G')//case for vegan order
			{
				OT = TYPE_VGAN;
			}
			else if (newstr[1] == 'V')//case for VIP order
			{
				OT = TYPE_VIP;
			}
			TS = newstr[2];
			id = newstr[3];
			size = newstr[4];
			money = newstr[5];
			pRest->Wrapper_Arrival(OT, TS, id, size, money, pEv);

				break;
		case 'P':
			break;
		case 'X':
			TS = newstr[1];
			id = newstr[2];
			pRest->Wrapper_Cancelation(TS, id, pEv);
			break;
		default:
			break;

		}
		delete[]newstr;
	}
	InFile.close();
}

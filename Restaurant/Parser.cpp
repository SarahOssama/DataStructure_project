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




void Parser::ReadFile(int& nN, int& nG, int& nV, int& sN, int& sG, int& sV, int& bo, int& bN, int& bG, int& bV, int& AutoP, int& M, Restaurant* pRest)
{
	InFile >> nN >> nG >> nV;
	InFile >> sN >> sG >> sV;
	InFile >> bo >> bN >> bG >> bV;
	InFile >> AutoP;
	InFile >> M;
	for (int i = 0; i < M; i++)// calls wrapper function of pRest which by its turn calls the events_constructors
	{
		//pRest->Just_A_Demo();
	}
	InFile.close();
}

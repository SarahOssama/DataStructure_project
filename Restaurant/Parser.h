

#pragma once
#include"GUI/GUI.h"
//#include"Rest/Restaurant.h"
#include"Defs.h"
#include <fstream>

//// The main purpose of this class is to maintain program modularity and maintainability
//// If we change the input way , this is the only class to be modified
//// As the restaurant class will be based on a single type of inputs
class Restaurant;
class Parser
{
private:
	ifstream InFile;
	string fileName;

public:
	Parser();
	void setFileName(string fn);
	bool OpenFile(GUI* pGUI);
	void ReadFile(int& nN, int& nG, int& nV, int& sN, int& sG, int& sV, int& bo, int& bN, int& bG, int& bV, int& AutoP, int& M, Restaurant* pRest,Event*pEv);
};


#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;
#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
#include "..\Events\CancelEvent.h"
#include"..\Events\PromotionEvent.h"
#include"..\Parser.h"


Restaurant::Restaurant() 
{
	pGUI = NULL;
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		Prsr->OpenFile(pGUI);
		//Prsr->ReadFile();
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		Just_A_Demo();

	};

}



//////////////////////////////////  Event handling functions   /////////////////////////////

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current timestep
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}


//Wrapper function for arrival event

void Restaurant::Wrapper_Arrival(ORD_TYPE& r_Type, int& TS, int& id, int& size, int& mony, Event* pEv)
{
	pEv = new ArrivalEvent(TS, id, r_Type, mony, size);
	EventsQueue.enqueue(pEv);
}

// Wrapper function for cancel event

void Restaurant::Wrapper_Cancelation(int& TS, int& id, Event* pEv)
{
	pEv = new CancelEvent(TS, id);
	EventsQueue.enqueue(pEv);
}
// Wrapper function promotion event

void Restaurant::Wrapper_Promote(int& TS, int& id, int& exmony, Event* pEv)
{
	pEv = new PromotionEvent(TS,id,exmony);
	EventsQueue.enqueue(pEv);
}



Restaurant::~Restaurant()
{
		if (pGUI)
			delete pGUI;
}

void Restaurant::FillDrawingList()
{
	//This function should be implemented in phase1
	//It should add ALL orders and Cooks to the drawing list
	//It should get orders from orders lists/queues/stacks/whatever (same for Cooks)
	//To add orders it should call function  void GUI::AddToDrawingList(Order* pOrd);
	//To add Cooks it should call function  void GUI::AddToDrawingList(Cook* pCc);
	int size = 0;
	Cook** pCook = Cook_V_Q.toArray(size);
	for (int i = 0; i < size; i++)
	{
		pGUI->AddToDrawingList(pCook[i]);
	}

	
}

 
//to delete any order  will technically do the same in each type
bool Restaurant::DeleteOrder(int ID)
{
	Order* pOrder = NormalOrder_L.GetOrderFromID(ID);     //to look for the Order to be deleted
	if (pOrder)
	{
		ORD_STATUS status = pOrder->getStatus();

		if (status == WAIT)
			return NormalOrder_L.DeleteNode(pOrder); // To delete the Order (esm funny keda)

	}
	return false;
}


//Adding order to a queue
void Restaurant::AddtoQueue(Order* pOrder)
{
	ORD_TYPE type = pOrder->GetType();
	

	switch (type)
	{
	case TYPE_NRM:

		NormalOrder_L.InsertEnd(pOrder);

		break;

	case TYPE_VGAN:

		VeganOrder_Q.enqueue(pOrder);

		break;

	case TYPE_VIP:

			VIPOrder_Q.enqueue(pOrder);
	
		break;

	default:

		return ;

	}
	
}


void Restaurant:: PromoteOrder(int ID)
{
	Order* pOrder = NormalOrder_L.GetOrderFromID(ID);
	if (pOrder)
	{
		Order* TempOrder = pOrder;
		pOrder->setType(TYPE_VIP);
		AddtoQueue(pOrder);
		bool deleted = NormalOrder_L.DeleteNode(TempOrder);

	}
		
		
	
	                  
}


//////////////////////////////////////////////////////////////////////////////////////////////
/// ==> 
///  DEMO-related functions. Should be removed in phases 1&2

//Begin of DEMO-related functions

//This is just a demo function for project introductory phase
//It should be removed starting phase 1
void Restaurant::Just_A_Demo()
{
	
	//
	// THIS IS JUST A DEMO FUNCTION
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	
	int EventCnt;	
	Order* pOrd;
	Event* pEv;
	srand(time(NULL));

	pGUI->PrintMessage("Just a Demo. Enter EVENTS Count(next phases should read I/P filename):");
	EventCnt = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->PrintMessage("Generating Events randomly... In next phases, Events should be loaded from a file...CLICK to continue");
	pGUI->waitForClick();
		
	//Just for sake of demo, generate some cooks and add them to the drawing list
	//In next phases, Cooks info should be loaded from input file
	int C_count = 12;	
	Cook *pC = new Cook[C_count];
	int cID = 1;

	for(int i=0; i<C_count; i++)
	{
		cID+= (rand()%15+1);	
		pC[i].setID(cID);
		pC[i].setType((ORD_TYPE)(rand()%TYPE_CNT));
	}	

		
	int EvTime = 0;

	int O_id = 1;
	
	//Create Random events and fill them into EventsQueue
	//All generated event will be "ArrivalEvents" for the demo
	for(int i=0; i<EventCnt; i++)
	{
		O_id += (rand()%4+1);		
		int OType = rand()%TYPE_CNT;	//Randomize order type		
		EvTime += (rand()%5+1);			//Randomize event time
		pEv = new ArrivalEvent(EvTime,O_id,(ORD_TYPE)OType);
		EventsQueue.enqueue(pEv);

	}	

	// --->   In next phases, no random generation is done
	// --->       EventsQueue should be filled from actual events loaded from input file

	
	
	
	
	//Now We have filled EventsQueue (randomly)
	int CurrentTimeStep = 1;
	

	//as long as events queue is not empty yet
	while(!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep,timestep,10);	
		pGUI->PrintMessage(timestep);


		//The next line may add new orders to the DEMO_Queue
		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
		

/////////////////////////////////////////////////////////////////////////////////////////
		/// The next code section should be done through function "FillDrawingList()" once you
		/// decide the appropriate list type for Orders and Cooks
		
		//Let's add ALL randomly generated Cooks to GUI::DrawingList
		for(int i=0; i<C_count; i++)
			pGUI->AddToDrawingList(&pC[i]);
		
		//Let's add ALL randomly generated Ordes to GUI::DrawingList
		int size = 0;
		Order** Demo_Orders_Array = DEMO_Queue.toArray(size);
		
		for(int i=0; i<size; i++)
		{
			pOrd = Demo_Orders_Array[i];
			pGUI->AddToDrawingList(pOrd);
		}
/////////////////////////////////////////////////////////////////////////////////////////

		pGUI->UpdateInterface();
		Sleep(1000);
		CurrentTimeStep++;	//advance timestep
		pGUI->ResetDrawingList();
	}

	delete []pC;


	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();

	
}
////////////////

void Restaurant::AddtoDemoQueue(Order *pOrd)
{
	DEMO_Queue.enqueue(pOrd);
}

/// ==> end of DEMO-related function
//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////Interactive mode function////////////////////////////////////

void Restaurant::Interactive_mode()
{
	pGUI->PrintMessage("Welcome to the Interactive Mode !!...");

	int nNormal,nVegan,nVIP; // Number of normal , vegan , vip cooks
	int spd_Nrm, spd_Vgn, spd_VIP; //Speed of each type of cooks
	int brk_o; // Number of dishes that a cook must finish before break
	int brk_Nrm, brk_Vgn, brk_VIP;  // break period in timesteps
	int Autopromo; // limit for autopromotion
	int nEvnt;// number of events

	Restaurant* pRest;
	Event* pEv;
	Order* pOrder;
	Cook* pCook;

	int cook_count; // number of all cooks in the restaurant
	cook_count = nNormal + nVegan + nVIP;
	int cID = 0;
	
	if (Prsr->OpenFile(pGUI))
	{
		Prsr->ReadFile(nNormal, nVegan, nVIP, spd_Nrm, spd_Vgn, spd_VIP, brk_o, brk_Nrm, brk_Vgn, brk_VIP, Autopromo, nEvnt, pRest, pEv);
	}
	//// Ids will not be repeated , as VIP are the most important we will assign to them the first set of Ids 
	for (int i = 0; i < nVIP; i++)
	{
		cID++;
		pCook = new Cook(cID,TYPE_VIP,spd_VIP,brk_o,brk_VIP);
		Cook_V_Q.enqueue(pCook);
	}

	for (int i = 0; i < nNormal; i++)
	{
		cID++;
		pCook = new Cook(cID, TYPE_NRM, spd_Nrm, brk_o, brk_Nrm);
		Cook_N_Q.enqueue(pCook);

	}
	for (int i = 0; i < nVegan; i++)
	{
		cID++;
		pCook = new Cook(cID, TYPE_VGAN, spd_Vgn, brk_o, brk_Vgn);
		Cook_G_Q.enqueue(pCook);
	}

	


}


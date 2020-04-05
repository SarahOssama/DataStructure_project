#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"


#include "Order.h"
class Parser;  //forward declaration to class Parser
// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Parser* Prsr; ///parser pointer to call it to open and read the file
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file

	
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>
	
	
	
	//
	// TODO: Add More Data Members As Needed
	//

	Queue <Order*> VIPOrder_Q;  //Queue for VIP orders

	Queue <Order*> NormalOrder_Q;  //Queue for Normal orders

	Queue <Order*> VeganOrder_Q;  //Queue for Vegan orders
	
	Queue<Cook*> Cook_V_Q;
	Queue<Cook*> Cook_N_Q;
	Queue<Cook*> Cook_G_Q;

public:
	
	Restaurant();
	~Restaurant();
	
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	


	void FillDrawingList();

	//
	// TODO: Add More Member Functions As Needed
	//
	////////////////////////////////////////////////
	//// Function Wrapper is a function that will be called in the Parser class 
	//// The purpose of this function is to get usage of the input taken from the file processing operation
	//// Espcially for the lines defining the events ,without breaking the classes responsabilities,
	//// As the restaurant class will be the responsible of taking any precautions before calling the event_constructors
	////////////////////////////////////////////////

	//void Wrapper_Arrival(ORD_TYPE &r_Type,int &TS,int &id, int &size, int& mony);
	//void Wrapper_Cancelation(int &TS, int& id);
	//void Wrapper_Promote(int &TS, int& id, int& exmony);




	bool DeleteOrder(Order* pOrder); //to Delete an order
	void AddtoQueue(Order* pOrder); //to add order to queue

/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 

	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

/// ================================================================================================== 



};

#endif
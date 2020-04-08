#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data)
	{
		Node<T>* P = Head;
		Node<T>* R = new Node<T>(data);

		if (Head == nullptr)
		{
			Head = R;
			return;
		}



		while (P->getNext())
			P = P->getNext();

		P->setNext(R);

		return;
	}



	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	T Find(T Key)
	{
		Node<T>* P = Head;
		while (P)
		{
			if (P == Key)
			{
				return P;
			}
			P = P->getNext();
		}
		return ;

	}


	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value)
	{
		int Count = 0;
		Node<T>* P = Head;
		while (P)
		{
			if (P->getItem() == value)
			{
				Count++;

			}
			P = P->getNext();
		}


		return Count;
	}



	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst()
	{
		Node<T>* P = Head;

		if (Head)
		{
			Head = P->getNext();
			delete P;
			return;
		}

		cout << "List is empty" << endl;
		return;

	}



	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast()
	{
		Node<T>* P = Head;
		if (!P)
		{
			cout << "List is Empty" << endl;
			return;
		}
		while (P->getNext())
		{
			if ((P->getNext()->getNext()) == nullptr)
			{
				Node <T>* R = P->getNext();
				P->setNext(nullptr);
				delete R;
				return;
			}
			P = P->getNext();
		}
		Head = nullptr;
		delete P;
		return;


	}


	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value)
	{
		Node<T>* P = Head;


		while (P)
		{
			/*if (P->getItem()==value && (P->getNext()->getItem()==nullptr))
			{
				Head=nullptr;
				delete P;
				cout << "Now the list is empty"<<endl;
				return true;
			}*/
			if (P->getItem() == value)
			{
				Head = P->getNext();
				delete P;
				cout << "Now the list is empty" << endl;
				return true;
			}
			if (P->getNext()->getItem() == value)
			{
				Node <T>* R = P->getNext();
				P->setNext(R->getNext());
				delete R;
				return true;
			}
			P = P->getNext();
		}

		return false;

	}


	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value)
	{
		Node<T>* P = Head;


		while (P)
		{
			/*if (P->getItem()==value && (P->getNext()->getItem()==nullptr))
			{
				Head=nullptr;
				delete P;
				cout << "Now the list is empty"<<endl;
				return true;
			}*/
			if (P->getItem() == value)
			{
				Head = P->getNext();
				delete P;
				cout << "Now the list is empty" << endl;

			}
			if (P->getNext()->getItem() == value)
			{
				Node <T>* R = P->getNext();
				P->setNext(R->getNext());
				delete R;

			}
			P = P->getNext();
		}

		return false;
	}


	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L)
	{

	}


	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();


	//[10] GetOrderFromID
	//Returns the order from its ID
	Order* GetOrderFromID(int ID)
	{
		Order* SearchOrder = Head->getItem();

		while (SearchOrder)
		{
			if (SearchOrder->GetID() == ID)
			{
				return SearchOrder;
			}
		}
		return nullptr;
	}


	//[11] IsEmpty

	bool IsEmpty()
	{
		if (Head == nullptr)
			return true;
		else
			return false;

	}

	//[12] get first node in the List 
	bool GetfirstNode(T& order)
	{
		if (Head == nullptr)
			return false;
		else
		{
			Node<T>* tempPtr = Head;
			order = Head->getItem();
			Head = Head->getNext();
			delete tempPtr;
			tempPtr = nullptr;
			return true;
		}

		
	}

};

#endif	

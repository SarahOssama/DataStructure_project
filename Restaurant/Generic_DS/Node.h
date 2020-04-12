
#ifndef __NODE_H_
#define __NODE_H_

class Order;

template < typename T>
class Node
{
private :
	T item; // A data item
	Node<T>* next; // Pointer to next node
	int Priority;
public :
	Node();
	Node( const T & r_Item);	//passing by const ref.
	Node( const T & r_Item, Node<T>* nextNodePtr);
	//Node(const T& r_Item, const int& pr);
	void setItem( const T & r_Item);
	void setNext(Node<T>* nextNodePtr);
	T getItem() const ;
	Node<T>* getNext() const ;
	void setPriority(Order* o);
	int getPriority() const;
	void Get_next_of();
}; // end Node


template < typename T>
Node<T>::Node() 
{
	next = nullptr;
} 

template < typename T>
Node<T>::Node( const T& r_Item)
{
	item = r_Item;
	next = nullptr;
} 

template < typename T>
Node<T>::Node( const T& r_Item, Node<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}


template < typename T>
void Node<T>::setItem( const T& r_Item)
{
	item = r_Item;
} 

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template < typename T>
T Node<T>::getItem() const
{
	return item;
} 

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
} 

template < typename T>
void Node<T>::setPriority(Order* o)
{
	Priority = o->gettotalmoney() / ( o->getSize() * o->getArrTime() );
}


template < typename T>
int Node<T>::getPriority() const
{
	return Priority;
}
/*template < typename T>
void Node<T>::Get_next_of()
{
	if (this)
	{
		this = this->getNext();
	}
}*/

#endif
//template for node class and doubly linked list
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

/*---------------------------------------------------------------------------*/
template <typename TGen>
class NodeClass //node class object for creating nodes for the DLL
{
	public:
		NodeClass(); //default constructor
		NodeClass(TGen e); //constructor
		virtual ~NodeClass(); //destructor
		TGen element; //element of node
		NodeClass<TGen> *next; //nodes next pointer
		NodeClass<TGen> *prev; //nodes previous pointer
};

template <typename TGen>
NodeClass<TGen>:: NodeClass(){} //default constructor

template <typename TGen>
NodeClass<TGen>::NodeClass(TGen e) { //constructor for the noce class
	element = e; //set element to member var
	next = 0; //set next to zero
	prev = 0; //set prev to zero
}

template <typename TGen>
NodeClass<TGen>::~NodeClass() { //destructor for garbage collection
	delete next; //delete next node
	delete prev; //delete previous node
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
template <typename TGen>
class DoublyLinkedList //double ended linked list class
{
public:
	DoublyLinkedList(); //constructor
	virtual ~DoublyLinkedList(); //destructor

	void insertRearDLL(TGen e); //insert a node at the rear of the DLL

	TGen getHeadDLL(); //gets elemenet at the head of the list
	void removeHeadDLL(); //removes the node from head of the DLL

	int getSizeDLL(){return (sizeDLL);} //returns current size of list
	bool isEmptyDLL(){return (sizeDLL == 0);}	//return true if DLL is empty

private:
	int sizeDLL; //current number of elements

	NodeClass<TGen>* head; //top of the DLL
	NodeClass<TGen>* rear; //bottom of the DLL
};

template <typename TGen>
DoublyLinkedList<TGen>::DoublyLinkedList(){ //constructor
	sizeDLL = 0; //sets sizeDLL equal to zero. our size counter
	head = 0; //set address of head equal to zero
	rear = 0; //sets address of head equal to zero
}

template <typename TGen>
DoublyLinkedList<TGen>::~DoublyLinkedList() { //destructor
	while (!isEmptyDLL()) //remove head nodes until DLL is empty
	{
		removeHeadDLL();
	}
}

template <typename TGen>
void DoublyLinkedList<TGen>::insertRearDLL(TGen d){ //add nodes to the rear of the list
	NodeClass<TGen>* newNode = new NodeClass<TGen>(d);
	if (isEmptyDLL()) {//DLL is empty
		head = newNode;
		rear = newNode;
		++sizeDLL;
	} else { //DLL contains existing nodes
		rear -> next = newNode;
		newNode -> prev = rear;
		rear = newNode;
		++sizeDLL;
	}
}

template <typename TGen>
TGen DoublyLinkedList<TGen>::getHeadDLL() { //returns element from head node
	NodeClass<TGen>* headNode = head;
	return headNode -> element;
}

template <typename TGen>
void DoublyLinkedList<TGen>::removeHeadDLL() { //recursively remove from head
	NodeClass<TGen>* deleteNode = head;
	if (getSizeDLL() == 1) //if there is one node left in the list
	{
		head = deleteNode -> next;
		rear = 0;
		--sizeDLL;
	}
	else //more than one nodes in the list
	{
		head = deleteNode -> next;
		head -> prev = 0;
		--sizeDLL;
	}
}
/*---------------------------------------------------------------------------*/
#endif

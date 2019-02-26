//double ended linked list implementation of a generic queue
#ifndef GENERIC_QUEUE_JR
#define GENERIC_QUEUE_JR

#include "DoublyLinkedList.h" //include generic doubly linked list interface

template <typename TGen>
class GenericQueueOG
{
	public:
		virtual void enQueue(TGen e) = 0;
		virtual void deQueue() = 0;

		virtual bool isEmptyGenQ() = 0;

		virtual int getSizeGenQ() = 0;
		virtual TGen getHeadGenQ() = 0;
};

template <typename TGen>
class GenericQueueJr: public GenericQueueOG<TGen> //child class (jr) inherts from parent/base class (OG)
{
public:
	GenericQueueJr(); //cosntrutor
	virtual ~GenericQueueJr(); //destrutor
	void enQueue(TGen e); //insert at rear
	void deQueue(); //remove from head
	bool isEmptyGenQ(); //check if queue size is equal to 0 and DLL is empty
	int getSizeGenQ(); //get total number of elements in the queue
	TGen getHeadGenQ(); //get first element towards head of queue
private:
	DoublyLinkedList<TGen> genQueue; //initalize queue as doubly linked list
};

template <typename TGen>
GenericQueueJr<TGen>::GenericQueueJr(){} //default constructor

template <typename TGen>
GenericQueueJr<TGen>::~GenericQueueJr() { //destructor
	while (isEmptyGenQ() == false) //while the queue contains elements
	{
		deQueue(); //remove from head
	}
}

template <typename TGen>
void GenericQueueJr<TGen>::enQueue(TGen e) { //insert node at end of the queue
	genQueue.insertRearDLL(e);
}

template <typename TGen>
void GenericQueueJr<TGen>::deQueue() { //remove node at start of the queue
	genQueue.removeHeadDLL();
}
template <typename TGen>
bool GenericQueueJr<TGen>::isEmptyGenQ() { //check if DLL is empty
	return (genQueue.isEmptyDLL());
}

template <typename TGen>
int GenericQueueJr<TGen>::getSizeGenQ() { //get size of queue from DLL
	return (genQueue.getSizeDLL());
}

template <typename TGen>
TGen GenericQueueJr<TGen>::getHeadGenQ() { //get first node from DLL
	return (genQueue.getHeadDLL());
}
#endif

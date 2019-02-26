//Generic stack defition and implementation utilizing template classes
#ifndef GEN_STACK_HEADER
#define GEN_STACK_HEADER

#include <iostream>
#include <string>
#include <stdlib.h>

template <typename genType>
class GenStack {
	enum {STACK_SIZE_DEFAULT = 100};
public:
	GenStack (int stackSizeMax = STACK_SIZE_DEFAULT); //construct constant stack size
	~GenStack(); //delete stack
	int stackSize() const; //return current size of the stack (top+1)
	bool isEmpty() const; //boolean checker for empty array
	const genType& peek() const;
	void push (const genType& element);
	void pop();
	void dupe();
private:
	genType* stack;
	int stackMax; //non constant stack size
	int stackTop; //indexed counter, keeps track of the top of the stack
};

template <typename genType> GenStack<genType> :: GenStack(int stackSizeMax)
{
	stack = new genType[stackSizeMax];
	stackMax = stackSizeMax;
	stackTop = -1;
}

template <typename genType> GenStack<genType> :: ~GenStack()
{
	delete [] stack;
}

template <typename genType> int GenStack<genType> :: stackSize() const
{
	return (stackTop + 1);
}


template <typename genType> bool GenStack<genType> :: isEmpty() const
{
	return (stackTop == - 1);
}

template <typename genType> const genType& GenStack<genType> :: peek() const
{
	try
	{
		if (isEmpty() == true)
		{
			throw stackTop;
		}
		else
		{
			return stack[stackTop];
		}
	}
	catch (int err)
	{
		std::cout << "[ERROR] Expected declaration before '" << stack[0] << "'.\n";
		exit(0);
	}
}

template <typename genType> void GenStack<genType> :: push(const genType& element)
{
	if (stackSize() == stackMax)
	{
		dupe();
	}
	stack[++stackTop] = element;
}

template <typename genType> void GenStack<genType> :: pop()
{
	try
	{
		if (isEmpty() == true)
		{
			throw stackTop;
		}
		else
		{
			--stackTop;
		}
	}
	catch (int err)
	{
		std::cout << "[ERROR] Empty stack. Expected declaration before '" << stack[0] << "'.\n";
		exit(0);
	}
}

template <typename genType> void GenStack<genType> :: dupe()
{
	genType* newArray = new genType[stackMax + 100];
	for (int i = 0; i < stackSize(); ++i)
	{
		newArray[i] = stack[i];
	}
	stackMax += 100;
	genType* oldArray = stack;
	stack = newArray;
	delete [] oldArray;
}
#endif

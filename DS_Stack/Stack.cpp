#include "Stack.h"
#include <iostream>

Stack::Stack()
	: top(-1)
{
	
}

bool Stack::isFull()
{
	if (top == MAX_STACK_SIZE - 1)
		return true;
	return false;
}

bool Stack::isEmpty()
{
	if (top == -1)
		return true;
	return false;
}

void Stack::push(Element &element)
{
	if (!isFull())
	{
		top++;
		stackdump[top] = element;
	}
	else
		std::cout << "Push error: Stack is already full!" << std::endl;
}

Element &Stack::pop()
{
	if(!isEmpty())
	{
		return stackdump[top--];
	}
	std::cout << "Pop error: Stack is already empty!" << std::endl;
	return Element();
}

Element::Element()
	: key(false)
	, num(0)
{

}

Element::Element(bool _key, int _num)
	: key(_key)
	, num(_num)
{

}
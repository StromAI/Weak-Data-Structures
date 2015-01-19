//Some basic code just for fun
#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100

struct Element
{
	Element();
	Element(bool key, int num);
	~Element(){}
	bool key; //Error Manage
	int num;
	//Other member
};

class Stack
{
public:
	Stack();
	~Stack(){}

	bool isEmpty();
	bool isFull();
	void push(Element &element);
	Element &pop();
private:
	int top;
	Element stackdump[MAX_STACK_SIZE];
};

#endif
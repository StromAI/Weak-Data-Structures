#include "Stack.h"
#include <iostream>

int main()
{
	Stack t_stack;
	for (int i = 0; i < 100; i++)
	{
		Element temp(true,i);
		t_stack.push(temp);
		std::cout << "The input number is: " << temp.num << std::endl; 
	}
	//t_stack.push(Element(1,0));
	while (!t_stack.isEmpty())
	{
		Element temp = t_stack.pop();
		if (temp.key)
		{
			std::cout << "The number is: " << temp.num << std::endl;
		}
		else
		{
			break;
		}
	}
	//t_stack.pop();
	return 0;
}
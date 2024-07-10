#include<iostream>
#include<stack>
using namespace std;


template<typename T>
std::ostream& operator<<(std::ostream& out, std::stack<T>& src)
{
	while (src.empty() != true)
	{
		out << src.top() << " ";
		src.pop();
	}
	out << endl;
	return out;
}

void create_stack()
{
	stack<int> stkInt;
	stack<float> stkFloat;
	stack<char> stkChar;
}

template<typename T>
void stack_push_pop(stack<T>& src)
{
	src.push(1);
	src.push(3);
	src.push(5);
	src.push(7);
	cout << src;
}



template<typename T>
void stack_copy(stack<T>& src)
{
	src.push(1);
	src.push(3);
	src.push(5);
	src.push(7);
	stack<T> stk1(src);
	cout << stk1;
	stack<T> stk2 = src;
	cout << stk2;
}


template<typename T>
void stack_empty_size(stack<T>& src)
{
	cout << "empty? " << src.empty() << endl;
	cout << "size? " << src.size() << endl;
}


int main()
{
	stack<int> stkInt;
	stack_push_pop(stkInt);

	stack<int> stkCopy;
	stack_copy(stkCopy);

	stack_empty_size(stkCopy);

}
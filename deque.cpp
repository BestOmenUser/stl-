#include<iostream>
#include<deque>
using namespace std;

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::deque<T>& src);

template<typename T>
void deque_push_pop(deque<T> src)
{
	cout << src;
	src.push_front(100);
	cout << src;
	src.pop_front();
	cout << src;
	src.erase(src.begin());
	cout << src;
}

template<typename T>
std::ostream& operator<< ( std::ostream &out , std::deque<T>& src)
{
	typename deque<T>::iterator iter = src.begin();
	for (; iter != src.end(); ++iter)
	{
		out << *iter << "  ";
	}
	out << endl;
	return out;
}

int main()
{
	deque<int> deqInt= { 1,2,3,4,5 };
	deque_push_pop(deqInt);
}
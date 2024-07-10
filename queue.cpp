#include<iostream>
#include<queue>
using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& out, std::queue<T>& src)
{
	while (!src.empty())
	{
		out << src.front() << " ";
		src.pop();
	}
	out << endl;
	return out;
}

void queue_create()
{
	queue<int> queInt;
	queue<float> queFloat;
	queue<string> queString;
}

template<typename T>
void queue_push_pop(queue<T> &src)
{
	src.push(1);
	src.push(3);
	src.push(5);
	src.push(7);
	cout << src;
}

template<typename T>
void queue_copy(queue<T>& src)
{
	src.push(1);
	src.push(3);
	src.push(5);
	src.push(7);
	queue<T> que1(src);
	queue<T> que2 = src;
	cout << src;
	cout << que1;
	cout << que2;
}

template<typename T>
void queue_front_back(queue<T>& src)
{
	src.push(1);
	src.push(3);
	src.push(5);
	src.push(7);
	queue<T> que1(src);
	cout << src;
	que1.front() = 0;
	que1.back() = 8;
	cout << que1;
}

template<typename T>
void queue_empty_size(queue<T>& src)
{
	cout << "empty? " << src.empty() << "size? " << src.size() << endl;
	src.push(1);
	cout << "empty? " << src.empty() << "size? " << src.size() << endl;
}
int main()
{
	queue<int> queInt;
	queue_push_pop(queInt);
	queue_copy(queInt);
	queue_front_back(queInt);
	queue_empty_size(queInt);
}
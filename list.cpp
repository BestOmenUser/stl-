#include<iostream>
#include<list>
using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& out, list<T>& src)
{
	typename list<T>::iterator iter=src.begin();
	for (; iter != src.end(); iter++)
	{
		out << *iter << " ";
	}
	out << endl;
	return out;
}

template<typename T>
void list_create_push_pop(list<T> &src)
{
	src.push_back(10);
	src.push_back(20);
	src.push_back(30);
	cout << src;
	src.pop_back();
	cout << src;
	src.push_front(1);
	src.push_front(2);
	src.push_front(3);
	cout << src;
	src.pop_front();
	cout << src;
	cout << src.front();
	cout << endl;
}


template<typename T>
void list_iterator(list<T>& src)
{
	typename list<T>::iterator iter_begin = src.begin();
	for (; iter_begin != src.end(); iter_begin++)
		cout << *iter_begin << " ";
	cout << endl;

	typename list<T>::reverse_iterator iter_rbegin = src.rbegin();
	for (; iter_rbegin != src.rend(); iter_rbegin++)
		cout << *iter_rbegin << " ";
	cout << endl;

}


template<typename T>
list<T> create_list(list<T> &src)
{
	list<T> lst1(4, 'm');
	cout << lst1;
	list<T> List = { 'a','b','c','d','e' };
	auto iter_beg = List.begin();
	iter_beg++;
	auto iter_end = List.begin();
	iter_end++;
	iter_end++;
	list<T> lst2(iter_beg,++iter_end);
	cout << lst2;
	list<T> lst3(List);
	cout << lst3;
	return lst3;
}

template<typename T>
void list_copy(list<T>& src)
{
	list<T> lst1 = { 1,2,3,4,5 };
	src.assign(5, 5);
	cout << src;
	src.swap(lst1);
	cout << src;
	src.assign(lst1.begin(), --lst1.end());
	cout << src;
	src = lst1;
	cout << src;
}

template<typename T>
void list_size(list<T>& src)
{
	cout << src.empty() <<" "<< src.size() << endl;
	src.resize(5);
	cout << src.empty() << " " << src.size() << endl;
	cout << src;
	src.resize(7, 1);
	cout << src.empty() << " " << src.size() << endl;
	cout << src;
	src.resize(4);
	cout << src.empty() << " " << src.size() << endl;
	cout << src;
}

template<typename T>
void list_insert(list<T>& src)
{
	list<T> lst = { 1,2,3,4,5 };
	src.assign(5, 5);
	cout << src;
	src.insert(++src.begin(), 10);
	cout << src;
	src.insert(++(++src.begin()), 3, 8);
	cout << src;
	src.insert(src.begin(), lst.begin(), lst.end());
	cout << src;
}

template<typename T>
void list_delete(list<T>& src)
{
	src = { 1,2,3,4,5,4,5,6 };
	cout << src;
	src.erase(src.begin());
	cout << src;
	src.erase(--(--src.end()), src.end());
	cout << src;
	src.remove(4);
	cout << src;
	src.clear();
	cout << "after clear list empty? " << src.empty() << endl;
}

template<typename T>
void list_reverse(list<T> src)
{
	cout << src;
	src.reverse();
	cout << src;
}

template<typename T>
void list_iterator_useless_delete(list<T>& src)
{
	cout << src;
	typename list<T>::iterator iter = src.begin();
	for (; iter != src.end();)
	{
		if (*iter == 2)
			iter = src.erase(iter);
		else
			iter++;
	}
	cout << src;
}

int main()
{
	list<int> listInt;
	list_create_push_pop(listInt);
	list<int> listChar = {1,2,3,4,5 };
	list_iterator(listChar);
	list<char> lstChar;
	create_list(lstChar);
	list<float> lstFloat;
	list_copy(lstFloat);
	list<int> lstSize;
	list_size(lstSize);
	list<int> lstInsert;
	list_insert(lstInsert);
	list<int> lstDelete;
	list_delete(lstDelete);

	list_reverse(listChar);

	list<int> lstIterator = { 2,3,3,4,2,2,6,7 };
	list_iterator_useless_delete(lstIterator);
}
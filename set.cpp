#include<iostream>
#include<set>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

void create_set()
{
	set<int> setInt;
	set<float> setFloat;
	set<string> setString;
	multiplies<int> mulsetInt;
}

/*template<typename T>
std::ostream& operator<<(std::ostream& out, set<T>& src)
{
	typename set<T>::iterator iter = src.begin();
	for (; iter != src.end(); iter++)
	{
		out << *iter << " ";
	}
	out << endl;
	return out;
}*/

template<typename T,template<typename> class Compare=std::less>
std::ostream& operator<<(std::ostream& out, set<T,Compare<T>>& src)
{
	typename set<T>::iterator iter = src.begin();
	for (; iter != src.end(); iter++)
	{
		out << *iter << " ";
	}
	out << endl;
	return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, multiset<T>& src)
{
	typename multiset<T>::reverse_iterator reverse_iter = src.rbegin();
	for (; reverse_iter != src.rend(); reverse_iter++)
	{
		out << *reverse_iter << " ";
	}
	out << endl;
	return out;
}

template<typename T>
void set_insert(set<T> src)
{
	src.insert(3);
	src.insert(1);
	src.insert(7);
	src.insert(5);
	src.insert(5);
	cout << src;
}

template<typename T>
void multiset_insert(std::multiset<T> src)
{
	src.insert(3);
	src.insert(1);
	src.insert(7);
	src.insert(5);
	src.insert(5);
	cout << src;
}

template<typename T>
void set_copy(set<T>& src)
{
	src.insert(1);
	src.insert(3);
	src.insert(5);
	src.insert(7);
	cout << src;

	set<T> set1(src);
	cout << set1;

	set<T> set2;
	set2 = src;
	cout << set2;

	set<T> set3;
	set3.insert(4);
	set2.swap(set3);
	cout << set2;
}

template<typename T>
void set_delete(set<T> src)
{
	src.insert(1);
	src.insert(3);
	src.insert(5);
	src.insert(7);
	src.insert(9);
	src.insert(9);
	cout << "size:" << src.size() << " " << src;

	auto iter = src.begin();
	iter = src.erase(iter);
	cout << src;

	src.erase(src.begin(), ++(++iter));
	cout << src;

	src.erase(9);
	cout << src;

	src.clear();
	cout << "src empty? " << src.empty() << endl;
}

template<typename T, template<typename> class Compare=std::less>
void set_compare(set<T,Compare<T>> src)
{
	src.insert(1);
	src.insert(5);
	src.insert(3);
	cout << src;
}



int plus(int x,int y)
{
	cout << "plus" << endl;
	return x + y;
}

int decent(int x,int y)
{
	cout << "decent" << endl;
	return x - y;
}

int mul(int x, int y)
{
	cout << "mul" << endl;
	return x * y;
}

int divide(int x, int y)
{
	cout << "divide" << endl;
	return x / y;
}

//func(x,y,plus)?
typedef int(*FUNC)(int, int);
int func(int x, int y, FUNC f)
{
	return f(x,  y);
}


class Student {
public:
	Student(string n, int i)
	{
		name = n;
		id = i;
	}
	int  get_id() const
	{
		return this->id;
	}
private:
	string name;
	int id;
};

class Student_less {
public:
	bool operator() (const Student& left, const Student& right) const
	{
		cout << left.get_id() << "  " << right.get_id() <<" "<< (left.get_id() < right.get_id())<< endl;
		return (left.get_id() < right.get_id());
	}
};

template<typename T,class Compare>
void set_student(set<T,Compare> & Group)
{
	Student S1("Alan", 1001);
	Student S2("Blue", 999);
	Student S3("Ouq", 1000);
	Group.insert(S1);
	Group.insert(S2);
	Group.insert(S3);
	auto iter = Group.begin();
	for (; iter != Group.end(); iter++)
	{
		cout << (*iter).get_id() << " ";
	}
	cout << endl;
}

void set_find(set<int> src)
{
	src.insert(1);
	src.insert(3);
	src.insert(5);
	src.insert(7);
	auto iter = src.find(1);
	cout << *iter << endl;

	int number = src.count(1);
	cout << number << endl;
	number = src.count(0);
	cout << number << endl;

	iter = src.lower_bound(3);
	cout << *iter << endl;
	iter = src.upper_bound(3);
	cout << *iter << endl;
}


int main()
{
	set<int> setInt;
	set_insert(setInt);
	multiset<int> mulsetInt;
	multiset_insert(mulsetInt);

	set_copy(setInt);

	set_delete(setInt);

	set<int, less<int>> setLess;
	set<int, greater<int>> setGreater;
	set_compare(setLess);
	set_compare(setGreater);

	func(1, 3,divide);

	set<Student, Student_less> group;
	set_student(group);

	set<int> setFind;
	set_find(setFind);
}
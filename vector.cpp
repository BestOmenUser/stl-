#include<iostream>
#include<vector>
using namespace std;


template<typename T>
vector<T> vector_beg_end(T* arr,int size)
{
	vector<T> vecT(arr, arr + size);
	return vecT;
}

template<typename T>
vector<T> vector_n_elem(int n, T elem)
{
	vector<T> vecT(n, elem);
	return vecT;
}


template<typename T>
vector<T> vector_copy(const vector<T> &src )
{
	vector<T> vecT(src);
	return vecT;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std :: vector<T>& src)
{
	for (auto it = src.begin(); it != src.end(); ++it)
	{
		out << *it << " ";
	}
	out << endl;
	return out;
}

template<typename T>
void vector_copy_to(const vector<T>& src)
{
	char arr[5] = {'a','r','r','0','1'};
	vector<T> vecA;
	vector<T> vecB;
	vector<T> vecC;
	vector<T> vecD;
	vecA.assign(arr,arr + sizeof(arr) / sizeof(arr[0]));
	vecB.assign(src.begin(), src.end());
	vecC.assign(5, 'B');
	vecD = vecA;
	cout << "vecA.assign( 'a', 'r', 'r', '0', '1')" << vecA;
	cout << "vecB.assign(src.begin,src.end)" << vecB;
	cout << "vecC.assign( 5,B)" << vecC;
	cout << "vecD = vecA;" << vecD;
	vecD.swap(vecC);
	cout << "after swap D C" << endl;
	cout << "vecC" << vecC;
	cout << "vecD" << vecD;
}


template<typename T>
void vector_size(vector<T> &src)
{
	cout << "src.size  src.empty(): " << src.size()<<"  " << src.empty() << endl;
	src.resize(4);
	cout << "src.resize(4):" << src;
	cout << "src.size  src.empty(): " << src.size() << "  " << src.empty() << endl;
	src.resize(0);
	cout << "scr.resize(0):" << src;
	cout << "src.size  src.empty(): " << src.size() << "  " << src.empty() << endl;
	src.resize(4, 5);
	cout << "scr.resize(4,5):" << src;
	cout << "src.size  src.empty(): " << src.size() << "  " << src.empty() << endl;
}


void vector_insert()
{
	vector<int> vecA;
	vector<int> vecB;

	vecA.push_back(1);
	vecA.push_back(3);
	vecA.push_back(5);
	vecA.push_back(7);
	vecA.push_back(9);  // vecA 1,3,5,7,9
	cout << "vecA:" << vecA;
	vecB.push_back(2);
	vecB.push_back(4);
	vecB.push_back(6);
	vecB.push_back(8);
	vecB.push_back(10);  // vecB 2,4,6,8,10
	cout << "vecB:" << vecB;
	vecA.insert(vecA.begin() + 3, 100); // vecA 1,3,5,100,7,9
	cout << "vecA:" << vecA;
	vecB.insert(vecB.begin() + 2, 50); // vecA 2,4,50,6,8,10
	cout << "vecB:" << vecB;
	vecA.insert(vecA.begin() + 2, 3, 88);//1,3,88,88,88,5,100,7,9
	cout << "vecA:" << vecA;
	vecA.insert(vecA.begin() + 1, vecB.begin(), vecB.end());//1,2,4,50,6,8,10,3,88,88,88,5,100,7,9
	cout << "vecA:" << vecA;
}


void vector_delete()
{
	vector<int> vecInt = { 1,2,3,4,5 };
	cout << "vecInt:" << vecInt;
	vecInt.erase(vecInt.begin() + 2); //1,2,4,5
	cout << "vecInt:" << vecInt;
	vecInt.pop_back(); //1,2,4;
	cout << "vecInt:" << vecInt;
	swap(vecInt[0], vecInt[2]);
	cout << "vecInt:" << vecInt;
	vecInt.pop_back(); //4,2;
	cout << "vecInt:" << vecInt;
}


void vector_iterator()
{
	vector<int> vecIntA;
	int array[] = { 0,1,20,30,40 };
	vecIntA .assign(array,array+5);
	vector<int>::iterator iter = vecIntA.begin();
	for (iter = vecIntA.begin(); iter != vecIntA.end(); iter++)
	{
		cout << *iter<<" ";
	}
	cout << endl;
	iter = vecIntA.begin() + 2;
	*iter = 0;
	for (iter = vecIntA.begin(); iter != vecIntA.end(); iter++)
	{
		cout << *iter<<" ";
	}
	cout << endl;
}


void vector_iterator_useless()
{
	/*vector<int> cont = { 1,2,3,3,3,4,5,5,5,6 };
	vector<int>::iterator iter;
	for (iter = cont.begin(); iter!=cont.end(); iter++)
	{
		if (*iter == 3)
			cont.erase(iter);
	}
	cout << cont;*/
	// 报错  因为每次删除后前移一位，而iter往后移一位。有遗漏。
	vector<int> cont = { 1,2,3,3,3,4,5,5,5,6 };
	vector<int>::iterator iter;
	for (iter = cont.begin(); iter!= cont.end();)
	{
		if (*iter == 3)
			iter = cont.erase(iter);
		else
			iter++;
	}
	cout << cont;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	char str[5] = { 'B','B','B','B','B' };

	vector<int> example = { 1,2,3,4,5 };
	cout<<vector_beg_end(arr, sizeof(arr) / sizeof(arr[0]));
	cout<<vector_n_elem(3, 'a');
	cout << vector_copy(example);

	vector<char> string = { 'B','B','B','B','B' };
	vector_copy_to(string);

	vector<int> vecSize;
	vector_size(vecSize);
	vector_insert();

	vector_delete();

	vector_iterator();

	vector_iterator_useless();
	return 0;
}


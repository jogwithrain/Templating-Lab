#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template< typename T>
//should support anything that adds such as ints, doubles, special numbers, and chars.
vector<T> vec_fill(T elem) {
	vector<T> v;
	for (auto i = 0; i < 10;i++) {
		v.push_back(elem + i);
	}
	return v;
}

template<typename T>
void order(T& a, T& b, T& c) {
	T temp;
	if (c > a) {
		temp = a;
		a = c;
		c = temp;
	}
	if (b > a) {
		temp = a;
		a = b;
		b = temp;
	}
	if (c > b) {
		temp = b;
		b = c;
		c = temp;
	}
}

template<typename T>
bool search(T begin, T end, int elem) {
	vector<int> a = { 3,124,25,140,24,63,135,1,44,5 };
	if (begin < 0) {
		cout << begin << " IS OUT OF RANGE" << endl;
		return false;
	}
	vector<int>::iterator start = a.begin() + begin;
	if (a.size() < end) {
		cout << end << " IS OUT OF BOUNDS" << endl;
		return false;

	}
	int b = a.size() - end;
	vector<int>::iterator ending = a.end() - b;
	for (auto i = start;i != ending; i++) {
		if (*i == elem) {
			return true;
		}
	}
	return false;
}

int main() {
	{ //scope one testing vec_fill
		vector<int> a = vec_fill(10);
		vector<int> b = { 10,11,12,13,14,15,16,17,18,19 };
		assert(a == b);

		vector<double> c = vec_fill<double>(10);
		vector<double> d = { 10.0,11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0 };
		assert(c == d);

		vector<char> e = vec_fill<char>('j');
		vector<char> f = { 'j','k','l','m','n','o','p','q','r','s'};
		assert(e == f);
	}
	{ //scope two testing order
	int d = 13;
	int f = 14;
	int g = 15;
	order(d, f, g);
	assert(d == 15);

	int h = 5;
	int i = 4;
	int j = 3;
	order(h, i, j);
	assert(h == 5);

	int a = 3;
	int b = 5;
	int c = 4;
	order(a, b, c);
	assert(a == 5);

	char l = 'a';
	char m = 'c';
	char n = 'b';
	order(l, m, n);
	assert(l = 'c');

	double q = 10.3;
	double r = 421.2;
	double z = 0.23;
	order(q, r, z);
	assert(q = 421.2);

}
	{ //scope for seraching int in an int vector
		bool a = search(0, 10, 5);
		assert(a == true);

		bool b = search(3, 6, 63);
		assert(b == true);

		bool c = search(0, 25, 2);
		assert(c == false);
		bool d = search(-1, 2, 5);
		assert(d == false);

		bool e = search(0.0, 10.0, 5);
		assert(e == true);

		//Chars need the -'0' because their number is different than
		//their regular char value.
		bool f = search('3' - '0', '7'-'0', 63);
		assert(f == true);
		//And there activates windows secuirty making me have to switch to another complier application :sob:
		bool g = search(0.0, 3.0, 3);
		assert(g == true);
	}
}



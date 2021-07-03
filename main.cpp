#include "KosList.cpp"
#include <iostream>

using namespace std;

int main()
{
	KosList<int> list;
	// Adding integral value.
	list.addline(1);
	list.addline(4);
	list.addline(5);
	list.addline(2);
	// Displaying values by index.
	cout << list.line(0) << list.line(1)<< list.line(2) << list.line(3) << '\n';
	// Deleting single node from it's index.
	list.deletenode(2);
	// Displaying values by index.
	cout << list.line(0);
	cout << list.line(1);
	cout << list.line(2);
}
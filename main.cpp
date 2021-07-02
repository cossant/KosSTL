#include "KosList.cpp"
#include <iostream>

using namespace std;

int main()
{
	KosList<int> list;
	list.addline(1);
	list.addline(4);
	list.addline(5);
	list.addline(2);
	cout << list.line(2) << list.line(1)<< list.line(1) << list.line(0) << list.line(3);
}
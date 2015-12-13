#include <iostream>
#include "Spisok.h"
using namespace std;
int main()
{
	Spisok Op;
	int k;
	Op.input();
	Op.print();
	cout << "Input elem to find: ";
	cin >> k;
	elem *p = Op.Poisk(k);
	if (p == NULL)
	{
		cout << "Not found!\n";
	}
	else
	{
		Op.del(p);
		Op.print();
	}
	return 0;
}
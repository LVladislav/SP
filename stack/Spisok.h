#pragma once
#include <iostream>
using namespace std;
struct elem{
	int val; // хранимое число
	elem *next; // указатель на след. элемент

	elem(int a)
	{
		val = a; // запоминаем значение элемента
		next = 0;// потому что добавлять будем в конец
	}
};

class Spisok
{
	elem *first;
public:
	Spisok();
	void add(int a);
	void print(void) const;
	void input(void);
	elem *Poisk(int i);
	void del(elem *q);
	~Spisok();
};


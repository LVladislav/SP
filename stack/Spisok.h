#pragma once
#include <iostream>
using namespace std;
struct elem{
	int val; // �������� �����
	elem *next; // ��������� �� ����. �������

	elem(int a)
	{
		val = a; // ���������� �������� ��������
		next = 0;// ������ ��� ��������� ����� � �����
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


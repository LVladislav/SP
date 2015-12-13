#include "Spisok.h"


Spisok::Spisok()
{
	first = 0; // ������ ������� ����� ����
}


Spisok::~Spisok()
{
	elem *cur=first;
	while (cur!=0)
	{
		elem *pred = cur;
		cur = cur->next;
		delete pred;
	}
	first = 0;
}


void Spisok::add(int a)
{
	if (first == 0)
	{
		first = new elem(a); // ������� ������ �������
	}
	else
	{
		elem *cur;
		for (cur = first; cur->next != 0; cur = cur->next) // ���� �� ������ ������; ���� � ��� ���� ��������; � ��������� �� ���������
		{}
		cur->next = new elem(a); // ������� ����� ������� , ��� ��������� � ������.
	}
}

void Spisok::print(void) const
{
	elem *cur; //������� ������� ��� �����
	cout << "List elem: "<<endl;
	if (first==0)
	{
		cout << "No elem!\n";
		return;
	}
	for (cur = first; cur != 0; cur = cur->next)
	{
		cout << cur->val<<endl;
	}

}
void Spisok::input(void)
{
	cout << "Input list elem(exit 0): " << endl;
	while (true)
	{
		int i;
		cin >> i;
		if (i == 0)
		{
			break;
		}
		this->add(i); //���������� � ������� ������ this
	}
}


elem *Spisok::Poisk(int i)
{
	elem *cur;
	for (cur = first; cur != 0; cur = cur->next)
	{
		if (cur->val==i)
		{
			return cur; // ���������� ����� ��������, ��� ����� ������� �����
		}
	}
	return 0; // ����� �������� �� �������.
}

void Spisok::del(elem *q)
{
	if (first == q) // ���� ������� ������ �������
	{
		first = first->next; // �� ���������� first �� ����. ����.
	}
	else
	{
		elem *cur;
		for (cur = first; cur->next !=q; cur = cur->next) // ���� �� ������ ������; ���� � ��� ���� ��������; � ��������� �� ���������
		{}
		cur->next = cur->next->next; //  �������� ��������� � cur, �� ����. ����� ����������.
		//cur->next=q->next; - ������������
	}
	delete q;
}
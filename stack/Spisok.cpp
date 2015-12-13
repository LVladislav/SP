#include "Spisok.h"


Spisok::Spisok()
{
	first = 0; // первый элемент равен нулю
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
		first = new elem(a); // создает первый элемент
	}
	else
	{
		elem *cur;
		for (cur = first; cur->next != 0; cur = cur->next) // цикл от начала списка; пока в нем есть элементы; и переходим на следующий
		{}
		cur->next = new elem(a); // создаем новый элемент , как последний в списке.
	}
}

void Spisok::print(void) const
{
	elem *cur; //текущий элемент для цикла
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
		this->add(i); //добовление в текущий список this
	}
}


elem *Spisok::Poisk(int i)
{
	elem *cur;
	for (cur = first; cur != 0; cur = cur->next)
	{
		if (cur->val==i)
		{
			return cur; // возвращаем адрес элемента, где лежит искомое число
		}
	}
	return 0; // когда значение не найдено.
}

void Spisok::del(elem *q)
{
	if (first == q) // если удаляем первый элемент
	{
		first = first->next; // то сдвигается first на след. элем.
	}
	else
	{
		elem *cur;
		for (cur = first; cur->next !=q; cur = cur->next) // цикл от начала списка; пока в нем есть элементы; и переходим на следующий
		{}
		cur->next = cur->next->next; //  изменяем следующий у cur, на след. после удаляемого.
		//cur->next=q->next; - эквивалентно
	}
	delete q;
}
#include"Card.h"
#include<stdlib.h>
#include<Windows.h>

Cards::Cards()
{
	for (int i = 0; i < Length - 2; i++)
	{
		Card_0[i].number = i / 4 + 1;
		Card_0[i].color = (i + 1) % 4;
	}
	Card_0[Length - 2] = { 0,1 };
	Card_0[Length - 1] = { 0,2 };
}

void Cards::shuffle()
{
	Card temp;
	for (int i = 0,j; i < Length; i++)
	{
		j = (rand() % (Length - i)) + i;
		temp = Card_0[i];
		Card_0[i] = Card_0[j];
		Card_0[j] = temp;
	}
}

void Cards::deal(Card first[], Card second[], Card third[], Card landlord[])
{
	int i = 0, f = 0, s = 0, t = 0;
	for (; i < 3; i++)landlord[i] = Card_0[i];
	for (int j = 0; j < 2; j++, i++,f++)first[f] = Card_0[i];
	for (int j = 0; j < 2; j++, i++,s++)second[s] = Card_0[i];
	for (int j = 0; j < 2; j++, i++,t++)third[t] = Card_0[i];
	while (i < 54)
	{
		for (int j = 0; j < 3; j++, i++,f++)first[f] = Card_0[i];
		for (int j = 0; j < 3; j++, i++,s++)second[s] = Card_0[i];
		for (int j = 0; j < 3; j++, i++,t++)third[t] = Card_0[i];
	}
}

void sort(Cards:: Card C[])
{
	for (int i = 1; i < 17; i++)
	{
		Cards::Card temp = C[i];
		
		for (int j = i-1; j >=0 && C[j]>temp; j--)
		{
			C[j + 1] = C[j];

			C[j] = temp;
		}
	}
}

void print(Cards::Card c)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (c.color)
	{
	case 0:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
		| FOREGROUND_RED | FOREGROUND_GREEN);//黄色
		break;
	case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
		| FOREGROUND_BLUE | FOREGROUND_RED);//粉色
		break;
	case 2:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
		| FOREGROUND_BLUE | FOREGROUND_GREEN);//青色
		break;
	case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
		| FOREGROUND_GREEN);//绿色
		break;
	}
	switch (c.number)
	{
	case 0:std::cout << "joker ";
		break;
	case 1:std::cout << "A  ";
		break;
	case 11:std::cout << "J  ";
		break;
	case 12:std::cout << "Q  ";
		break;
	case 13:std::cout << "K  ";
		break;
	case 10:std::cout << "10 ";
		break;
	default:	std::cout << c.number << "  ";
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}

void test(Cards::Card first[], Cards::Card second[],
	Cards::Card third[], Cards::Card landlord[])
{
	Cards test;
	Cards temp;
	int i=0;
	for (int j = 0; j < 2; i++, j++)temp.Card_0[i] = landlord[j];
	for (int j = 0; j < 17; i++, j++)temp.Card_0[i] = first[j];
	for (int j = 0; j < 17; i++, j++)temp.Card_0[i] = second[j];
	for (int j = 0; j < 17; i++, j++)temp.Card_0[i] = third[j];
	sort(temp.Card_0);
	sort(test.Card_0);
	bool result=true;
	for (int j = 0; j < 54; j++)
		if (temp.Card_0[j].number != test.Card_0[j].number|| 
			temp.Card_0[j].color != test.Card_0[j].color)
		{
			break;
			result = false;
		}
	if (result)std::cout << "经检查，本次发牌成功~O(∩_∩)O~o(*￣▽￣*)ブ~（づ￣3￣）づ╭❤～\n";
	else std::cout << "经检查，本次发牌失败(发出的牌不满足扑克牌规则)(；′⌒`)\n";
}

void prints(Cards::Card c[],int n)
{
	for (int i = 0; i < n; i++)print(c[i]);
}
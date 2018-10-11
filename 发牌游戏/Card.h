#pragma once
#include<iostream>

class Cards
{
public:
	struct Card//����Ϊ0��1 С��Ϊ0��2
	{
		short number;//J-11,Q-12,K-13
		short color;//0-���ң�1-���ң�2-÷����3-����
		bool operator>(const Card & c )
		{
			if ((3 <= this->number&&number <= 13) && (3 <= c.number&&c.number <= 13))
			{
				if (number > c.number)return true;
				else if (number == c.number)
				{
					if (color < c.color)return true;
					else return false;
				}
				else return false;
			}
			else if ((3 <= number&&number <= 13) || (3 <= c.number&&number <= 13))
			{
				if (3 <= c.number&&number <= 13)return true;
				else return false;
			}
			else if (number == 0 || c.number == 0)
			{
				if (number < c.number)return true;
				else if (number == c.number)
				{
					if (color < c.color)return true;
					else return false;
				}
				else return false;
			}
			else
			{
				if (number > c.number)return true;
				else if (number == c.number)
				{
					if (color < c.color)return true;
					else return false;
				}
				else return false;
			}
		}
	};
	Card Card_0[54] = { 0 };
	Cards();
	void shuffle();
	void deal(Card first[],Card second[],Card third[],Card landlord[]);
private:
	static const int Length = 54;
};

void print(Cards::Card c);

void sort(Cards::Card C[]);

void test(Cards::Card first[], Cards::Card second[],
	Cards::Card third[], Cards::Card landlord[]);

void prints(Cards::Card c[],int n);
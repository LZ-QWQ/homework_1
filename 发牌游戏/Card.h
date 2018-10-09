#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>

class Cards
{
public:
	Cards();
	~Cards();
	void reset();
	void Print();
	void Examine();
private:
	typedef struct Card//大王为0，1 小王为0，2
	{
		short number;//J-11,Q-12,K-13
		short color;//1-黑桃，2-红桃，3-梅花，4-方块
		Card* next;
	}* List;
	List Cards_0;//头结点
	List Last;//尾结点
	int Length = 54;
};
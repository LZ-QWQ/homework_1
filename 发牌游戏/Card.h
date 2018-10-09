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
	typedef struct Card//����Ϊ0��1 С��Ϊ0��2
	{
		short number;//J-11,Q-12,K-13
		short color;//1-���ң�2-���ң�3-÷����4-����
		Card* next;
	}* List;
	List Cards_0;//ͷ���
	List Last;//β���
	int Length = 54;
};
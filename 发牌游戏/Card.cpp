#include"Card.h"

Cards::Cards()
{
	Cards_0 = new Card{ -1,-1,nullptr };
	List temp = Cards_0;
	temp->next = new Card{ 0,1,nullptr };
	temp = temp->next;
	temp->next = new Card{ 0,2,nullptr };
	int cout = 1;
	while (cout <= 13)//1-K 13ÖÖÅÆ
	{
		temp = temp->next;
		temp->next = new Card{ cout,1,nullptr };
		temp = temp->next;
		temp->next = new Card{ cout,2,nullptr };
		temp = temp->next;
		temp->next = new Card{ cout,3,nullptr };
		temp = temp->next;
		temp->next = new Card{ cout,4,nullptr };
		cout++;
	}
}

Cards::~Cards()
{
	List temp;
	while (Cards_0->next != nullptr)
	{
		temp = Cards_0->next;
		delete Cards_0;
		Cards_0 = temp;
	}
	delete Cards_0;
}

void Cards::reset()
{
	List temp1 = nullptr, temp2 = Cards_0->next;
	while (temp2 != nullptr)
	{
		temp1 = temp2;
		temp2 = temp2->next;
		delete temp1;
	}
	Cards_0 = new Card{ -1,-1,nullptr };
	List temp = Cards_0;

	temp->next = new Card{ 0,1,nullptr };
	temp = temp->next;
	temp->next = new Card{ 0,2,nullptr };
	temp = temp->next;
	int cout = 1;
	while (cout <= 13)//1-K 13ÖÖÅÆ
	{
		temp->next = new Card{ cout,1,nullptr };
		temp = temp->next;
		temp->next = new Card{ cout,2,nullptr };
		temp = temp->next;
		temp->next = new Card{ cout,3,nullptr };
		temp = temp->next;
		temp->next = new Card{ cout,4,nullptr };
		temp = temp->next;
		cout++;
	}
}
#include"Card.h"
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
	system("Chcp 65001");
	system("Color 70");
	Cards card;
	Cards::Card first[17];
	Cards::Card second[17];
	Cards::Card third[17];
	Cards::Card landlord[3];
	char temp;
	srand(time(0));
	cout << "键入任意字符(q除外)并回车发牌(q to quit)----designed by 李政 17070110009:\n";
	while (cin >> temp && temp != 'q')
	{
		card.shuffle();
		card.deal(first, second, third, landlord);	
		sort(first);
		sort(second);
		sort(third);
		test(first, second, third, landlord);
		cout<< "键入任意字符(q除外)并回车以继续发牌(q to quit)----designed by 李政 17070110009:\n";
	}
	return 0;
}
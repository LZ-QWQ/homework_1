#include"Card.h"
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
	Cards card;
	Cards::Card first[17];
	Cards::Card second[17];
	Cards::Card third[17];
	Cards::Card landlord[3];
	char temp;
	srand(time(0));
	cout << "键入任意字符(q除外)并回车发牌(q to quit)----designed by LZ~! 17070110009:\n";
	cout << "黑桃为黄色，红桃和大王为粉色，梅花和小王为青色，方块为绿色\n";
	while (cin >> temp && temp != 'q')
	{
		card.shuffle();
		card.deal(first, second, third, landlord);	
		sort(first);
		sort(second);
		sort(third);
		cout << "底牌\t";
		prints(landlord,3);
		cout << endl << "第一组\t";
		prints(first, 17);
		cout << endl << "第二组\t";
		prints(second, 17);
		cout << endl << "第三组\t";
		prints(third, 17);
		cout << endl;
		test(first, second, third, landlord);
		cout<< "键入任意字符(q除外)并回车以继续发牌(q to quit)----designed by LZ~! 17070110009:\n";
		cout << "黑桃为黄色，红桃和大王为粉色，梅花和小王为青色，方块为绿色\n";
	}
	return 0;
}
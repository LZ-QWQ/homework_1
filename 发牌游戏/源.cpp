#include"Card.h"

using namespace std;

int main()
{
	Cards card;
	char temp;
	srand(time(0));
	cout << "键入 y 并回车发牌(q to quit):\n";
	while (cin >> temp && temp != 'q')
	{
		cout<< "键入 y 并回车以继续发牌(q to quit):\n";
	}
	return 0;
}
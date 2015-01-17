#include <iostream>
using namespace std;

int main()
{
	int rd;
	int kex = 0;
	cout << "ENTER to activate command.\n";
	cout << "1: make a kex, 2: eat a kex, 9: status, 0: exit\n";
	do
	{
		cin >> rd;
		switch (rd)
		{
		case 1:
			cout << "You made a kex.\n";
			kex++;
			break;
		case 2:
			if (kex >= 1)
			{
				kex--;
				cout << "You ate a kex.\n";
			}
			else
				cout << "You haven't got kexes!\n";
			break;
		case 9:
			cout << "You have " << kex << (kex == 1 ? " kex" : " kexes") << ".\n";
			break;
		case 0:
			return 0;
		default:
			cout << "Unknown command.\n";
			break;
		}
	} while (rd != 0);

	return 0;
}
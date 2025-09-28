#include<iostream>

using std::cout;
using std::endl;


void Coins_change(int Change)
{
	int coins[] = { 500,100,50,10 };
	int num_coin = 4;

	for (int i = 0; i < num_coin; i++) {
		int coin_value = coins[i];

		int count = Change / coins[i];

		Change = Change % coins[i];

		if (count > 0)
		{
			cout << coin_value << "¿ø: " << count << "°³" << endl;
		}

	}

}

int main()
{
	int change = 1260;
	Coins_change(change);

	return 0;
}
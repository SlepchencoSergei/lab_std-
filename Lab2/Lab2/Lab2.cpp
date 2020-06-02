#include <iostream>
using namespace std;

int main()
{
	int sum = 0;

	for (int i = 20; i < 100; i++)
	{
		
                // если результат целочисленного деления равен 0
		// (если i кратно 3)
		if (i % 3 == 0)
			// sum = sum+i 
 			// прибавить к sum значение i
			sum += i;
	}

	cout << "Summa = " << sum;
}

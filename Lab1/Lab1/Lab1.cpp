#include <iostream>
#include <cmath>
using namespace std;

int main()

        
{       
	// определим переменные a и b и зададим их значения 
	float a = 1000;
	float b = 0.0001;

	// определяем переменные, вычисляем и выводим результат 
        // для типа  float
	float op1 = pow(a + b, 3);
	float op2 = pow(a, 3);
	float op3 = op1 - op2;
	float op4 = 3 * a * b * b + pow(b, 3) + 3 * a * a * b;
	float res = op3 / op4;

	cout << "Result float = " << res << endl;

	// определяем переменные a1 и b1 и зададим их значения 
	double a1 = 1000;
	double b1 = 0.0001;
      
        // определяем переменные, вычисляем и выводим результат 
        // для типа double
	double op11 = pow(a1 + b1, 3);
	double op21 = pow(a1, 3);
	double op31 = op11 - op21;
	double op41 = 3 * a1 * b1 * b1 + pow(b1, 3) + 3 * a1 * a1 * b1;
	double res1 = op31 / op41;

	cout << "Result double = " << res1 << endl;

	system("pause");
}
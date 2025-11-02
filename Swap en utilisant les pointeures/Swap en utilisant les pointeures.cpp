#include <iostream>


using namespace std;

void swapfonction(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a = 5, b = 10;
	cout << "Les valeures de a et b avant swap: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	swapfonction(&a, &b);
	cout << "Les valeures de a et b apres swap: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}
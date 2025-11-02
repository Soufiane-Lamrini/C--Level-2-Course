#include <iostream>

using namespace std;

int main()
{
    int ArrDeuxDimension[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ArrDeuxDimension[i][j] = (j + 1) * (i + 1);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf(" %0*d", 2, ArrDeuxDimension[i][j]);
        }
        cout << endl;
    }
}
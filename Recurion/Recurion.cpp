#include <iostream>

using namespace std;

void printNumbreNtoM(int N, int M)
{
    if (M >= N)
    {
        cout << M << endl;
        printNumbreNtoM(N, M-1);
    }
}
int CalPowerOfNum(int N, int M)
{

    if (M==1)
    {
        return N;
    }
    else
    {
        return (N* CalPowerOfNum(N, M - 1));
    }
}
int main()
{
   int N = 2, M = 3;
    printNumbreNtoM(1, 10);
    cout <<CalPowerOfNum(N, M);
}

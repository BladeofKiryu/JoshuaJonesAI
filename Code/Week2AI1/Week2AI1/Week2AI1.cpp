#include <iostream>
using namespace std;

void result(int N)
{
    for (int num = 0; num < N; num++)
    {
        if (num % 4 == 0 && num % 7 == 0)
            cout << num << " ";
    }
}

int main()
{
    int N = 1000;

    result(N);
    return 0;
}
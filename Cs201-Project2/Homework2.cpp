#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

//Recursive Fibonacci
long fibonacci(int n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

//Iterative Fibonacci
long fibo(int n)
{
    long previous = 1;
    long current = 1;
    long next = 1;
    for (int i = 3; i <= n; ++i)
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}

int main()
{
    //Store the starting time
double duration;
clock_t startTime = clock();
//Code block
for(int i= 0; i<1000; i++)// it selects times of simulation repeat
    fibo(100000);

//for(int i= 0; i<1000; i++)
  //  fib(40);

//Compute the number of seconds that passed since the starting time
duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
cout << "Execution took " << duration/1000 << " milliseconds." << endl;


}

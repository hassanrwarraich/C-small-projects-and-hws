
#include <iostream>
#include <ctime>
using namespace std;

 //iterative method
int iterativeFib(int n){
	int previous = 1;
	int current = 1;
	int next = 1;
	for (int i = 3; i <= n; ++i){
		next = current + previous;
		previous = current;
		current = next;
	}
	return next;
}

//recursive method
int fib(int n){
	if ( n <= 2 )
		return 1;
	else
		return fib(n-1) + fib(n-2);
}


//main method
int main()
{
    //iterative running from 5 to 55 with increase of +5
    for (int i = 5; i <= 55; i = i + 5)
    {
        double duration;
        clock_t startTime = clock();

        for (int j = 0; j < 1000000; j++)
        {
           int n = iterativeFib(i);
        }

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration/1000000 << " milliseconds." << endl;

    }

    //iterative running from 100 to 100000 with increase of *10
    for (int i = 100; i <= 100000; i = i * 10)
    {
        double duration;
        clock_t startTime = clock();

        for (int j = 0; j < 100000; j++)
        {
           int n = iterativeFib(i);
        }

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration/100000 << " milliseconds." << endl;
    }


    //iterative running from 100000 to 100000000 with increase of *10
    for (int i = 1000000; i <= 100000000; i = i * 10)
    {
        double duration;
        clock_t startTime = clock();

        int n = iterativeFib(i);

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;
    }

    //iterative method running from 250000000 to 1000000000 with increase of +250000000
    for (int i = 250000000; i <= 1000000000; i = i + 250000000)
    {
        double duration;
        clock_t startTime = clock();

        int n = iterativeFib(i);

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;
    }

    //recursive method running from 5 to 25 with increase of +5
    for(int i = 5; i < 35 ; i = i + 5)
    {
        double duration;
        clock_t startTime = clock();
        for (int j =0; j < 100000; j++)
        {
            int n = fib(i);
        }
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration/100000 << " milliseconds." << endl;
    }

    //recursive method running from 30 to 55 with increase of +5
    for(int i = 35; i <= 55 ; i = i + 5)
    {
        double duration;
        clock_t startTime = clock();

        int n = fib(i);

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;
    }


    return 0;
}

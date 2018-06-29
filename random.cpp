/*
PRE:
+ srand( seed ) generates seed based on given parameter
+ rand() return the next pseudo random number
+ RAND_MAX is the maximum random number you can get
*/
#include <bits/stdc++.h>
using namespace std;

//input: no input
//output: a  random integer based on system clock
int randomFunctionUtil()
{
    srand( time(NULL) ); //NULL is in capital
    return rand();
}
int random_rangeBased(int start, int ending)
{
    int x = randomFunctionUtil();
    int diff = ending - start;
    return (x % diff ) + start;
}

double random_floatingPoint_zeroToOne()
{
    int x  = randomFunctionUtil();
    double r = static_cast <double> (x) / static_cast <double> (RAND_MAX);
    return r;
}

double random_floatingPoint_range( double start, double ending)
{
    int x = randomFunctionUtil();
    double r = start + static_cast <double> (x) /( static_cast <double> (RAND_MAX/(ending-start)));
    return r;
}


int main()
{
    //function testing:
    //1
    //cout << randomFunctionUtil();

    //2
    //cout << random_rangeBased(110, 115);

    //3
    //cout << random_floatingPoint_zeroToOne();

    //4
    //cout << random_floatingPoint_range(10, 20);

}

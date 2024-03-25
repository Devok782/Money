#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
    //Money() test
    Money empty;

    //Money(int, int) test
    Money m1(32, 45);
    Money m2(67, 73);

    //operator+ test
    Money sum = m1 + m2;

    //operator- test
    Money subtrahend(93, 75);
    Money minusend(67, 84);
    Money difference = subtrahend - minusend;

    //operator* test
    Money factor(7, 57);
    Money product = factor * 7;

    //operator/ test
    Money dividend(18, 96);
    Money quotient = dividend / 3;

    //compound test
    Money c1(11, 13);
    Money c2(45, 65);
    Money c3(37, 86);

    Money compound = c1 + c2 - c3;

}
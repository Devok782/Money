#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using std::istream;
using std::ostream;

using namespace std;

class Money
{
    private:
        int* dollars;
        int* cents;

    public: 
        //Money(int d=0, int c= 0); //couldn't get to work as assignment wants
        //Money() : dollars(0), cents(0) {} //this works, but not what assignment wants
        Money(); //default constructor, same as above // works
        // Money(int d, int c) : dollars(d), cents(c) {}
        Money(int, int); //arg constructor     //works
        Money(const Money&); //copy constructor
        ~Money();   //destructor
        Money& operator=(const Money&); //function that overloads an operator
        Money operator+(const Money&) const;    //overloaded +
        Money operator-(const Money&) const;    //overloaded -
        Money& operator*(double);               //overloaded *
        Money& operator/(double);               //overloaded /

        friend istream& operator>>(istream&, Money&);
        friend ostream& operator<<(ostream&, const Money&);
};

#endif
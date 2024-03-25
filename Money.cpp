#include "Money.h"

// Money::Money(int d = 0, int c = 0) doesn't work
// {
//     dollars = new int(d);
//     cents = new int(c);
// }

//default constructor
Money::Money()  //works, but not what assignment wants
{
    cout << "Money() called" << endl;
    dollars = 0;
    cents = 0;
}

//arg constructor
Money::Money(int d/*=0*/, int c/*= 0*/) //same as above
{
    cout << "Money(int, int) called" << endl;
    dollars = new int(d);
    cents = new int(c);

    //Checks if cents is over 99 when created, and fixes accordingly
    if (*cents > 99)
    {
        int temp = *cents / 100;
        *dollars += temp;
        *cents = *cents % 100;
    }
}

//copy constructor
Money::Money(const Money& right)
{
    cout << "Money(const Money&) called" << endl;
    dollars = new int(*right.dollars);
    cents = new int(*right.cents);
    cout << "$" << *dollars << "." << *cents << endl;
}

//destructor
Money::~Money()
{
    cout << "~Money called" << endl;
    delete dollars;
    delete cents;
}

//function that overloads an operator
//pointer swapping technique 
Money& Money::operator=(const Money& right)
{
    //1. create a local object
    cout << "Money& operator= called" << endl;
    Money local(right);

    //2. swap pointers and money values
    int* temp_dollars = this->dollars;
    this->dollars = local.dollars;
    local.dollars = temp_dollars;

    int* temp_cents = this->cents;
    this->cents = local.cents;
    local.cents = temp_cents;
    cout << "$" << local.dollars << "." << local.cents << endl;
    
    //3. return *this
    return *this;
}

Money Money::operator+(const Money& right) const
{
    //Increased variables by the amount added
    cout << "Money operator+ called" << endl;
    *dollars += *right.dollars;
    *cents += *right.cents;

    //If over 99, increments dollars by amount divided
    // and sets cents to remainder
    if (*cents > 99)
    {
        int temp = *cents / 100;
        *dollars += temp;
        *cents = *cents % 100;
    }

    cout << "$" << *dollars << "." << *cents << endl;
    return *this;
}
        
Money Money::operator-(const Money& right) const
{
    //Creates variables for what's being subtracted from,
    //and what amount it is subtracting
    cout << "Money operator- called" << endl;
    int temp_amount = (*dollars * 100) + *cents; 
    int temp_subtract = (*right.dollars * 100) + *right.cents;

    //Splits amount back into individual variables after subtraction
    *dollars = (temp_amount - temp_subtract) / 100;
    *cents = (temp_amount - temp_subtract) % 100;
    //*dollars -= *right.dollars;
    //*cents -= *right.cents;

    cout << "$" << *dollars << "." << *cents << endl;
    return *this;
}
        
Money& Money::operator*(double k)
{
    //Multiplies given amount by k
    cout << "Money operator* called" << endl;
    *dollars *= k;
    *cents *= k;

    //If over 99, increments dollars by amount divided 
    //and sets cents to remainder
    if (*cents > 99)
    {
        int temp = *cents / 100;
        *dollars += temp;
        *cents = *cents % 100;
    }

    cout << "$" << *dollars << "." << *cents << endl;
    return *this;
}
        
Money& Money::operator/(double k)
{
    cout << "Money operator/ called" << endl;
    int temp_amount = (*dollars * 100) + *cents;
    *dollars = (temp_amount / k) / 100;
    int temp_cents = (temp_amount / k);
    *cents = temp_cents % 100;

    cout << "$" << *dollars << "." << *cents << endl;
    return *this;
}

istream& operator>>(istream& in, Money& money)
{
    cout << "istream& operator>> called" << endl;
    char dollarSign;
    double allocDouble;

    in >> dollarSign;
    in >> allocDouble;

    *money.dollars = static_cast<int>(allocDouble);
    *money.cents = static_cast<int>(allocDouble * 100) % 100;
    return in;
}

ostream& operator<<(ostream& out, const Money& money)
{
    cout << "ostream& operator<< called" << endl;
    out << "$" << money.dollars << "." << money.cents;
    return out;
}
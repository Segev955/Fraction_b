// helped: https://www.youtube.com/watch?v=o-qRv9WjGdE

#ifndef FRACTION_A_FRACTION_H
#define FRACTION_A_FRACTION_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>



namespace ariel {}
using namespace std;


class Fraction {
private:
    int num;
    int den;
public:
//constructor:
    Fraction();
    Fraction(const int &num1,const int &num2);
    Fraction(double num); //double
//getters:
    int getNumerator() const;
    int getDenominator() const;

    //Add
    Fraction operator+(const Fraction &other) const;
    Fraction operator+(const double &other) const;
    friend Fraction operator+(const double &num , const Fraction &other)
    {return Fraction(num) + other;}

    //Sub
    Fraction operator-(const Fraction &other) const;
    Fraction operator-(const double &other) const;
    friend Fraction operator-(const double &num , const Fraction &other)
    {return Fraction(num) - other;}

    //Mul
    Fraction operator*(const Fraction &other) const;
    Fraction operator*(const double &other) const;
    friend Fraction operator*(const double &num , const Fraction &other)
    {return Fraction(num) * other;}

    //Dev
    Fraction operator/(const Fraction &other) const;
    Fraction operator/(const double &other) const;
    friend Fraction operator/(const double &num , const Fraction &other)
    {return Fraction(num) / other;}

    //Equal
    bool operator==(const Fraction &other) const;
    bool operator==(const double &other) const;
    friend bool operator==(const double &num,const Fraction &other)
    {return Fraction(num) == other;}

    //Bigger
    bool operator>(const Fraction &other) const;
    bool operator>(const double &other) const;
    friend bool operator>(const double &num,const Fraction &other)
    {return Fraction(num) > other;}

    //Smaller
    bool operator<(const Fraction &other) const;
    bool operator<(const double &other) const;
    friend bool operator<(const double &num,const Fraction &other)
    {return Fraction(num) < other;}


    bool operator<=(const Fraction &other) const;
    bool operator<=(const double &other) const;
    friend bool operator<=(const double &num,const Fraction &other)
    {return Fraction(num) <= other;}

    bool operator>=(const Fraction &other) const;
    bool operator>=(const double &other) const;
    friend bool operator>=(const double &num,const Fraction &other)
    {return Fraction(num) >= other;}

    //Output
    friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction);
    //Input
    friend std::istream &operator>>(std::istream &input, Fraction &fraction);

    friend Fraction &operator++(Fraction &fra); //++n
    friend const Fraction operator++(Fraction &fra, int val); //n++
    friend Fraction &operator--(Fraction &fra); //--n
    friend const Fraction operator--(Fraction &fra, int val); //n--

    operator string() const;
    //Helpers
    void setPre(float num);
    void reduce();
    //Overflow
    bool overAdd(const Fraction &fra1, const Fraction &fra2) const;
    bool overSub(const Fraction &fra1, const Fraction &fra2) const;
    bool overMul(const Fraction &fra1, const Fraction &fra2) const;
    bool overDev(const Fraction &fra1, const Fraction &fra2) const;

};


#endif //FRACTION_A_FRACTION_H







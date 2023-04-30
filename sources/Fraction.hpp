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
    Fraction();
    Fraction(const int &num1,const int &num2);
    Fraction(int n);
    Fraction(const Fraction &other);
    Fraction(double num);
    Fraction(float num);
//getters:
    int getNumerator() const;
    int getDenominator() const;

    Fraction operator+(const Fraction &other) const;
    Fraction operator+(const float &other) const;
    Fraction operator+(const double &other) const;
    Fraction operator+(const int &other) const;
    friend Fraction operator+(const double &num , const Fraction &other)
    {return Fraction(num) + other;}


    Fraction operator-(const Fraction &other) const;
    Fraction operator-(const float &other) const;
    Fraction operator-(const double &other) const;
    Fraction operator-(const int &other) const;
    friend Fraction operator-(const double &num , const Fraction &other)
    {return Fraction(num) - other;}

    Fraction operator*(const Fraction &other) const;
    Fraction operator*(const float &other) const;
    Fraction operator*(const double &other) const;
    Fraction operator*(const int &other) const;
    friend Fraction operator*(const double &num , const Fraction &other)
    {return Fraction(num) * other;}

    Fraction operator/(const Fraction &other) const;
    Fraction operator/(const float &other) const;
    Fraction operator/(const double &other) const;
    Fraction operator/(const int &other) const;
    friend Fraction operator/(const double &num , const Fraction &other)
    {return Fraction(num) / other;}


    bool operator==(const Fraction &other) const;
    bool operator==(const float &other) const;
    bool operator==(const double &other) const;
    bool operator==(const int &other) const;
    friend bool operator==(const double &num,const Fraction &other)
    {return Fraction(num) == other;}

    bool operator>(const Fraction &other) const;
    bool operator>(const float &other) const;
    bool operator>(const double &other) const;
    bool operator>(const int &other) const;
    friend bool operator>(const double &num,const Fraction &other)
    {return Fraction(num) > other;}

    bool operator<(const Fraction &other) const;
    bool operator<(const float &other) const;
    bool operator<(const double &other) const;
    bool operator<(const int &other) const;
    friend bool operator<(const double &num,const Fraction &other)
    {return Fraction(num) < other;}

    bool operator<=(const Fraction &other) const;
    bool operator<=(const float &other) const;
    bool operator<=(const double &other) const;
    bool operator<=(const int &other) const;
    friend bool operator<=(const double &num,const Fraction &other)
    {return Fraction(num) <= other;}

    bool operator>=(const Fraction &other) const;
    bool operator>=(const float &other) const;
    bool operator>=(const double &other) const;
    bool operator>=(const int &other) const;
    friend bool operator>=(const double &num,const Fraction &other)
    {return Fraction(num) >= other;}

    friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction);

    friend std::istream &operator>>(std::istream &input, Fraction &fraction);

    friend Fraction &operator++(Fraction &fra); //++n
    friend const Fraction operator++(Fraction &fra, int val); //n++



    friend Fraction &operator--(Fraction &fra); //--n
    friend const Fraction operator--(Fraction &fra, int val); //n--

//    operator double() const; //convert to double
    operator string() const;
    void setPre(float num);
    void reduce();
    bool overAdd(const Fraction &fra1, const Fraction &fra2) const;
    bool overSub(const Fraction &fra1, const Fraction &fra2) const;
    bool overMul(const Fraction &fra1, const Fraction &fra2) const;
    bool overDev(const Fraction &fra1, const Fraction &fra2) const;

};


#endif //FRACTION_A_FRACTION_H







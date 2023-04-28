// helped: https://www.youtube.com/watch?v=o-qRv9WjGdE

#ifndef FRACTION_A_FRACTION_H
#define FRACTION_A_FRACTION_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>



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

    Fraction operator+(const Fraction &other);
    Fraction operator+(const float &other);
    Fraction operator+(const double &other);
    Fraction operator+(const int &other);

    Fraction operator-(const Fraction &other);
    Fraction operator-(const float &other);
    Fraction operator-(const double &other);
    Fraction operator-(const int &other);

    Fraction operator*(const Fraction &other);
    Fraction operator*(const float &other);
    Fraction operator*(const double &other);
    Fraction operator*(const int &other);

    Fraction operator/(const Fraction &other);
    Fraction operator/(const float &other);
    Fraction operator/(const double &other);
    Fraction operator/(const int &other);

    bool operator==(const Fraction &other);
    bool operator==(const float &other);
    bool operator==(const double &other);
    bool operator==(const int &other);

    bool operator>(const Fraction &other);
    bool operator>(const float &other);
    bool operator>(const double &other);
    bool operator>(const int &other);

    bool operator<(const Fraction &other);
    bool operator<(const float &other);
    bool operator<(const double &other);
    bool operator<(const int &other);

    bool operator<=(const Fraction &other);
    bool operator<=(const float &other);
    bool operator<=(const double &other);
    bool operator<=(const int &other);

    bool operator>=(const Fraction &other);
    bool operator>=(const float &other);
    bool operator>=(const double &other);
    bool operator>=(const int &other);

    friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction);

    friend std::istream &operator>>(std::istream &input, Fraction &fraction);

    Fraction &operator++(); //++n
    const Fraction operator++(int); //n++

    Fraction &operator--(); //--n
    const Fraction operator--(int); //n--

    operator double() const; //convert to double
    operator string() const;
    void setPre(float num);
    void reduce();

};


#endif //FRACTION_A_FRACTION_H









#include "Fraction.hpp"

Fraction::Fraction(int num1, int num2) {
    this->num = num1;
    this->den = num2;
}

Fraction::Fraction(int n): Fraction(n,1) {}

Fraction::operator double() const {
    return double(num) / double(den);
}

Fraction::operator string() const {
    return to_string(num) + "/" + to_string(den);
}

//Fraction::Fraction(double num) {
//    this->num = num;
//    this->den = 1;
//}

int Fraction::getNum() const { return this->num; }

int Fraction::getDen() const { return this->den; }

//add
Fraction Fraction::operator+(const Fraction &other) {
    int n = (this->num * other.den) + (this->den * other.num);
    int d = this->den * other.den;
    return Fraction(n, d);
}

//add double
Fraction Fraction::operator+(const double &other) {
    double ans = (double) this->num / this->den + other;
    return Fraction(ans);
}

//sub
Fraction Fraction::operator-(const Fraction &other) {
    int n = (this->num * other.den) - (this->den * other.num);
    int d = this->den * other.den;
    return Fraction(n, d);
}

//sub double
Fraction Fraction::operator-(const double &other) {
    double ans = (double) this->num / this->den - other;
    return Fraction(ans);
}

//sub int
Fraction Fraction::operator-(const int &other) {
    double ans = (double) this->num / this->den - other;
    return Fraction(ans);
}

//mul
Fraction Fraction::operator*(const Fraction &other) {
    int n = this->num * other.num;
    int d = this->den * other.den;
    return Fraction(n, d);
}

//mul double
Fraction Fraction::operator*(const double &other) {
    double ans = (double) this->num / this->den * other;
    return Fraction(ans);

}

//dev
Fraction Fraction::operator/(const Fraction &other) {
    int n = this->num * other.den;
    int d = this->den * other.num;
    return Fraction(n, d);
}

//dev double
Fraction Fraction::operator/(const double &other) {
    double ans = (double) this->num / this->den / other;
    return Fraction(ans);
}

//equal
bool Fraction::operator==(const Fraction &other) {
    double n = (double) this->num / this->den;
    double o = (double) other.num / other.den;
    return n == o;
}

//equal double
bool Fraction::operator==(const double &other) {
    double n = (double) this->num / this->den;
    return n == other;
}

//Bigger
bool Fraction::operator>(const Fraction &other) {
    double n = (double) this->num / this->den;
    double o = (double) other.num / other.den;
    return n > o;
}

//bigger double
bool Fraction::operator>(const double &other) {
    double n = (double) this->num / this->den;
    return n > other;
}

//Smaller
bool Fraction::operator<(const Fraction &other) {
    double n = (double) this->num / this->den;
    double o = (double) other.num / other.den;
    return n < o;
}

//Smaller double
bool Fraction::operator<(const double &other) {
    double n = (double) this->num / this->den;
    return n < other;
}

//Smaller or equal
bool Fraction::operator<=(const Fraction &other) {
    double n = (double) this->num / this->den;
    double o = (double) other.num / other.den;
    return n <= o;
}

//Smaller or equal (double)
bool Fraction::operator<=(const double &other) {
    double n = (double) this->num / this->den;
    return n <= other;
}

//bigger or equal
bool Fraction::operator>=(const Fraction &other) {
    double n = (double) this->num / this->den;
    double o = (double) other.num / other.den;
    return n >= o;
}

//bigger or equal (double)
bool Fraction::operator>=(const double &other) {
    double n = (double) this->num / this->den;
    return n >= other;
}

std::ostream &operator<<(std::ostream &output, const Fraction &fraction) {
    return output << to_string(fraction.getNum()) << to_string(fraction.getDen());
}

std::istream &operator>>(std::istream &input, Fraction &fraction) {
//    int n, d;
//    char c;
//    if (input >> n >> c >> d) {
//        if (c == '/') {
//            fraction.num = n;
//            fraction.den = d;
//        } else
//            input.setstate(std::ios_base::failbit);
//    }
    return input;
}



Fraction &Fraction::operator++() { //++n

    return *this;
}

const Fraction Fraction::operator++(int) {//n++
    Fraction cpy(*this);
    return cpy;
}

Fraction &Fraction::operator--() { //--n
    return *this;
}

const Fraction Fraction::operator--(int) { //n--
    Fraction cpy(*this);
    return cpy;
}

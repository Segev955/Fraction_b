#include "Fraction.hpp"

using namespace ariel;

//constructor
Fraction::Fraction(const int &num1, const int &num2) : num(num1), den(num2) {
    if (num2 == 0) {
        throw invalid_argument("Division by zero is undefined");
    }
    reduce();
}
Fraction::Fraction(): num(0), den(1){
    
}

//copy
Fraction::Fraction(const Fraction &other) : num(other.num), den(other.den) {}

//int
Fraction::Fraction(int n) : Fraction(n, 1) {}

//double convert
Fraction::operator double() const {
    return double(num) / double(den);
}

//Fraction::operator string() const {
//    return to_string(num) + "/" + to_string(den);
//}
//double constructor
Fraction::Fraction(double num) {
    setPre(float(num));
    reduce();
}

//float (for the test)
Fraction::Fraction(float num) {
    setPre(num);
    reduce();
}

int Fraction::getNumerator() const { return this->num; }

int Fraction::getDenominator() const { return this->den; }

//add
Fraction Fraction::operator+(const Fraction &other) {
    int n = (this->num * other.den) + (this->den * other.num);
    int d = this->den * other.den;
    return Fraction(n, d);
}

//add float
Fraction Fraction::operator+(const float &other) {
    float ans = (float) this->num / this->den + other;
    return Fraction(ans);
}

//add double
Fraction Fraction::operator+(const double &other) {
    float ans = (float) this->num / this->den + other;
    return Fraction(ans);
}

//add int
Fraction Fraction::operator+(const int &other) {
    float ans = (float) this->num / this->den + other;
    return Fraction(ans);
}

//Fraction Fraction::operator+(const double &num1, const double &num2) {
//    double ans = num1 + num2;
//    return Fraction(ans);
//}

//sub
Fraction Fraction::operator-(const Fraction &other) {
    int n = (this->num * other.den) - (this->den * other.num);
    int d = this->den * other.den;
    return Fraction(n, d);
}

//sub float
Fraction Fraction::operator-(const float &other) {
    float ans = (float) this->num / this->den - other;
    return Fraction(ans);
}

//sub double
Fraction Fraction::operator-(const double &other) {
    float ans = (float) this->num / this->den - other;
    return Fraction(ans);
}

//sub int
Fraction Fraction::operator-(const int &other) {
    float ans = (float) this->num / this->den - other;
    return Fraction(ans);
}

//mul
Fraction Fraction::operator*(const Fraction &other) {
    int n = this->num * other.num;
    int d = this->den * other.den;
    return Fraction(n, d);
}

//mul float
Fraction Fraction::operator*(const float &other) {
    float ans = (float) this->num / this->den * other;
    return Fraction(ans);

}

//mul double
Fraction Fraction::operator*(const double &other) {
    float ans = (float) this->num / this->den * other;
    return Fraction(ans);

}

//mul int
Fraction Fraction::operator*(const int &other) {
    float ans = (float) this->num / this->den * other;
    return Fraction(ans);

}

//dev
Fraction Fraction::operator/(const Fraction &other) {
    int n = this->num * other.den;
    int d = this->den * other.num;
    return Fraction(n, d);
}

//dev float
Fraction Fraction::operator/(const float &other) {
    if (other == 0.0) {
        throw invalid_argument("Division by zero is undefined");
    }
    float ans = (float) this->num / this->den / other;
    return Fraction(ans);
}

//dev double
Fraction Fraction::operator/(const double &other) {
    if (other == 0.0) {
        throw invalid_argument("Division by zero is undefined");
    }
    float ans = (float) this->num / this->den / other;
    return Fraction(ans);
}

//dev int
Fraction Fraction::operator/(const int &other) {
    if (other == 0) {
        throw invalid_argument("Division by zero is undefined");
    }
    float ans = (float) this->num / this->den / other;
    return Fraction(ans);
}

//equal
bool Fraction::operator==(const Fraction &other) {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n == o;
}

//equal float
bool Fraction::operator==(const float &other) {
    float n = (float) this->num / this->den;
    return n == other;
}

//equal double
bool Fraction::operator==(const double &other) {
    float n = (float) this->num / this->den;
    return n == other;
}

//equal int
bool Fraction::operator==(const int &other) {
    float n = (float) this->num / this->den;
    return n == other;
}

//Bigger
bool Fraction::operator>(const Fraction &other) {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n > o;
}

//bigger float
bool Fraction::operator>(const float &other) {
    float n = (float) this->num / this->den;
    return n > other;
}

//bigger double
bool Fraction::operator>(const double &other) {
    float n = (float) this->num / this->den;
    return n > other;
}

//bigger int
bool Fraction::operator>(const int &other) {
    float n = (float) this->num / this->den;
    return n > other;
}

//Smaller
bool Fraction::operator<(const Fraction &other) {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n < o;
}

//Smaller float
bool Fraction::operator<(const float &other) {
    float n = (float) this->num / this->den;
    return n < other;
}

//Smaller double
bool Fraction::operator<(const double &other) {
    float n = (float) this->num / this->den;
    return n < other;
}

//Smaller int
bool Fraction::operator<(const int &other) {
    float n = (float) this->num / this->den;
    return n < other;
}

//Smaller or equal
bool Fraction::operator<=(const Fraction &other) {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n <= o;
}

//Smaller or equal (float)
bool Fraction::operator<=(const float &other) {
    float n = (float) this->num / this->den;
    return n <= other;
}

//Smaller or equal (double)
bool Fraction::operator<=(const double &other) {
    float n = (float) this->num / this->den;
    return n <= other;
}

//Smaller or equal (int)
bool Fraction::operator<=(const int &other) {
    float n = (float) this->num / this->den;
    return n <= other;
}

//bigger or equal
bool Fraction::operator>=(const Fraction &other) {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n >= o;
}

//bigger or equal (float)
bool Fraction::operator>=(const float &other) {
    float n = (float) this->num / this->den;
    return n >= other;
}

//bigger or equal (double)
bool Fraction::operator>=(const double &other) {
    float n = (float) this->num / this->den;
    return n >= other;
}

//bigger or equal (int)
bool Fraction::operator>=(const int &other) {
    float n = (float) this->num / this->den;
    return n >= other;
}

std::ostream &operator<<(std::ostream &output, const Fraction &fraction) {
    output << fraction.num << '/' << fraction.den;
    return output;
}

std::istream &operator>>(std::istream &input, Fraction &fraction) {
    int n, d;
//    char c;
    if (input >> n >> d) {
        fraction.num = n;
        fraction.den = d;
//        } else
//            input.setstate(std::ios_base::failbit);

    } else {
        throw invalid_argument("Input 2 numbers");

    }
    return input;
}


Fraction &Fraction::operator++() { //++n
    this->num += this->den;
    return *this;
}

const Fraction Fraction::operator++(int) {//n++
    Fraction current = *this;
    this->num += this->den;
    return current;
}

Fraction &Fraction::operator--() { //--n
    this->num -= this->den;
    return *this;
}

const Fraction Fraction::operator--(int) { //n--
    Fraction current = *this;
    this->num -= this->den;
    return current;
}

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void Fraction::reduce() {
    int n = gcd(num, den);
    this->num = num / n;
    this->den = den / n;
}

void Fraction::setPre(float num) {
//set precision 3 digits
    std::ostringstream os;
    os << std::fixed << std::setprecision(3) << num;
    num = stod(os.str());
    int d = 1;
    while (std::ceil(num * d != std::floor(num * d))) {
        d *= 10;
    }
    this->num = int(num * d);
    this->den = d;
}





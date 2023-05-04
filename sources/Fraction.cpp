#include "Fraction.hpp"

using namespace ariel;


//default
Fraction::Fraction() : num(0), den(1) {}

//constructor
Fraction::Fraction(const int &num1, const int &num2) : num(num1), den(num2) {
    if (num2 == 0) {
        throw invalid_argument("Division by zero is undefined");
    }
    reduce();
    //Minus at the numerator
    if (this->den < 0) {
        this->num = this->num * -1;
        this->den = this->den * -1;
    }
}

//double constructor
Fraction::Fraction(double num) {
    setPre(float(num));
    reduce();
}

//getters:
int Fraction::getNumerator() const { return this->num; }
int Fraction::getDenominator() const { return this->den; }

//add
Fraction Fraction::operator+(const Fraction &other) const {
    int n = (this->num * other.den) + (this->den * other.num);
    int d = this->den * other.den;
    if (overAdd(*this, other))
        throw std::overflow_error("overflow");
    return Fraction(int(n), int(d));
}

//add double
Fraction Fraction::operator+(const double &other) const {
    return *this + Fraction(other);
}

//sub
Fraction Fraction::operator-(const Fraction &other) const {
    int n = (this->num * other.den) - (this->den * other.num);
    int d = this->den * other.den;
    if (overSub(*this, other))
        throw std::overflow_error("overflow");
    return Fraction(int(n), int(d));
}

//sub double
Fraction Fraction::operator-(const double &other) const {
    return *this - Fraction(other);
}

//mul
Fraction Fraction::operator*(const Fraction &other) const {
    int n = this->num * other.num;
    int d = this->den * other.den;
    if (overMul(*this, other))
        throw std::overflow_error("overflow");
    return Fraction(int(n), int(d));
}

//mul double
Fraction Fraction::operator*(const double &other) const {
    return *this * Fraction(other);
}

//dev
Fraction Fraction::operator/(const Fraction &other) const {
    if (other.num == 0) {
        throw runtime_error("Division by zero is undefined");
    }
    int n = this->num * other.den;
    int d = this->den * other.num;
    if (overDev(*this, other))
        throw std::overflow_error("overflow");
    return Fraction(int(n), int(d));
}

//dev double
Fraction Fraction::operator/(const double &other) const {
    if (other == 0.0) {
        throw runtime_error("Division by zero is undefined");
    }
    return *this / Fraction(other);
}

//equal
bool Fraction::operator==(const Fraction &other) const {
//    reduce();
    if (this->den < 0) {
        Fraction fra(this->num * -1, this->den * -1);
        return fra.num  == other.num && fra.den == other.den;

    }
    return this->num == other.num && this->den == other.den;
}

//equal double
bool Fraction::operator==(const double &other) const {
    Fraction a(other);
    return this->num == a.num && this->den == a.den;
}

//Bigger
bool Fraction::operator>(const Fraction &other) const {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n > o;
}

//bigger double
bool Fraction::operator>(const double &other) const {
    float n = (float) this->num / this->den;
    return n > other;
}

//Smaller
bool Fraction::operator<(const Fraction &other) const {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n < o;
}

//Smaller double
bool Fraction::operator<(const double &other) const {
    Fraction a(other);
    return *this < a;
}

//Smaller or equal
bool Fraction::operator<=(const Fraction &other) const {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n <= o;
}

//Smaller or equal (double)
bool Fraction::operator<=(const double &other) const {
    float n = (float) this->num / this->den;
    return n <= other;
}

//bigger or equal
bool Fraction::operator>=(const Fraction &other) const {
    float n = (float) this->num / this->den;
    float o = (float) other.num / other.den;
    return n >= o;
}

//bigger or equal (double)
bool Fraction::operator>=(const double &other) const {
    float n = (float) this->num / this->den;
    return n >= other;
}

//Output
std::ostream &operator<<(std::ostream &output, const Fraction &fraction) {
    int one = 1;
    if (fraction.den < 0)
        one = -1;
    output << (fraction.num * one) << '/' << (fraction.den * one);
    return output;
}

//Input
std::istream &operator>>(std::istream &input, Fraction &fraction) {
    int n, d;
    if (input >> n >> d) {
        if (d == 0) {
            throw runtime_error("Division by zero is undefined");
        }
        if (n == 0) { //Fraction equal 0
            fraction.num = n;
            fraction.den = 1;
        } else {
            fraction.num = n;
            fraction.den = d;
        }
    } else {
        throw runtime_error("Input 2 numbers");
    }

    return input;
}

Fraction &operator++(Fraction &fra) { //++n
    fra = fra + 1;
    return fra;
}

const Fraction operator++(Fraction &fra, int val) {//n++
    Fraction current = fra;
    fra = fra + 1;
    return current;
}

Fraction &operator--(Fraction &fra) { //--n
    fra = fra - 1;
    return fra;
}

const Fraction operator--(Fraction &fra, int val) { //n--
    Fraction current = fra;
    fra = fra - 1;
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

//set precision 3 digits
void Fraction::setPre(float num) {
    std::ostringstream os;
    os << std::fixed << std::setprecision(3) << num; //to string
    num = stod(os.str()); //back to float
    int d = 1;
    while (std::ceil(num * d != std::floor(num * d))) {
        d *= 10;
    }
    this->num = int(num * d);
    this->den = d;
}

//overflows:
bool Fraction::overAdd(const Fraction &fra1, const Fraction &fra2) const {
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    return ((fra1.num == max_int && fra1.den != max_int)
            || (fra1.num <= min_int + 100 && fra2.num <= min_int + 100)
            || (fra2.num == max_int && fra2.den != max_int));
}

bool Fraction::overSub(const Fraction &fra1, const Fraction &fra2) const {
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    return ((fra1.num <= min_int + 100 && fra2.num <= min_int + 100)
            || (fra1.num >= max_int - 100 && fra2.num <= min_int + 100));
}

bool Fraction::overMul(const Fraction &fra1, const Fraction &fra2) const {
    int max_int = std::numeric_limits<int>::max();
    return ((fra1.num == max_int && fra1.den != max_int)
            || (fra1.den == max_int && fra1.num != max_int)
            || (fra2.num == max_int && fra2.den != max_int));
}


bool Fraction::overDev(const Fraction &fra1, const Fraction &fra2) const {
    int max_int = std::numeric_limits<int>::max();
    return ((fra1.den == max_int && fra1.num < max_int - 100)
            || (fra1.num == max_int && fra1.den != max_int));
}

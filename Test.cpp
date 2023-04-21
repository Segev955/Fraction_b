#include <iostream>
#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("init") {
    Fraction a(1, 2);
    CHECK(a.getNum() == 1);
    CHECK(a.getDen() == 2);

    Fraction b(8, 2);
    CHECK(b.getNum() == 4);
    CHECK(b.getDen() == 1);
}

TEST_CASE("operators") {
    Fraction a(1, 2), b(1, 4), c(-1 , 2), d(-1, 4);
    CHECK(a + b == Fraction(3, 4));
    CHECK(a - b == b); //b = 1/4
    CHECK(a * b == Fraction(1, 8));
    CHECK(a / b == Fraction(4, 2));
    //negative:
    CHECK(c + d == Fraction(-3, 4));
    CHECK(c - d == Fraction(-1, 4));
    CHECK(c * d == Fraction(1, 8));
    CHECK(c / d == Fraction(2, 1));

}

TEST_CASE("comparison operators") {
    Fraction a(3, 8), b(1, 5);
    CHECK((a > b) == ((double) 3 / 8) > ((double) 1 / 5));
    CHECK((a < b) == ((double) 3 / 8) < ((double) 1 / 5));
    Fraction c(1, 4), d(2, 4);
    CHECK((c >= d) == ((double) 1 / 4) >= ((double) 2 / 4));
    CHECK((c <= d) == ((double) 1 / 4) <= ((double) 2 / 4));
}

TEST_CASE("double") {
    Fraction a(1, 2);
    //ADD:
    Fraction b = 0.4 + a;
    cout << b.getNum() << '/' <<b.getDen() << endl;
    CHECK(0.4 + a == 0.9);
    CHECK(a + 0.4 == 0.9);
    //SUB:
    CHECK(a - 0.4 == 0.1);
    CHECK(0.7 - a == 0.2);
    //MUL:
    CHECK(a * 0.5 == 0.25);
    CHECK(0.5 * a == 0.25);
    //DIV:
    CHECK(a / 0.4 == 1.25);
    CHECK(0.4 / a == 0.8);
}

TEST_CASE("Adds") {
    Fraction a(1, 2);
    CHECK(a++ == Fraction(1, 2));
    CHECK(++a == Fraction(3, 2));
    Fraction b(5, 2);
    CHECK(b++ == Fraction(5, 2));
    CHECK(++b == Fraction(7, 2));
}

TEST_CASE("Substracts") {
    Fraction a(3, 2);
    CHECK(a-- == Fraction(3, 2));
    CHECK(--a == Fraction(1, 2));
    Fraction b(7, 2);
    CHECK(b-- == Fraction(7, 2));
    CHECK(--b == Fraction(5, 2));

}

TEST_CASE("test") {
    CHECK_THROWS(Fraction(3, 0)); // Division by zero is undefined
    CHECK_THROWS(Fraction(0, 0)); // Division by zero is undefined
    Fraction a(0, 1234);
    CHECK(a == 0.0);
    CHECK(Fraction (2, 4) == Fraction(1,2));
    
}

TEST_CASE("ostream") {
    Fraction a(3, 2), b(10, 1);
    std::ostringstream s;
    s << a;
    CHECK_EQ(s.str(), "3/2");
    s << b;
    CHECK_EQ(s.str(), "10");
}



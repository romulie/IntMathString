/*
# IntMathString
String-based class for integer math calculations with huge numbers
You can create arbitrary-long integers using strings or standard integers.
And perform math and boolean operations on them:
boolean ==, !=, <, >, <=, >=
Summation +
Subtraction -
Increment ++i, i++
Decrement --i, i--
Multyplication *
Integer division /
Modulo division %
Factorial method
<< and >> for std::cout and std::cin operations
*/
#ifndef INTMATHSTRING_H
#define INTMATHSTRING_H

#include <iostream>
#include <string>
#include "sum_strings.h"
#include "subtract_strings.h"
#include "compare_MathStrings.h"
#include "multiply_strings.h"
#include "divide_strings.h"

class IntMathString
{
    public:
        IntMathString() { this -> s = "0"; };               /// ctor
        IntMathString(long long int n) { this -> s = std::to_string(n); };/// ctor from int
        IntMathString(const std::string val);               /// ctor
        virtual ~IntMathString(){};                         /// dtor
        IntMathString(const IntMathString& other);          /// copy ctor
        IntMathString(IntMathString&& other)=default;       /// move ctor?
        IntMathString& operator=(const IntMathString& rhs); /// assignment operator
        IntMathString& operator=(const std::string& rhs);   /// assignment operator
        IntMathString operator+(const IntMathString& other);/// + operator
        IntMathString operator-(const IntMathString& other);/// - operator
        IntMathString operator*(const IntMathString& other);/// * operator (multiplication)
        IntMathString operator/(const IntMathString& other);/// / operator (integer division)
        IntMathString operator%(const IntMathString& other);/// % operator (modulo)
        IntMathString factorial();                          /// factorial
        bool operator<(const IntMathString& other);         /// < operator
        bool operator>(const IntMathString& other);         /// > operator
        bool operator<=(const IntMathString& other);        /// <= operator
        bool operator>=(const IntMathString& other);        /// >= operator
        IntMathString& operator++();                        /// ++i pre-increment operator
        IntMathString operator++(int foo);                  /// i++ post-increment operator
        IntMathString& operator--();                        /// --i pre-decrement operator
        IntMathString operator--(int foo);                  /// i-- post-decrement operator
        friend std::string validate(std::string &s);               /// checks for validity of input string, replaces illegal symbols with '0'
        friend std::ostream& operator<<(std::ostream& os, const IntMathString& a);   /// << operator
        friend std::istream& operator>>(std::istream& is, IntMathString& a);         /// >> operator
        std::string get() { return s; }                     /// getter
        void set(std::string val) { s = val; }              /// setter
        size_t size() { return s.size(); }                  /// get size of the string (number of digits)

    private:
        std::string s;
};

#endif // INTMATHSTRING_H

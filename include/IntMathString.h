#ifndef INTMATHSTRING_H
#define INTMATHSTRING_H

#include <iostream>
#include <string>
#include "sum_strings.h"
#include "subtract_strings.h" /// !!!!WORKS ONLY FOR NON-NEGATIVE VALUES!!!!
#include "compare_MathStrings.h"

class IntMathString
{
    public:
        IntMathString() { this -> s = "0"; };               /// ctor
        IntMathString(int n) { this -> s = std::to_string(n); };/// ctor from int????
        IntMathString(std::string val) { this -> s = val; };/// ctor ??? CHECK FOR VALIDITY!
        virtual ~IntMathString(){};                         /// dtor
        IntMathString(const IntMathString& other);          /// copy ctor
        //IntMathString(IntMathString&& other)=default;       /// move ctor???????????????????????
        IntMathString& operator=(const IntMathString& rhs); /// assignment operator
        IntMathString& operator=(const std::string& rhs);   /// assignment operator
        IntMathString operator+(const IntMathString& other);/// + operator
        IntMathString operator-(const IntMathString& other);/// - operator !!!! WORKS ONLY WITH POSITIVE NUMBERS!!!!
        bool operator<(const IntMathString& other);         /// < operator
        bool operator>(const IntMathString& other);         /// > operator
        bool operator<=(const IntMathString& other);        /// <= operator
        bool operator>=(const IntMathString& other);        /// >= operator
        IntMathString& operator++();                        /// ++i pre-increment operator
        IntMathString operator++(int foo);                  /// i++ post-increment operator
        IntMathString& operator--();                        /// --i pre-decrement operator
        IntMathString operator--(int foo);                  /// i-- post-decrement operator
        friend std::ostream& operator<<(std::ostream& os, const IntMathString& a);   /// << operator
        friend std::istream& operator>>(std::istream& is, IntMathString& a);         /// >> operator
        std::string get() { return s; }                     /// getter
        void set(std::string val) { s = val; }              /// setter
        size_t size() { return s.size(); }                  /// get size of the string (number of digits)

    private:
        std::string s;
};

#endif // INTMATHSTRING_H

#ifndef INTMATHSTRING_H
#define INTMATHSTRING_H

#include <iostream>
#include <string>

//#include "sum_strings.h"

class IntMathString
{
    public:
        IntMathString() { this -> s = "0"; };               /// ctor
        IntMathString(std::string val) { this -> s = val; };/// ctor ??? CHECK FOR VALIDITY!
        virtual ~IntMathString(){};                         /// dtor
        IntMathString(const IntMathString& other);          /// copy ctor
                                                            /// move ctor
        IntMathString& operator=(const IntMathString& rhs); /// assignment operator
        IntMathString& operator=(const std::string& rhs);   /// assignment operator
        IntMathString operator+(const IntMathString& other);/// + operator
        friend std::ostream& operator<<(std::ostream& os, const IntMathString& a);   /// << operator
        friend std::istream& operator>>(std::istream& is, IntMathString& a);         /// >> operator
        std::string get() { return s; }                     /// getter
        void set(std::string val) { s = val; }              /// setter
        size_t size() { return s.size(); }                  /// get size of the string (number of digits)

    private:
        std::string s;


};

#endif // INTMATHSTRING_H

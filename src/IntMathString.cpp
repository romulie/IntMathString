#include "IntMathString.h"
#include "sum_strings.h"

std::istream& operator>>(std::istream& is, IntMathString& a){
    is >> a.s;
    return is;
}

std::ostream& operator<<(std::ostream& os, const IntMathString& a){
    os << a.s; /// Function call to overload the "<<" operator
    return os;//
}

IntMathString IntMathString::operator+(const IntMathString& other){
    IntMathString result;
    result.s = sum_strings(this->s, other.s);
    return result;
}

IntMathString::IntMathString(const IntMathString& other){
    //if (this->s != other.s){                 ///copy ctor
        this -> s = other.s;
    //}
}

IntMathString& IntMathString::operator=(const IntMathString& rhs){
    if (this == &rhs) return *this;   /// handle self assignment
    this -> s = rhs.s;                /// assignment operator
    return *this;
}

IntMathString& IntMathString::operator=(const std::string& rhs){
    this -> s = rhs;                  /// assignment operator from std::string
    return *this;
}

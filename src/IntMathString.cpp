#include "IntMathString.h"


IntMathString IntMathString::factorial(){ /// factorial
    IntMathString result(1);
    IntMathString cnt(*this);
    while (cnt > 1){
      result = result * cnt;
      --cnt;
    }
    return result;
}

IntMathString IntMathString::operator/(const IntMathString& other){ /// / operator (integer division)
    IntMathString result;
    result.s = divide_strings(this->s, other.s)[0];
    return result;
}

IntMathString IntMathString::operator%(const IntMathString& other){ /// % operator (modulo)
    IntMathString result;
    result.s = divide_strings(this->s, other.s)[1];
    return result;
}

IntMathString IntMathString::operator*(const IntMathString& other){ // multiplication operator
    IntMathString result;
    result.s = multiply_strings(this->s, other.s);
    return result;
}

IntMathString IntMathString::operator-(const IntMathString& other){
    IntMathString result;
    result.s = subtract_strings(this->s, other.s);
    return result;
}

IntMathString IntMathString::operator+(const IntMathString& other){
    IntMathString result;
    result.s = sum_strings(this->s, other.s);
    return result;
}

IntMathString& IntMathString::operator++(){                         /// ++i pre-increment operator
    *this = *this + IntMathString(1);
    //this -> s = sum_strings(this->s, "1");
    return *this;
}

IntMathString IntMathString::operator++(int foo){                         /// ++i post-increment operator
    IntMathString tmp(this -> s);
    //*this = *this + IntMathString(1);
    this -> s = sum_strings(this->s, "1");
    return tmp;
}

IntMathString& IntMathString::operator--(){                         /// --i pre-decrement operator
    //*this = *this - IntMathString(1);
    this -> s = subtract_strings(this->s, "1");
    //*this = *this - IntMathString(1);
    return *this;
}

IntMathString IntMathString::operator--(int foo){                         /// i-- post-decrement operator
    IntMathString tmp(this -> s);
    *this = *this - IntMathString(1);
    //this -> s = subtract_strings(this->s, "1");
    return tmp;
}

bool IntMathString::operator<(const IntMathString& other){         /// < operator
    int result = compare_MathStrings(this->s, other.s);
    return (result == -1);
}

bool IntMathString::operator>(const IntMathString& other){         /// > operator
    int result = compare_MathStrings(this->s, other.s);
    return (result == 1);
}

bool IntMathString::operator<=(const IntMathString& other){         /// <= operator
    int result = compare_MathStrings(this->s, other.s);
    return (result < 1);
}

bool IntMathString::operator>=(const IntMathString& other){         /// >= operator
    int result = compare_MathStrings(this->s, other.s);
    return (result > -1);
}

std::istream& operator>>(std::istream& is, IntMathString& a){
    is >> a.s;
    return is;
}

std::ostream& operator<<(std::ostream& os, const IntMathString& a){
    os << a.s; /// Function call to overload the "<<" operator
    return os;//
}

IntMathString::IntMathString(const IntMathString& other){       ///copy ctor
    //if (this->s != other.s){
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

#include "IntMathString.h"
#include <iostream>

//using namespace std;

int main(){
    IntMathString a, b, c;
    //std::string c{"123456"};
    a = "333";
    b = "30";
    //IntMathString c(9988);
    c = a % b;
    //--c;
    std::cout << "c = " << c <<std::endl;
    //std::cout << "--c = " << --c <<std::endl;///!! got problems with subtracting from negative values
    //std::cout << "++c = " << ++c <<std::endl;
    //std::cout << "c++ = " << c++ <<std::endl;
    //std::cout << "c = " << c <<std::endl;
    //std::cout << "++c = " << ++c <<std::endl;
    //std::cout << "c-- = " << c-- <<std::endl;///!!
    //std::cout << "c = " << c <<std::endl;
    //std::cout << "--c = " << --c <<std::endl;

    system("pause");
    return 0;
}

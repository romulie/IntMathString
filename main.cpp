#include "IntMathString.h"
#include <iostream>

//using namespace std;

int main(){
    IntMathString a, b(5), c;
    //std::string c{"123456"};
    a = "333";
    b = 500;
    //IntMathString c(9988);
    c = b.factorial();
    //--c;
    std::cout << "c = " << c.get() <<std::endl;
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

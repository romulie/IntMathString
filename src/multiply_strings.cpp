#include "multiply_strings.h"
std::string prod(const std::string &a, const char &b);


std::string multiply_strings(const std::string &a, const std::string &b){

std::string a1, b1;
bool minusSign = false;
    // manage negative values:
    if (a[0] == '-' && b[0] == '-')      {a1 = a.substr(1); b1 = b.substr(1);}
    else if (a[0] == '-' && b[0] != '-') {a1 = a.substr(1); b1 = b; minusSign = true;}
    else if (a[0] != '-' && b[0] == '-') {a1 = a; b1 = b.substr(1); minusSign = true;}
    else {a1 = a; b1 = b;}

std::string result = "";
std::string tmpProduct;
std::string zeroes = "";
int carry = 0;

    while (a1[0] == '0') a1.erase(0, 1);
    while (b1[0] == '0') b1.erase(0, 1);

    if ((a1.size() == 0) || (b1.size() == 0) || (a1 == "0") || (b1 == "0")) return "0";
    else if (a1.size() < b1.size()) std::swap(a1, b1);

    for (int i = b1.size()-1; i >= 0; i--){
        tmpProduct = prod(a1, b1[i]) + zeroes;
        result = sum_strings(result, tmpProduct);
        zeroes.push_back('0');
    }

    if (minusSign) result = "-" + result;

return result;
}
//=====================================================
std::string prod(const std::string &a, const char &b){

std::string result;
int carry = 0;

    if (b == '0') return "0";
    else {
        for (int i = a.size() - 1; i >= 0; i--){
            int tmpProd = (a[i] - '0') *  (b - '0') + carry;
            result = char(tmpProd % 10 + '0') + result;
            carry =  tmpProd / 10;
            }
        if (carry) result = char(carry + '0') + result;
    }
return result;
}

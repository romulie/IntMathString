#include "subtract_strings.h"

std::string subtract_strings(const std::string &a, const std::string &b) {

    std::string a1 = a;
    std::string b1 = b;
    while ((a1[0] == '0') && (a1.size() != 1)) a1.erase(0, 1);
    while((b1[0] == '0') && (b1.size() != 1)) b1.erase(0, 1);

    if (a1[0] == '-' && b1[0] != '-') return "-" + sum_strings(a1.substr(1), b1);
    if (a1[0] != '-' && b1[0] == '-') return sum_strings(a1, b1);
    if (a1[0] == '-' && b1[0] == '-'){
        std::string tmp = a1.substr(1);
        a1 = b1.substr(1);
        b1 = tmp;
    }

    int sizeA = a.size();
    int sizeB = b.size();
    std::string zeroes(abs(sizeA - sizeB), '0');
    int subTmp = 0;
    bool negativeFlag = false;
    bool borrow = 0;
    std::string result;

    if ((sizeA == 0) || ((a1 == "0") && (b1 != "0"))) return "-" + b;
    if ((sizeB == 0) || (b1 == "0")) return a;

    if ((sizeA > sizeB)&&(sizeB != 0)) {
        b1 = zeroes + b1;
    }
    if ((sizeA < sizeB)&&(sizeA != 0)) {
        std::swap(a1, b1);
        negativeFlag = true;
        b1 = zeroes + b1;
    }

    if ((sizeA == sizeB)&&(sizeA != 0)&&(a1 < b1)) {
        std::swap(a1, b1);
        negativeFlag = true;
    }

    for (int i = std::max(sizeA, sizeB) - 1; i >= 0; i--) {
        if (((a1[i] - '0') - borrow) < (b1[i] - '0')) {
            subTmp = 10 + ((a1[i] - '0') - borrow) - (b1[i] - '0');
            borrow = 1;
        }
        else {
            subTmp = ((a1[i] - '0') - borrow) -  (b1[i] - '0');
            borrow = 0;
        }
        result = char(subTmp + '0') + result;
    }

    while ((result[0] == '0') && (result.size() != 1)) result.erase(0, 1);

    ///if (borrow) std::cout << "!!!BORROW at the END of SUBTRACT!!!" << std::endl;
    if (negativeFlag) result = "-" + result;

return result;
}

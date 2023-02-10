#include "divide_strings.h"

int compare(const std::string &a, const std::string &b);
std::string subtract(const std::string &a, const std::string &b);

std::vector<std::string> divide_strings(const std::string &a, const std::string &b) {

std::string a1 = a, b1 = b;
std::string subStrA;
int quotient = 0;
std::string quotientStr ="";
bool flag0 = false;
bool flag1 = true;

    while ((a1[0] == '0') && (a1.size() != 1)) a1.erase(0, 1);
    while((b1[0] == '0') && (b1.size() != 1)) b1.erase(0, 1);

    int sizeA = a1.size() - 1;
    int sizeB = b1.size() - 1;

    if (b1 == "0") return std::vector<std::string> {"NAN", a1};
    else if (a1 == "0") return std::vector<std::string> {"0", "0"};
    else if (b1 == "1") return std::vector<std::string> {a1, "0"};
    else if (compare(a1,b1) == 0) return std::vector<std::string> {"1","0"};
    else if (compare(a1,b1) == -1) return std::vector<std::string> {"0", a1};
    else{

        int offset = sizeB + 1;
        int i = 0;
        subStrA = a1.substr(0, offset);

        if (compare(subStrA, b1) < 0){
            i++;
            subStrA += a1[i + offset - 1];
        }

        for ( ; i < sizeA - sizeB + 1; ) {
            quotient = 0;
            /// add new digits until subStrA >= b1
            while ((compare(subStrA, b1) < 0) && (i < sizeA - sizeB + 1)) {
                subStrA = subStrA + a1[i + offset - 1];
                /// add to the quotientStr additional 0
                if (compare(subStrA, b1) < 0){
                    quotientStr += "0";
                    i++;
                    flag0 = true;
                    continue;
                }
                else flag0 = false;
            }

            int quotientLast = quotient;
            /// subtract b1 from subStrA while subStrA >= b
            while (compare(subStrA, b1) >= 0){
                subStrA = subtract(subStrA, b1);
                quotient ++;
            }
                /// add 0 if there has been zero subtractions
                if ((quotient == quotientLast)&&(!flag0)){
                    quotientStr += "0";
                }

                if (flag0 == false){
                    quotientStr += std::to_string(quotient);
                i++;
                }
            }
    }

    while ((subStrA[0] == '0') && (subStrA.size() != 1)) subStrA.erase(0, 1);
    return std::vector<std::string> {quotientStr, subStrA};
}
///===================================================================
std::string subtract(const std::string &a, const std::string & b){

std::string a1 = a;
std::string b1 = b;
    while ((a1[0] == '0') && (a1.size() != 1)) a1.erase(0, 1);
    while((b1[0] == '0') && (b1.size() != 1)) b1.erase(0, 1);
int sizeA = a1.size();
int sizeB = b1.size();
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
//==============================================================
int compare(const std::string &a, const std::string &b){
///std::string subtract(std::string , std::string );
std::string tmp = subtract(a, b);

    switch (tmp[0]) {
    case '-':
        return -1;
        break;
    case '0':
        return 0;
        break;
    default:
        return 1;
    }
}

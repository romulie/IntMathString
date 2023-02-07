#include "sum_strings.h"

std::string sum_strings(const std::string &a, const std::string &b) {

    int sizeA = a.size(), sizeB = b.size();
    if (sizeA == 0 || a == "0") return b;
    if (sizeB == 0 || b == "0") return a;

    if (a[0] == '-' && b[0] != '-') return subtract_strings(b, a.substr(1));
    if (b[0] == '-' && a[0] != '-') return subtract_strings(a, b.substr(1));
    if (a[0] == '-' && b[0] == '-') return "-" + sum_strings(a.substr(1), b.substr(1));

    std::string a1, b1, result, zeroes(abs(sizeA - sizeB), '0');
    bool carry = 0;

    if (sizeA >= sizeB){//&&(sizeB != 0)
        b1 = zeroes + b;
        a1 = a;
    }
    if (sizeA < sizeB){//&&(sizeA != 0)
        a1 = zeroes + a;
        b1 = b;
    }

    for (int i = std::max(sizeA, sizeB)-1; i >= 0; i--){
        int sum = (a1[i] - '0') +  (b1[i] - '0') + carry;
        result = char(sum % 10+'0') + result;
        carry = sum / 10;
    }
    if (carry) result = '1' + result;

return result;
}


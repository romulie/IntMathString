#include "compare_MathStrings.h"
#include "subtract_strings.h"


int compare_MathStrings(const std::string& a, const std::string& b){

std::string tmp = subtract_strings(a, b);

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

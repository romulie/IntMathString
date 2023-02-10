#ifndef DIVIDE_STRINGS_H_INCLUDED
#define DIVIDE_STRINGS_H_INCLUDED

/// TODO:
/// divide_string uses its own functions subtract and compare which ARE DIFFERENT from  subtract_strings compare_MathStrings
/// due to the fact that the latter are using SIGNED operations
//#include "subtract_strings.h"
//#include "compare_MathStrings.h"
#include <string>
#include <vector>

std::vector<std::string> divide_strings(const std::string &a, const std::string &b);

#endif // DIVIDE_STRINGS_H_INCLUDED

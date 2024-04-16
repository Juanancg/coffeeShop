#ifndef COFFEESHOP_SRC_UTILS_STRINGUTILS_H
#define COFFEESHOP_SRC_UTILS_STRINGUTILS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

namespace utils
{

    void Tokenize(const std::string &line, const char separator, std::vector<std::string> &tokens);

}

#endif // COFFEESHOP_SRC_UTILS_STRINGUTILS_H
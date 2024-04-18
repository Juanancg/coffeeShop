#ifndef COFFEESHOP_SRC_UTILS_STRINGUTILS_H
#define COFFEESHOP_SRC_UTILS_STRINGUTILS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

namespace utils
{

    /**
     * @brief Tokenize a given string by a separator
     *
     * @param [in] str str to tokenize
     * @param [in] separator char separator
     * @param [out] tokens vector with the string tokens
     *
     */
    void Tokenize(const std::string &str, const char separator, std::vector<std::string> &tokens);

}

#endif // COFFEESHOP_SRC_UTILS_STRINGUTILS_H
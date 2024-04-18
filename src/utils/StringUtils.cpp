#include "StringUtils.h"

namespace utils
{

    void Tokenize(const std::string &str, const char separator, std::vector<std::string> &tokens)
    {
        tokens.clear();

        std::stringstream ss(str);

        std::vector<std::string> strTokens;
        std::string elem = "";

        while (std::getline(ss, elem, separator))
        {
            tokens.push_back(elem);
        }
    }

}

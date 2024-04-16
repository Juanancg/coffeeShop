#include "StringUtils.h"

namespace utils
{

    void Tokenize(const std::string &line, const char separator, std::vector<std::string> &tokens)
    {
        tokens.clear();

        std::stringstream ssLine(line);

        std::vector<std::string> lineTokens;
        std::string elem = "";
        while (std::getline(ssLine, elem, separator))
        {
            tokens.push_back(elem);
        }
    }

}

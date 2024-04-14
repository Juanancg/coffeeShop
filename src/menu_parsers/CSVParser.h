#ifndef COFFEESHOP_SRC_MENU_PARSER_CSVPARSER_H
#define COFFEESHOP_SRC_MENU_PARSER_CSVPARSER_H

#include "IMenuParser.h"

namespace menu
{
    // beverage,type,price,extras,rule
    const uint MAX_FIELDS = 5;
    const uint BEVERAGE_FIELD = 0;
    const uint BEV_TYPE_FIELD = 1;
    const uint BEV_PRICE_FIELD = 2;
    const uint EXTRAS_FIELD = 3;
    const uint RULE_FIELD = 4;

    class CSVParser : public IMenuParser
    {
    public:
        CSVParser();
        ~CSVParser();

        bool ParseMenu(const std::string &path);

        void ProcessMenuEntry(const std::vector<std::string> &lineTokens, stcBeverageMenuEntry &entry);

        void Tokenize(const std::string &line, const char separator, std::vector<std::string> &tokens);

        void SaveRawRules(const std::string &beverageName, const stcBeverageMenuEntry &entry);

    private:
    };

}

#endif // COFFEESHOP_SRC_MENU_PARSER_CSVPARSER_H
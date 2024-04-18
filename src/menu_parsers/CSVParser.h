#ifndef COFFEESHOP_SRC_MENU_PARSER_CSVPARSER_H
#define COFFEESHOP_SRC_MENU_PARSER_CSVPARSER_H

#include "IMenuParser.h"

#include "../utils/StringUtils.h"

namespace menu
{
    // beverage,type,price,extras,rule
    const uint MAX_FIELDS = 5;
    const uint BEVERAGE_FIELD = 0;
    const uint BEV_TYPE_FIELD = 1;
    const uint BEV_PRICE_FIELD = 2;
    const uint EXTRAS_FIELD = 3;
    const uint RULE_FIELD = 4;

    /**
     * @brief CSV parser of the menu
     */
    class CSVParser : public IMenuParser
    {
    public:
        CSVParser();
        ~CSVParser();

        /**
         * @brief Parse the csv file that cointains the menu
         *
         * @param [in] path Path to the csv file
         *
         * @return true if could open and read the file
         * @return false if couldnt open and read the file
         */
        bool ParseMenu(const std::string &path);

        /**
         * @brief Takes a line of the file tokenized and parse the line filling the fields of the Entry
         *
         * @param [in] lineTokens vector with the line tokenized
         * @param [out] entry struct with the fields filled by the info of the file
         *
         */
        void ProcessMenuEntry(const std::vector<std::string> &lineTokens, stcBeverageMenuEntry &entry);

        /**
         * @brief Saves the raw rules of the beverage
         *
         * @param [in] beverageName name of the type of beverage
         * @param [in] entry entry associated to the beverage with the raw rules inside
         *
         */
        void SaveRawRules(const std::string &beverageName, const stcBeverageMenuEntry &entry);

    private:
    };

}

#endif // COFFEESHOP_SRC_MENU_PARSER_CSVPARSER_H
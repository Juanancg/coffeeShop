#ifndef COFFEESHOP_SRC_MENU_PARSER_IMENUPARSER_H
#define COFFEESHOP_SRC_MENU_PARSER_IMENUPARSER_H

#include <vector>
#include <map>
#include <string>

namespace menu
{

    struct stcBeverageMenuEntry
    {
        std::string type = ""; // Name of the type, price
        double price = 0;
        std::vector<std::string> extras;
        std::vector<std::string> rules; // TODO REMOVE
    };

    // Defines the type that the UI needs to show all the data to the user
    typedef std::map<std::string, std::vector<menu::stcBeverageMenuEntry>> MenuUI;

    // Defines the type for manage the weird rules.
    typedef std::pair<std::string, std::string> BeverageVariety; // std::pair<MainBeverage, BeverageVariety>
    typedef std::map<BeverageVariety, std::vector<std::string>> RawRules;

    class IMenuParser
    {
    public:
        virtual ~IMenuParser() {}
        virtual bool ParseMenu(const std::string &path) = 0;
        virtual void SaveRawRules(const std::string &beverageName, const stcBeverageMenuEntry &entry) = 0;

        MenuUI GetMenuForUI() const { return menu_; }
        RawRules GetRawRules() const { return setRawRules_; }

    protected:
        MenuUI menu_;
        RawRules setRawRules_;
    };

}

#endif // COFFEESHOP_SRC_MENU_PARSER_IMENUPARSER_H
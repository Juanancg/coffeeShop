#ifndef COFFEESHOP_SRC_RULES_RULEMANAGER_H
#define COFFEESHOP_SRC_RULES_RULEMANAGER_H

#include <memory>

#include "../menu_parsers/IMenuParser.h"
#include "IRuleExtras.h"
#include "RuleFactory.h"

namespace rules
{

    /**
     * @brief Class that manage all the existing rules and to which beverage-variety applies
     */
    class RuleManager
    {
    public:
        RuleManager();
        ~RuleManager();

        /**
         * @brief Load the rules from the parser that are in a raw string and creates the classes associated to.
         *
         * @param [in] rawRules container with all the beverage-varieties and what rules applies to each one.
         *
         */
        void LoadRules(const menu::RawRules &rawRules);

        /**
         * @brief Check if the beverage passes all the defined rules
         *
         * @param [in] mainBeverage name of the main beverage
         * @param [in] variety name of the variety of the beverage
         * @param [in] extras Extras selected by the user
         *
         * @return true if passes all the checks
         * @return false if at least one of the checks doesnt pass
         */
        bool CheckBeverage(const std::string &mainBeverage, const std::string &variety, const std::vector<std::string> &extras);

    private:
        std::map<menu::BeverageVariety, std::vector<std::unique_ptr<IRuleExtras>>> allRules_;
    };
}

#endif // COFFEESHOP_SRC_RULES_RULEMANAGER_H
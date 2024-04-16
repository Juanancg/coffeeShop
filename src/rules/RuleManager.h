#ifndef COFFEESHOP_SRC_RULES_RULEMANAGER_H
#define COFFEESHOP_SRC_RULES_RULEMANAGER_H

#include "../menu_parsers/IMenuParser.h"

namespace rules
{

    class RuleManager
    {
    public:
        RuleManager();
        ~RuleManager();

        void LoadRules(const menu::RawRules &rawRules);

        bool CheckBeverage(const std::string &mainBeverage, const std::string &variety, const std::vector<std::string> &extras);

    private:
    };
}

#endif // COFFEESHOP_SRC_RULES_RULEMANAGER_H
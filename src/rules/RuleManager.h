#ifndef COFFEESHOP_SRC_RULES_RULEMANAGER_H
#define COFFEESHOP_SRC_RULES_RULEMANAGER_H

#include <memory>

#include "../menu_parsers/IMenuParser.h"
#include "IRuleExtras.h"
#include "RuleFactory.h"

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
        std::map<menu::BeverageVariety, std::vector<std::unique_ptr<IRuleExtras>>> allRules_;
        // TODO Check memory deletion
    };
}

#endif // COFFEESHOP_SRC_RULES_RULEMANAGER_H
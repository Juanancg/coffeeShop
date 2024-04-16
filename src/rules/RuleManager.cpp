#include "RuleManager.h"

namespace rules
{

    RuleManager::RuleManager()
    {
    }

    RuleManager::~RuleManager()
    {
    }

    void RuleManager::LoadRules(const menu::RawRules &rawRules)
    {
        for (const auto &[beverage, vecRules] : rawRules)
        {
            for (const std::string &rawRule : vecRules)
            {
                std::unique_ptr<IRuleExtras> ruleptr = RuleFactory::createRule(rawRule);

                allRules_[beverage].push_back(std::move(ruleptr));
            }
        }
    }

    bool RuleManager::CheckBeverage(const std::string &mainBeverage, const std::string &variety, const std::vector<std::string> &extras)
    {
        bool validBeverage = true;

        menu::BeverageVariety beverage = {mainBeverage, variety};

        if (allRules_.find(beverage) != allRules_.end())
        {
            for (const auto &rule : allRules_[beverage])
            {
                validBeverage &= rule->CheckRule(extras);
            }
        }

        return validBeverage;
    }

}
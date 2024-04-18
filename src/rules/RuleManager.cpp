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
                std::unique_ptr<IRuleExtras> ruleptr = RuleFactory::CreateRule(rawRule);

                allRules_[beverage].push_back(std::move(ruleptr));
            }
        }
    }

    bool RuleManager::CheckBeverage(const std::string &mainBeverage, const std::string &variety, const std::vector<std::string> &extras)
    {
        bool validBeverage = true;

        menu::BeverageVariety beverage = {mainBeverage, variety};

        // Find if the beverage-variety has rules loaded
        if (allRules_.find(beverage) != allRules_.end())
        {
            // Check all the rules associated to the beverage-variety
            for (const auto &rule : allRules_[beverage])
            {
                validBeverage &= rule->CheckRule(extras);
            }
        }

        return validBeverage;
    }

}
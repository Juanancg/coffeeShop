#ifndef COFFEESHOP_SRC_RULES_RULEFACTORY_H
#define COFFEESHOP_SRC_RULES_RULEFACTORY_H

#include <memory>
#include <vector>
#include <map>

#include "IRuleExtras.h"
#include "CannotHaveBoth.h"
#include "../utils/StringUtils.h"

namespace rules
{

    class RuleFactory
    {
    public:
        inline static const std::string RULE_CANNOT_BOTH = "cannot_have:both";

        enum class RuleType
        {
            CANNOT_BOTH,
            NONE
        };

        static std::unique_ptr<IRuleExtras> createRule(const std::string &rawRule)
        {

            RuleType ruleType = ParseRawRuleType(rawRule);

            switch (ruleType)
            {
            case RuleType::CANNOT_BOTH:
                return std::make_unique<CannotHaveBoth>(rawRule);
            // Add cases for additional parser types
            default:
                return nullptr;
            }
        }

        static RuleType ParseRawRuleType(const std::string &rawRule)
        {
            RuleType ret = RuleType::NONE;

            std::size_t pos = rawRule.find('(');
            std::vector<std::string> tokens;
            utils::Tokenize(rawRule, '(', tokens);

            if (0 < tokens.size())
            {
                if (ruleSet_.find(tokens[0]) != ruleSet_.end())
                {
                    ret = ruleSet_[tokens[0]];
                }
            }

            return ret;
        }

    private:
        inline static std::map<std::string, RuleType> ruleSet_ = {{RULE_CANNOT_BOTH, RuleType::CANNOT_BOTH}};
    };

}

#endif // COFFEESHOP_SRC_RULES_RULEFACTORY_H
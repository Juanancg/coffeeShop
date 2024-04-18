#ifndef COFFEESHOP_SRC_RULES_CANNOTHAVEBOTH_H
#define COFFEESHOP_SRC_RULES_CANNOTHAVEBOTH_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "IRuleExtras.h"
#include "../utils/StringUtils.h"

namespace rules
{

    /**
     * @brief Rule of having two extras at the same time
     */
    class CannotHaveBoth : public IRuleExtras
    {
    public:
        CannotHaveBoth(const std::string &rawRule) : IRuleExtras(rawRule)
        {
            ParseRule(rawRule);
            if (ruleExtras_.size() < 2)
            {
                std::cout << "ERROR: Rule with wrong format \"" << rawRule << "\" expected name:(ingredient1;ingredient2)" << std::endl;
                ruleExtras_.clear();
                // NOTE: If the rule is malformatted then the check rule is going to pass all the checks as correct. Ask client if this is the behaviour intended
            }
        }

        virtual ~CannotHaveBoth() {}

        /**
         * @brief Checks the current rule of having two extras at the same time.
         *
         * @param [in] extras vector of ingredients to be checked
         *
         * @return true If the list of extras is valid
         * @return false If both ingredients are in the list
         */
        bool CheckRule(const std::vector<std::string> &extras)
        {
            bool valid = true;

            // Search if all the extras that cannot be at the same time are present in the input vector
            for (const auto &ruleExtra : ruleExtras_)
            {
                if (std::find(extras.begin(), extras.end(), ruleExtra) != extras.end())
                {
                    valid = false;
                }
                else
                {
                    valid = true;
                    break;
                }
            }

            return valid;
        }

    private:
        void ParseRule(const std::string &rawRule)
        {
            // Parse the rule string and extract the extras
            // Expect cannot_have:both(milk;lemon)
            std::size_t pos = rawRule.find(':');
            // FUTURE: Here you do somehting with the both, maybe a future rule could be instead of both neither

            if (pos != std::string::npos && pos < rawRule.size() - 1)
            {
                std::string extrasStr = rawRule.substr(pos + 1);
                std::size_t leftParth = extrasStr.find('(');
                std::size_t rightParth = extrasStr.find(')');

                if (leftParth != std::string::npos && rightParth != std::string::npos && leftParth < rightParth)
                {
                    std::string extrasList = extrasStr.substr(leftParth + 1, rightParth - leftParth - 1);
                    std::size_t start = 0;
                    std::size_t end;
                    while ((end = extrasList.find(';', start)) != std::string::npos)
                    {
                        ruleExtras_.push_back(extrasList.substr(start, end - start));
                        start = end + 1;
                    }
                    std::string ingredient2 = extrasList.substr(start);
                    if (ingredient2 != "")
                    {
                        ruleExtras_.push_back(extrasList.substr(start));
                    }
                    else
                    {
                        // Delete the current extra save it because we want to pass the check if the rule is malformatted
                        ruleExtras_.clear();
                    }
                }
            }
        }

        std::vector<std::string> ruleExtras_;
    };

}

#endif // COFFEESHOP_SRC_RULES_CANNOTHAVEBOTH_H
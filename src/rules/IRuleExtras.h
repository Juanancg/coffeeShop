#ifndef COFFEESHOP_SRC_RULES_IRULEEXTRAS_H
#define COFFEESHOP_SRC_RULES_IRULEEXTRAS_H

#include <vector>
#include <string>

namespace rules
{
    /**
     * @brief  Interface that represent a specific rule
     */
    class IRuleExtras
    {
    public:
        IRuleExtras(const std::string &rawRule) : rawRule_(rawRule){};
        virtual ~IRuleExtras() {}

        virtual bool CheckRule(const std::vector<std::string> &extras) = 0;

    private:
        std::string rawRule_ = "";
    };

}

#endif // COFFEESHOP_SRC_RULES_IRULEEXTRAS_H
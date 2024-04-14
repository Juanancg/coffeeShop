#ifndef RULEMANAGER_H
#define RULEMANAGER_H

#include "../menu_parsers/IMenuParser.h"

namespace rules
{

    class RuleManager
    {
    public:
        RuleManager();
        ~RuleManager();

        void LoadRules(const menu::RawRules &rawRules);

        bool CheckBeverage();

    private:
    };
}

#endif // RULEMANAGER_H
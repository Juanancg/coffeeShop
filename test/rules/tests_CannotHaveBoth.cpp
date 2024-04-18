#include "tests_CannotHaveBoth.h"

TEST_F(tests_CannotHaveBoth, CheckRuleValidExtras)
{
    std::string rawRule = "cannot_have:both(milk;lemon)";
    rules::CannotHaveBoth rule(rawRule);

    std::vector<std::string> extras = {"milk", "sugar"};

    EXPECT_TRUE(rule.CheckRule(extras));
}

TEST_F(tests_CannotHaveBoth, CheckRuleInvalidExtras)
{
    std::string rawRule = "cannot_have:both(milk;lemon)";
    rules::CannotHaveBoth rule(rawRule);

    std::vector<std::string> extras = {"milk", "sugar", "lemon"};

    EXPECT_FALSE(rule.CheckRule(extras));
}

TEST_F(tests_CannotHaveBoth, CheckRuleSignleValidExtra)
{
    std::string rawRule = "cannot_have:both(milk;lemon)";
    rules::CannotHaveBoth rule(rawRule);

    std::vector<std::string> extras = {"milk"};

    EXPECT_TRUE(rule.CheckRule(extras));
}

TEST_F(tests_CannotHaveBoth, RawRuleMissformat)
{
    std::string rawRule = "cannot_have:both(milk;)";
    rules::CannotHaveBoth rule(rawRule);

    std::vector<std::string> extras = {"milk"};

    EXPECT_TRUE(rule.CheckRule(extras));
}
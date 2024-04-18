#include "tests_StringUtils.h"

TEST_F(tests_StringUtils, Tokenize)
{

    std::string line = "tea,green tea,1.75,sugar-milk-soy milk-honey-lemon,cannot_have:both(milk-lemon)";
    char separator = ',';
    std::vector<std::string> tokens;

    utils::Tokenize(line, separator, tokens);

    ASSERT_EQ(tokens.size(), 5);
    EXPECT_EQ(tokens[0], "tea");
    EXPECT_EQ(tokens[1], "green tea");
    EXPECT_EQ(tokens[2], "1.75");
    EXPECT_EQ(tokens[3], "sugar-milk-soy milk-honey-lemon");
    EXPECT_EQ(tokens[4], "cannot_have:both(milk-lemon)");
}

TEST_F(tests_StringUtils, TokenizeWeirdCase)
{

    std::string line = ",,,,,";
    char separator = ',';
    std::vector<std::string> tokens;

    utils::Tokenize(line, separator, tokens);

    ASSERT_EQ(tokens.size(), 5);
    EXPECT_EQ(tokens[0], "");
    EXPECT_EQ(tokens[1], "");
    EXPECT_EQ(tokens[2], "");
    EXPECT_EQ(tokens[3], "");
    EXPECT_EQ(tokens[4], "");
}

TEST_F(tests_StringUtils, TokenizeSeparatorBeginning)
{

    std::string line = ",hello world !";
    char separator = ',';
    std::vector<std::string> tokens;

    utils::Tokenize(line, separator, tokens);

    ASSERT_EQ(tokens.size(), 2);
    ASSERT_EQ(tokens[0], "");
    ASSERT_EQ(tokens[1], "hello world !");
}
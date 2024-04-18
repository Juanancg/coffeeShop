#include "tests_CSVParser.h"

TEST_F(tests_CSVParser, ParseMenuEmptyFile)
{
    menu::CSVParser parser;

    std::string path = "";

    EXPECT_FALSE(parser.ParseMenu(path));
}

TEST_F(tests_CSVParser, ParseMenu)
{
    menu::CSVParser parser;

    std::string path = "/opt/coffeeShop/src/menu.csv";

    EXPECT_TRUE(parser.ParseMenu(path));

    menu::MenuUI menuUi = parser.GetMenuForUI();
    menu::RawRules rules = parser.GetRawRules();

    ASSERT_EQ(menuUi.size(), 3);

    // Check coffee types
    auto coffeeIt = menuUi.find("coffee");
    ASSERT_TRUE(coffeeIt != menuUi.end());
    EXPECT_EQ(coffeeIt->second.size(), 3);
    EXPECT_EQ(coffeeIt->second[0].type, "espresso");
    EXPECT_EQ(coffeeIt->second[0].price, 2.00);
    EXPECT_EQ(coffeeIt->second[0].extras.size(), 3);
    EXPECT_EQ(coffeeIt->second[0].extras[0], "sugar");
    EXPECT_EQ(coffeeIt->second[0].extras[1], "milk");
    EXPECT_EQ(coffeeIt->second[0].extras[2], "cream");
    EXPECT_EQ(coffeeIt->second[0].rules.size(), 0);

    EXPECT_EQ(coffeeIt->second[1].type, "latte");
    EXPECT_EQ(coffeeIt->second[1].price, 3.00);
    EXPECT_EQ(coffeeIt->second[1].extras.size(), 3);
    EXPECT_EQ(coffeeIt->second[1].extras[0], "sugar");
    EXPECT_EQ(coffeeIt->second[1].extras[1], "milk");
    EXPECT_EQ(coffeeIt->second[1].extras[2], "cream");
    EXPECT_EQ(coffeeIt->second[1].rules.size(), 0);

    EXPECT_EQ(coffeeIt->second[2].type, "decaf");
    EXPECT_EQ(coffeeIt->second[2].price, 2.50);
    EXPECT_EQ(coffeeIt->second[2].extras.size(), 3);
    EXPECT_EQ(coffeeIt->second[2].extras[0], "sugar");
    EXPECT_EQ(coffeeIt->second[2].extras[1], "milk");
    EXPECT_EQ(coffeeIt->second[2].extras[2], "cream");
    EXPECT_EQ(coffeeIt->second[2].rules.size(), 0);

    // Check tea types
    auto teaIt = menuUi.find("tea");
    ASSERT_TRUE(teaIt != menuUi.end());
    ASSERT_EQ(teaIt->second.size(), 2);
    EXPECT_EQ(teaIt->second[0].type, "black tea");
    EXPECT_EQ(teaIt->second[0].price, 1.50);
    EXPECT_EQ(teaIt->second[0].extras.size(), 5);
    EXPECT_EQ(teaIt->second[0].extras[0], "sugar");
    EXPECT_EQ(teaIt->second[0].extras[1], "milk");
    EXPECT_EQ(teaIt->second[0].extras[2], "soymilk");
    EXPECT_EQ(teaIt->second[0].extras[3], "honey");
    EXPECT_EQ(teaIt->second[0].extras[4], "lemon");
    ASSERT_EQ(teaIt->second[0].rules.size(), 1);
    EXPECT_EQ(teaIt->second[0].rules[0], "cannot_have:both(milk;lemon)");

    EXPECT_EQ(teaIt->second[1].type, "green tea");
    EXPECT_EQ(teaIt->second[1].price, 1.75);
    EXPECT_EQ(teaIt->second[1].extras.size(), 5);
    EXPECT_EQ(teaIt->second[1].extras[0], "sugar");
    EXPECT_EQ(teaIt->second[1].extras[1], "milk");
    EXPECT_EQ(teaIt->second[1].extras[2], "soymilk");
    EXPECT_EQ(teaIt->second[1].extras[3], "honey");
    EXPECT_EQ(teaIt->second[1].extras[4], "lemon");
    ASSERT_EQ(teaIt->second[1].rules.size(), 1);
    EXPECT_EQ(teaIt->second[1].rules[0], "cannot_have:both(milk;lemon)");

    // Check cocoa types
    auto cocoaIt = menuUi.find("cocoa");
    ASSERT_TRUE(cocoaIt != menuUi.end());
    ASSERT_EQ(cocoaIt->second.size(), 3);
    EXPECT_EQ(cocoaIt->second[0].type, "milk");
    EXPECT_EQ(cocoaIt->second[0].price, 3.50);
    EXPECT_EQ(cocoaIt->second[0].extras.size(), 1);
    EXPECT_EQ(cocoaIt->second[0].extras[0], "sugar");
    EXPECT_EQ(cocoaIt->second[0].rules.size(), 0);

    EXPECT_EQ(cocoaIt->second[1].type, "soymilk");
    EXPECT_EQ(cocoaIt->second[1].price, 4.00);
    EXPECT_EQ(cocoaIt->second[1].extras.size(), 1);
    EXPECT_EQ(cocoaIt->second[1].extras[0], "sugar");
    EXPECT_EQ(cocoaIt->second[1].rules.size(), 0);

    EXPECT_EQ(cocoaIt->second[2].type, "water");
    EXPECT_EQ(cocoaIt->second[2].price, 3.00);
    EXPECT_EQ(cocoaIt->second[2].extras.size(), 1);
    EXPECT_EQ(cocoaIt->second[2].extras[0], "sugar");
    EXPECT_EQ(cocoaIt->second[2].rules.size(), 0);

    // TODO CHECK RAWRULES and Remove
}

TEST_F(tests_CSVParser, ProcessMenuEntry)
{
    menu::CSVParser parser;

    std::vector<std::string> lineTokens;
    lineTokens.push_back("tea");
    lineTokens.push_back("green tea");
    lineTokens.push_back("1.75");
    lineTokens.push_back("sugar-milk-soy milk-honey-lemon");
    lineTokens.push_back("cannot_have:both(milk;lemon)");

    menu::stcBeverageMenuEntry entry;
    parser.ProcessMenuEntry(lineTokens, entry);

    EXPECT_EQ(entry.type, "green tea");
    EXPECT_EQ(entry.price, 1.75);

    ASSERT_EQ(entry.extras.size(), 5);

    EXPECT_EQ(entry.extras[1], "milk");
    EXPECT_EQ(entry.extras[2], "soy milk");
    EXPECT_EQ(entry.extras[3], "honey");
    EXPECT_EQ(entry.extras[4], "lemon");
    ASSERT_EQ(entry.rules.size(), 1);
    EXPECT_EQ(entry.rules[0], "cannot_have:both(milk;lemon)");
}

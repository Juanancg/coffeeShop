#include <iostream>
#include <memory>

#include "ui/ShellUI.h"
#include "menu_parsers/MenuParserFactory.h" // TODO RENAME MENU_PARSERS folder
#include "rules/RuleManager.h"
#include "ui/ShellUI.h"

int main(int argc, char **argv)
{
    menu::MenuParserFactory::ParserType sourceType = menu::MenuParserFactory::ParserType::CSV;
    std::unique_ptr<menu::IMenuParser> parser = menu::MenuParserFactory::createParser(sourceType);

    std::string path = "/opt/coffeeShop/src/menu.csv";
    bool ret = parser->ParseMenu(path);

    menu::MenuUI menuParsed = parser->GetMenuForUI();
    menu::RawRules rawRules = parser->GetRawRules();
    rules::RuleManager ruleMgr;
    ShellUI ui;

    ui.Start(menuParsed);
    ruleMgr.LoadRules(rawRules);

    std::unique_ptr<Beverage> beveragePtr = ui.createBeverage();

    if (ruleMgr.CheckBeverage(beveragePtr->GetBeverageMain(), beveragePtr->GetBeverageVariety(), beveragePtr->GetExtras()))
    {
        std::cout << "Valid Beverage!!!" << std::endl;
    }
    else
    {
        std::cout << "Invalid Beverage :( " << std::endl;
    }

    // TODO If yes -> OrderManager CreateOrder

    return 0;
}
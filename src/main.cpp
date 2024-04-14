#include <iostream>
#include <memory>

#include "ui/ShellUI.h"
#include "menu_parsers/MenuParserFactory.h"
#include "ui/ShellUI.h"

int main(int argc, char **argv)
{
    menu::MenuParserFactory::ParserType sourceType = menu::MenuParserFactory::ParserType::CSV;
    std::unique_ptr<menu::IMenuParser> parser = menu::MenuParserFactory::createParser(sourceType);

    std::string path = "/opt/coffeeShop/src/menu.csv";
    bool ret = parser->ParseMenu(path);

    menu::MenuUI menuParsed = parser->GetMenuForUI();

    ShellUI ui;

    ui.Start(menuParsed);
    std::unique_ptr<Beverage> beveragePtr = ui.createBeverage();

    // TODO Check with rule manager if it fulfil the conditions

    // TODO If yes -> OrderManager CreateOrder

    return 0;
}
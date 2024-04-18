#include <iostream>
#include <memory>

#include "ui/ShellUI.h"
#include "menu_parsers/MenuParserFactory.h" // TODO RENAME MENU_PARSERS folder
#include "rules/RuleManager.h"
#include "ui/ShellUI.h"
#include "OrderManager.h"

int main(int argc, char **argv)
{
    menu::MenuParserFactory::ParserType sourceType = menu::MenuParserFactory::ParserType::CSV;
    std::unique_ptr<menu::IMenuParser> parser = menu::MenuParserFactory::CreateParser(sourceType);

    std::string path = "/opt/coffeeShop/src/menu.csv";
    bool ret = parser->ParseMenu(path);

    if (ret)
    {
        ShellUI ui;
        rules::RuleManager ruleMgr;
        OrderManager orderMgr;

        menu::MenuUI menuParsed = parser->GetMenuForUI();
        menu::RawRules rawRules = parser->GetRawRules();

        ui.Start(menuParsed);
        ruleMgr.LoadRules(rawRules);

        while (true)
        {
            std::cout << "------------------------------------------------------------------" << std::endl;
            OptionsMainMenu choice = ui.MainMenu();

            switch (choice)
            {
            case ORDER_BEVERAGE:
            {
                std::unique_ptr<Beverage> beveragePtr = ui.createBeverage();

                if (beveragePtr != nullptr)
                {
                    std::cout << "Checking Beverage..." << std::endl;

                    if (ruleMgr.CheckBeverage(beveragePtr->GetBeverageMain(), beveragePtr->GetBeverageVariety(), beveragePtr->GetExtras()))
                    {
                        std::cout << "Valid Beverage!!!" << std::endl;

                        orderMgr.RegisterOrder(std::move(beveragePtr));
                    }
                    else
                    {
                        std::cout << "Invalid Beverage ingredients, try again " << std::endl;
                    }
                }
                break;
            }
            case PRINT_ORDERS:
            {
                orderMgr.PrintOrders();
                break;
            }
            case REMOVE_ORDER:
            {
                /* code */
                int idxOrder = ui.GetIdxOrderToRm();
                orderMgr.CancelOrder(idxOrder);
                break;
            }
            case EXIT:
                return 0;

            default:
                std::cout << "Invalid Option, try again" << std::endl;
                break;
            }

            // std::unique_ptr<Beverage> beveragePtr = ui.createBeverage();

            // if (beveragePtr != nullptr)
            // {
            //     std::cout << "Checking Beverage..." << std::endl;

            //     if (ruleMgr.CheckBeverage(beveragePtr->GetBeverageMain(), beveragePtr->GetBeverageVariety(), beveragePtr->GetExtras()))
            //     {
            //         std::cout << "Valid Beverage!!!" << std::endl;

            //         orderMgr.RegisterOrder(std::move(beveragePtr));
            //     }
            //     else
            //     {
            //         std::cout << "Invalid Beverage ingredients, try again " << std::endl;
            //     }
            // }
        }
    }
    else
    {
        std::cout << "Failure while loading the menu!" << std::endl;
    }

    return 0;
}
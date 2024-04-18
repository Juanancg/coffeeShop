#ifndef COFFEESHOP_SRC_UIIFACE_H
#define COFFEESHOP_SRC_UIIFACE_H

#include <memory>
#include <iostream>
#include <vector>

#include "../menu_parsers/IMenuParser.h"
#include "../menu_parsers/CSVParser.h"
#include "../types/Beverage.h"

enum OptionsMainMenu
{
    NONE = 0,
    ORDER_BEVERAGE = 1,
    PRINT_ORDERS = 2,
    REMOVE_ORDER = 3,
    EXIT = 4,
    MAX_OPTION = 5,
};

class UIiface
{
public:
    UIiface() = default;
    virtual ~UIiface() {}

    virtual OptionsMainMenu MainMenu() = 0;
    virtual void Start(const menu::MenuUI &menu) = 0;
    virtual std::unique_ptr<Beverage> createBeverage() = 0;
    virtual bool GetUserChoice(const int minNum, const int maxSize, int &choice) = 0;
    virtual int GetIdxOrderToRm() const = 0;

protected:
    std::unique_ptr<menu::IMenuParser> parser_ = nullptr;

    menu::MenuUI menu_;
};

#endif // COFFEESHOP_SRC_UIIFACE_H
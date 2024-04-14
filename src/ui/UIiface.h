#ifndef COFFEESHOP_SRC_UIIFACE_H
#define COFFEESHOP_SRC_UIIFACE_H

#include <memory>
#include <iostream>
#include <vector>

#include "../menu_parsers/IMenuParser.h"
#include "../menu_parsers/CSVParser.h"
#include "../types/Beverage.h"

class UIiface
{
public:
    UIiface() = default;
    virtual ~UIiface() {}

    virtual void Start(menu::MenuUI &menu) = 0;
    virtual std::unique_ptr<Beverage> createBeverage() = 0;
    virtual bool GetUserChoice(const int minNum, const int maxSize, int &choice) = 0;

protected:
    std::unique_ptr<menu::IMenuParser> parser_ = nullptr;

    menu::MenuUI menu_;
};

#endif // COFFEESHOP_SRC_UIIFACE_H
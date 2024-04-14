#ifndef COFFEESHOP_SRC_UI_SHELLUI_H
#define COFFEESHOP_SRC_UI_SHELLUI_H

#include <memory>
#include <iostream>
#include <vector>

#include "UIiface.h"

class ShellUI : public UIiface
{
public:
    ShellUI();
    ~ShellUI();

    void Start(menu::MenuUI &menu);
    std::unique_ptr<Beverage> createBeverage();
    bool GetUserChoice(const int minNum, const int maxSize, int &choice);

private:
    bool SelectMainBeverage(std::string &beverageName, std::vector<menu::stcBeverageMenuEntry> &beverageMenuEntry);

    void SelectExtras(const std::vector<std::string> &availableExtras, std::vector<std::string> &selectedExtras);
};

#endif // COFFEESHOP_SRC_UI_SHELLUI_H
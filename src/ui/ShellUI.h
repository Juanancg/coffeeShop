#ifndef COFFEESHOP_SRC_UI_SHELLUI_H
#define COFFEESHOP_SRC_UI_SHELLUI_H

#include <memory>
#include <iostream>
#include <vector>

#include "UIiface.h"

/**
 * @brief Class that represents the ui of a shell
 */
class ShellUI : public UIiface
{
public:
    ShellUI();
    ~ShellUI();

    /**
     * @brief Shows the main menu in which the user could select an option
     *
     * @return OptionsMainMenu option selected by the user
     */
    OptionsMainMenu MainMenu();

    /**
     * @brief Loads the menu to show
     *
     * @param [in] menu
     *
     */
    void Start(const menu::MenuUI &menu);

    /**
     * @brief Shows the user the menu and let him to create a Beverage
     *
     * @return std::unique_ptr<Beverage>
     */
    std::unique_ptr<Beverage> createBeverage();

    /**
     * @brief Method to manage the user input
     *
     * @param [in] minNum Min num valid that could enter the user
     * @param [in] maxSize Max num valid that could enter the user
     * @param [out] choice User input
     *
     * @return true If its a valid choice
     * @return false If its not a valid choice
     */
    bool GetUserChoice(const int minNum, const int maxSize, int &choice);

    /**
     * @brief Ask the user about which order index he wants to delete
     *
     * @return int idx to be removed
     */
    int GetIdxOrderToRm() const;

private:
    /**
     * @brief Shows the main beverages and ask the user about the main type of beverage that he wants to order. He has to select the number of the beverage
     *
     * @param [out] beverageName Name of the beverage selected
     * @param [out] beverageMenuEntry Struct that has the menu entry of the beverage
     *
     * @return true If its a valid choice
     * @return false If its not a valid choice
     */
    bool SelectMainBeverage(std::string &beverageName, std::vector<menu::stcBeverageMenuEntry> &beverageMenuEntry);

    /**
     * @brief Shows the varieties of a Beverage and ask the user about which option. He has to select the number of the variety
     *
     * @param [in] beverageVarietyEntries Entry with all the varieties
     * @param [out] beverageEntrySelected Entry of the beverage selected
     *
     * @return true If its a valid choice
     * @return false If its not a valid choice
     */
    bool SelectBeverageVariety(const std::vector<menu::stcBeverageMenuEntry> &beverageVarietyEntries, menu::stcBeverageMenuEntry &beverageEntrySelected);

    /**
     * @brief Shows the extras and ask the user if he wants any extras. He has to select the number of the extra, and could include multiple times the same extra. Is a loop until the user selects that he doenst want more extras
     *
     * @param [in] availableExtras List of the available extras
     * @param [out] selectedExtras Extras selected
     *
     */
    void SelectExtras(const std::vector<std::string> &availableExtras, std::vector<std::string> &selectedExtras);
};

#endif // COFFEESHOP_SRC_UI_SHELLUI_H
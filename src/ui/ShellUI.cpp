#include "ShellUI.h"

ShellUI::ShellUI()
{
    parser_ = std::make_unique<menu::CSVParser>();
}

ShellUI::~ShellUI()
{
}

void ShellUI::Start(const menu::MenuUI &menu)
{
    menu_ = menu;
}

OptionsMainMenu ShellUI::MainMenu()
{
    while (true)
    {
        int choice = 0;

        std::cout << "Select an option:" << std::endl;
        std::cout << "1) Order Beverage" << std::endl;
        std::cout << "2) Print Orders" << std::endl;
        std::cout << "3) Remove Order" << std::endl;
        std::cout << "4) Exit" << std::endl;

        std::cin >> choice;

        // Validate the users choice
        if (OptionsMainMenu::NONE < choice && choice < OptionsMainMenu::MAX_OPTION)
        {
            return static_cast<OptionsMainMenu>(choice);
        }
        else
        {
            std::cout << "Invalid choice, try again" << std::endl;
        }
    }
}

std::unique_ptr<Beverage> ShellUI::createBeverage()
{
    std::string mainBeverage = "";
    std::vector<menu::stcBeverageMenuEntry> beverageMenuEntry;

    if (SelectMainBeverage(mainBeverage, beverageMenuEntry))
    {
        menu::stcBeverageMenuEntry selectedEntry;

        if (SelectBeverageVariety(beverageMenuEntry, selectedEntry))
        {

            // Ask user to choose extras
            std::vector<std::string> selectedExtras;
            SelectExtras(selectedEntry.extras, selectedExtras);

            std::unique_ptr<Beverage> beverage = std::make_unique<Beverage>(mainBeverage, selectedEntry.type, selectedEntry.price, selectedExtras);

            return beverage;
        }
    }

    return nullptr;
}

bool ShellUI::SelectBeverageVariety(const std::vector<menu::stcBeverageMenuEntry> &beverageVarietyEntries, menu::stcBeverageMenuEntry &beverageEntrySelected)
{
    // Display beverage options (varieties) for the current type
    for (size_t i = 0; i < beverageVarietyEntries.size(); ++i)
    {
        auto &entry = beverageVarietyEntries[i];
        std::cout << i + 1 << ". " << entry.type << " - Price: " << entry.price << "€" << std::endl;
    }

    int varietyChoice = 0;
    if (GetUserChoice(1, beverageVarietyEntries.size(), varietyChoice))
    {
        beverageEntrySelected = beverageVarietyEntries[varietyChoice - 1];
        return true;
    }

    return false;
}

bool ShellUI::GetUserChoice(const int minNum, const int maxSize, int &choice)
{
    std::cout << "Enter the number associated with what you want to order: ";
    std::cin >> choice;

    // Validate the user's choice
    if (choice < minNum || choice > maxSize)
    {
        std::cout << "Invalid choice. Please try again." << std::endl;
        return false;
    }

    return true;
}

int ShellUI::GetIdxOrderToRm() const
{
    int idx = -1;
    std::cout << "Enter the number of the order that you want to delete: ";
    std::cin >> idx;

    return idx;
}

bool ShellUI::SelectMainBeverage(std::string &beverageName, std::vector<menu::stcBeverageMenuEntry> &beverageMenuEntry)
{
    size_t ii = 0;
    for (auto &[type, entries] : menu_)
    {
        ii++;
        std::cout << ii << ") Beverage Type: " << type << std::endl;
    }

    int choice = 0;

    if (GetUserChoice(1, menu_.size(), choice))
    {
        auto it = menu_.begin();
        std::advance(it, choice - 1);
        beverageName = it->first;
        beverageMenuEntry = it->second;

        return true;
    }

    return false;
}

void ShellUI::SelectExtras(const std::vector<std::string> &availableExtras, std::vector<std::string> &selectedExtras)
{
    // Show extras available
    std::cout << "Extras available:" << std::endl;
    for (size_t i = 0; i < availableExtras.size(); ++i)
    {
        std::cout << i + 1 << ") " << availableExtras[i] << std::endl;
    }

    while (true)
    {
        int extraChoice = 0;
        std::cout << "Choose an extra (0 to finish): ";
        if (!GetUserChoice(0, availableExtras.size(), extraChoice))
        {
            // Not break if the user has insert an invalid number, just try again
            continue;
        }

        if (extraChoice == 0)
        {
            // User finished choosing extras
            break;
        }

        if ((extraChoice - 1) < static_cast<int>(availableExtras.size()))
        {
            // Add the selected extra to the vector
            selectedExtras.push_back(availableExtras[extraChoice - 1]);
        }
    }
}
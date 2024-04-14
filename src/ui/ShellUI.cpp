#include "ShellUI.h"

ShellUI::ShellUI()
{
    parser_ = std::make_unique<menu::CSVParser>();
}

ShellUI::~ShellUI()
{
}

void ShellUI::Start(menu::MenuUI &menu)
{
    menu_ = menu;
}

std::unique_ptr<Beverage> ShellUI::createBeverage()
{
    std::string mainBeverage = "";
    std::vector<menu::stcBeverageMenuEntry> beverageMenuEntry;

    if (SelectMainBeverage(mainBeverage, beverageMenuEntry))
    {

        // Display beverage options (varieties) for the current type
        for (size_t i = 0; i < beverageMenuEntry.size(); ++i)
        {
            auto &entry = beverageMenuEntry[i];
            std::cout << i + 1 << ". " << entry.type << " - Price: " << entry.price << "€" << std::endl;
        }

        int varietyChoice = 0;

        if (GetUserChoice(1, beverageMenuEntry.size(), varietyChoice))
        {

            // Get the selected beverage entry
            auto &selectedEntry = beverageMenuEntry[varietyChoice - 1];

            // Ask user to choose extras
            std::vector<std::string> selectedExtras;
            SelectExtras(selectedEntry.extras, selectedExtras);

            std::unique_ptr<Beverage> beverage = std::make_unique<Beverage>(mainBeverage, selectedEntry.type, selectedEntry.price, selectedExtras);

            return beverage;
        }
    }

    return nullptr;
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
            break;
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
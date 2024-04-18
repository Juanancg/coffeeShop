#ifndef COFFEESHOP_SRC_MENU_PARSER_MENUPARSERFACTORY_H
#define COFFEESHOP_SRC_MENU_PARSER_MENUPARSERFACTORY_H

#include <memory>

#include "IMenuParser.h"
#include "CSVParser.h"

namespace menu
{

    class MenuParserFactory
    {
    public:
        enum class ParserType
        {
            CSV,
            NONE
        };

        static std::unique_ptr<IMenuParser> CreateParser(ParserType type)
        {
            switch (type)
            {
            case ParserType::CSV:
                return std::make_unique<CSVParser>();
            // Add cases for additional parser types
            default:
                return nullptr;
            }
        }
    };

}

#endif // COFFEESHOP_SRC_MENU_PARSER_MENUPARSERFACTORY_H
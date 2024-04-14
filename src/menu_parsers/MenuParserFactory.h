#ifndef MENUPARSERFACTORY_H
#define MENUPARSERFACTORY_H

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

        static std::unique_ptr<IMenuParser> createParser(ParserType type)
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

#endif // MENUPARSERFACTORY_H
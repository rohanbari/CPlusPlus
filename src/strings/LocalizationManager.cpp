/**
 * @file LocalizationManager.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Localization is important for large projects that are likely to be
 * used by foreign people. This program illustrates the implementation of a
 * flexible localization management system.
 * @version 0.1
 * @date 2022-11-19
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <array>
#include <cinttypes>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief Localization manager class.
 *
 */
namespace Localization {
using StringId = int32_t;
enum class Language {
    en_US,
    en_IN,
    total
};

const StringId STRING_COLOR { 0 };

class Manager {
    using Strings = unordered_map<StringId, string>;
    using StringPack = array<Strings, static_cast<size_t>(Language::total)>;

    StringPack stringPack;
    Strings* currentStringPack { nullptr };

    uint32_t languageIndex;

public:
    Manager()
    {
        // en-US Localization
        static const uint32_t _EN_US { static_cast<uint32_t>(Language::en_US) };
        stringPack[_EN_US][STRING_COLOR] = "COLOR"s;

        // en-IN Localization
        static const uint32_t _EN_IN { static_cast<uint32_t>(Language::en_IN) };
        stringPack[_EN_IN][STRING_COLOR] = "COLOUR"s;

        // By default, en_US localization is set.
        setLanguage(Language::en_US);
    }

    /**
     * @brief Refers current string pack to the passed language's string pack.
     *
     * @param language Language to be used
     */
    void setLanguage(Language language)
    {
        currentStringPack = &(stringPack[static_cast<uint32_t>(language)]);
    }

    /**
     * @brief Get the String object.
     *
     * @param stringId String ID
     * @return string  The localized string
     */
    string getString(StringId stringId) const
    {
        stringstream result;
        result << stringId << "-x-";

        string finalString { result.str() };
        auto it = currentStringPack->find(stringId);

        if (it != currentStringPack->end())
            finalString = it->second;

        return finalString;
    }
};
}

int main(void)
{
    Localization::Manager manager;

    string color { manager.getString(Localization::STRING_COLOR) };
    cout << "en_US localization: " << color.c_str() << endl;

    manager.setLanguage(Localization::Language::en_IN);

    color = manager.getString(Localization::STRING_COLOR);
    cout << "en_IN localization: " << color.c_str() << endl;

    cout << "Default local: " << manager.getString(1) << endl;

    return EXIT_SUCCESS;
}
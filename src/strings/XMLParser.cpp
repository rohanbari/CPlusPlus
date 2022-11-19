/**
 * @file XMLParser.cpp
 * @author rohanbari (rohanbari4@gmail.com)
 * @brief Parsing XML files with RapidXML library.
 * @version 0.1
 * @date 2022-11-19
 *
 * Copyright (c) 2022 rohanbari
 *
 */

#include <iostream>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

using namespace std;
using namespace rapidxml;

int main(void)
{
    file<> xmlFile("sample.xml");

    xml_document<> document;
    document.parse<0>(xmlFile.data());

    xml_node<>* catalog { document.first_node("catalog") };

    if (catalog != nullptr) {
        xml_node<>* book { catalog->first_node("book") };

        while (book != nullptr) {
            xml_node<>* author { book->first_node("author") };
            cout << author->value() << endl;

            book = book->next_sibling("book");
        }
    }

    return EXIT_SUCCESS;
}
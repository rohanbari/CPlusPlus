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

size_t strlen(const char* str)
{
    const char* beg = str;
    while (*str)
        str++;
    return static_cast<size_t>(str - beg);
}

/**
 * @brief Validate and warn if the node is corrupted.
 *
 * @param param Node to be validated
 */
void validateNode(xml_node<char>* param)
{
    if (param == nullptr)
        cerr << "error: Data invalid." << endl;

    if (strlen(param->value()) == 0)
        cerr << "<data not present>" << endl;
}

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
            validateNode(author);
            cout << "Author: " << author->value() << endl;

            xml_node<>* title { book->first_node("title") };
            validateNode(title);
            cout << "Title: " << title->value() << endl;

            xml_node<>* genre { book->first_node("genre") };
            validateNode(genre);
            cout << "Genre: " << genre->value() << endl;

            xml_node<>* price { book->first_node("price") };
            validateNode(price);
            cout << "Price: " << price->value() << endl;

            xml_node<>* publish_date { book->first_node("publish_date") };
            validateNode(publish_date);
            cout << "Publish date: " << publish_date->value() << endl;

            xml_node<>* description { book->first_node("description") };
            validateNode(description);
            cout << "Description: " << description->value() << endl << endl;

            // These points to the next sibling of the DOM tree.
            book = book->next_sibling("book");
            title = title->next_sibling("title");
            genre = genre->next_sibling("genre");
            price = price->next_sibling("price");
            publish_date = publish_date->next_sibling("publish_date");
            description = description->next_sibling("description");
        }
    }

    return EXIT_SUCCESS;
}
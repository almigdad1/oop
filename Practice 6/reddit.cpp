
#include "reddit.hpp"

#include <iostream>
#include <string>


printData::printData(std::string Title, std::string Author, bool TorF)
{
    title = Title;
    author = Author;
    trueOrFalse = TorF;
}


void RedInput::print()
{
    for(long i = data.size() - 1; i > 0; --i)
    {
        printData d = data.at(i);
        std::cout << "Title:  " << d.title << std::endl << "Author: " << d.author << std::endl;
    }
}


std::string RedInput::remove(std::string s)
{
    s.pop_back();
    s.erase(s.begin());

    return s;
}

RedInput::RedInput(json::Value* v)
{
    int i = 0;

    while(v->direct("\"data\"")->direct("\"children\"")->index(i) != nullptr)
    {
        std::string title = remove(v->direct("\"data\"")->direct("\"children\"")->index(i)->direct("\"data\"")->direct("\"title\"")->getString());
        std::string author = remove(v->direct("\"data\"")->direct("\"children\"")->index(i)->direct("\"data\"")->direct("\"author\"")->getString());
        bool t = v->direct("\"data\"")->direct("\"children\"")->index(i)->direct("\"data\"")->direct("\"stickied\"")->getBool();

        printData displayData(title, author, t);
        data.insert(data.begin(), displayData);

        ++i;
    }
}

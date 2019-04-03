#pragma once

#include "json.hpp"

#include <iostream>
#include <string>
#include <vector>

//Struct to print data tags
struct printData
{
    bool trueOrFalse = false;
    std::string title = "", author = "";

    printData(std::string Title, std::string Author, bool TorF);
};

//Struct to remove unnecessary components and display titles/authors
struct RedInput
{
    std::string remove(std::string);
    std::vector<printData> data;

    void print();
    RedInput(json::Value *v);
};

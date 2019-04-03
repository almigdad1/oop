// Practice 6
//
#include "json.hpp"
#include "reddit.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <typeinfo>

int main()
{
    std::istreambuf_iterator<char> first(std::cin);
    std::istreambuf_iterator<char> last;
    std::string s(first, last);

    json::Value* val = json::parse(s);

    RedInput reddit(val);
    reddit.print();

    return 0;
}

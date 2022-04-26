#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> stringSplit(const std::string& str, const std::string& delim)
{
    std::vector<std::string> splitted_string;
    std::size_t current, prev = 0;
    current = str.find(delim);
    while(current != std::string::npos)
    {
        splitted_string.push_back(str.substr(prev, current-prev));
        prev = current + delim.size();
        current = str.find(delim, prev);
    }
    splitted_string.push_back(str.substr(prev, current-prev));
    return splitted_string;
}


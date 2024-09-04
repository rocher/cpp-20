import hello;

#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

int main()
{
    std::cout << hello::say_hello();
    std::cout << boost::gregorian::day_clock::universal_day();
    std::cout << std::endl;
}

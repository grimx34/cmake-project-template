//
// Created by Jamahl Watson on 31/10/2018.
//

#include <iostream>

#include "CppLib/lib_header.h"

int main()
{
    std::cout << "Hello World!" << " I am using build version " << cpplib::buildNumber();
    return 0;
}
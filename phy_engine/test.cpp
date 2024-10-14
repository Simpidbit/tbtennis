//#include "math.h"
#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Test构造" << std::endl;
    }
    ~Test() {
        std::cout << "Test析构" << std::endl;
    }
};

int main()
{
    {
        Test t;
    }

    std::cout << "Hello World" << std::endl;


    return 0;
}

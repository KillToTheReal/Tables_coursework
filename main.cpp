#include <iostream>
#include "table.h"
#include "unit_test.cpp"
using namespace std;

int main()
{
    Table<float> test(4,5);

    unit_test();
    
    return 0;
}

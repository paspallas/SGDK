#include <genesis.h>
#include "CTest.hpp"
#include <vector>
#include <list>

using namespace std;

#define ARRAY_SIZE 3

int main()
{
    vector<u16> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);

    list<u16> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    char cadena[20];
    for (size_t i = 0; i < v.size(); ++i)
    {
        sprintf(cadena, "Vector: %d", v[i]);
        VDP_drawText(cadena, 0, (u8)i);
    }

    u8 i = 0;
    for (auto it : l)
    {
        sprintf(cadena, "list: %d", it);
        VDP_drawText(cadena, 0, i + 6);
        ++i;
    }

    CTest staticClass(5);
    staticClass.print("static class says hello", 5, 10);

    CTest *dynamicClass = new CTest(5);
    dynamicClass->print("dynamic class says hello", 5, 12);

    CTest * classArray[ARRAY_SIZE];

    for (u8 i = 0; i < ARRAY_SIZE; ++i)
    {
        classArray[i] = new CTest(i);
    }

    char string[36];
    for (u8 i = 0; i < ARRAY_SIZE; ++i)
    {
        sprintf(string, "Class array element %d says hello", classArray[i]->getID());
        classArray[i]->print(string, 1, 16 + i);
    }

    while (TRUE)
    {
        VDP_waitVSync();
    }

    delete(dynamicClass);

    return 0;
}

#pragma once

#include <genesis.h>

class CTest
{
public:
    CTest(u8 id);
    ~CTest();

    void print(const char* string, const u8 x, const u8 y);
    u8 getID();

private:
    u8 m_id;

};

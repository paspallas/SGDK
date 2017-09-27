#include "CTest.hpp"

CTest::CTest(u8 id)
{
    m_id = id;
}

CTest::~CTest()
{

}

void CTest::print(const char* string, const u8 x, const u8 y)
{
    VDP_drawText(string, x, y);
}

u8 CTest::getID()
{
    return m_id;
}

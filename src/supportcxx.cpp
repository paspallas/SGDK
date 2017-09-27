/*
 *  c++ support functionality
 */

#include <genesis.h>

void* operator new(u32 size)
{
    return MEM_alloc(size);
}

void* operator new[](u32 size)
{
    return MEM_alloc(size);
}

void operator delete(void* ptr)
{
    MEM_free(ptr);
}

void operator delete[](void* ptr)
{
    MEM_free(ptr);
}

void operator delete(void* ptr, u32 t)
{
    MEM_free(ptr);
}


extern "C"
{
    extern void (*__CTOR_LIST__)() ;
    extern void (*__DTOR_LIST__)() ;

    void callConstructors()
    {
        void (**constructor)() = &__CTOR_LIST__ ;
        u16 total = *(u16 *)constructor ;
        constructor++ ;
        while (total) {
            (*constructor)() ;
            total-- ;
            constructor++ ;
        }
    }

    void callDestructors()
    {
        void (**deconstructor)() = &__DTOR_LIST__ ;
        u16 total = *(u16 *)deconstructor ;
        deconstructor++ ;
        while (total) {
            (*deconstructor)() ;
            total-- ;
            deconstructor++ ;
        }
    }

    void __cxa_pure_virtual () {}
    void * __dso_handle = 0;
    void  __cxa_atexit() {}
}

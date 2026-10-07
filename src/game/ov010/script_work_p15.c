/*
 * file:     script_work_p15.c
 * unit:     yes
 * function: func_02159058, func_0215909C
 * address:  0x02159058
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159030  0x02159030  thumb  ov010
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   func_02030734 0x02030734 arm
 *   d_0217289C 0x0217289C data a1
 */
#include "../../matched/include/Obj18755.h"

typedef unsigned short u16;

typedef unsigned char u8;

extern int func_02159030(int a0, int a1, int a2);
extern void *func_02158FD0(void *, unsigned int);
extern void func_02082A60(const void *, void *, unsigned int);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
int func_02159058(int a, int b, int c, int d, u16 e);
void *func_0215909C(u8 *a);
extern const char d_0217289C[];


int func_02159058(int a, int b, int c, int d, u16 e)
{
    func_02159030(a, 0x8000, b);
    func_02159030(a, 0x8001, c);
    func_02159030(a, 0x8002, d);
    return func_02159030(a, 0x8003, e);
}

void *func_0215909C(u8 *a)
{
    void *p = func_02030734(((struct Obj18755 *)a)->fC, 0x7e, 1, d_0217289C, 0x21b);
    func_02082A60(func_02158FD0(a, 0x8020), p, 0x7e);
    return p;
}

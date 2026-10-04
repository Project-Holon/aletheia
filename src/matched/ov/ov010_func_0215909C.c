/*
 * function: func_0215909C
 * address: 0x0215909C
 * packet: pkt_ov010_0215909C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   func_02030734 0x02030734 arm
 *   d_0217289C 0x0217289C data a1
 */
#include "../include/Obj18755.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern void *func_02158FD0(void *, unsigned int);
extern void func_02082A60(const void *, void *, unsigned int);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern const char d_0217289C[];
void *func_0215909C(u8 *a)
{
    void *p = func_02030734(((struct Obj18755 *)a)->fC, 0x7e, 1, d_0217289C, 0x21b);
    func_02082A60(func_02158FD0(a, 0x8020), p, 0x7e);
    return p;
}

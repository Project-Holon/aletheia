/*
 * function: func_021B66E0
 * address:  0x021B66E0
 * packet:   pkt_ov101_021B66E0
 * region:   ov101
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_021B64F0  0x021B64F0  thumb  ov101
 */
#include "../include/Obj04420.h"

extern void MI_CpuFill8(int, int, int);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
typedef unsigned int   u32;
extern void func_021B64F0(u32 p, u32 a, u32 b, u32 c, u32 d);

void func_021B66E0(int a, int b, int c)
{
    int r7;

    MI_CpuFill8(a, 0, 0x34);
    r7 = 0x57b;
    ((struct Obj04420 *)a)->f0 = b;
    ((struct Obj04420 *)a)->f28 = (int)func_02030734(c, 0x2c, 0, (const char *)0x021B7524, r7);
    MI_CpuFill8(((struct Obj04420 *)a)->f28, 0, 0x2c);
    ((struct Obj04420 *)a)->f2C = (int)func_02030734(c, 0x2c, 0, (const char *)0x021B7524, r7 + 2);
    MI_CpuFill8(((struct Obj04420 *)a)->f2C, 0, 0x2c);
    ((struct Obj04420 *)a)->f30 = (int)func_02030734(c, 0x2c, 0, (const char *)0x021B7524, r7 + 4);
    MI_CpuFill8(((struct Obj04420 *)a)->f30, 0, 0x2c);
    func_021B64F0(b, 0x1000, 0x021B741C, 4, a);
}

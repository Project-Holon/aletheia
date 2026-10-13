/*
 * function: func_0217422C
 * address: 0x0217422C
 * packet: pkt_ov012_0217422C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   gUnionMainEmptyString 0x02175628 data ov012 a1
 */
#include "../include/Obj00610.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u8 gUnionMainEmptyString[];
void func_0217422C(u8 *p, int a, int b)
{
    if (((struct Obj00610 *)p)->f354C != 0 || ((struct Obj00610 *)p)->f3548 != 0)
        func_02034714((const char *)gUnionMainEmptyString, 0, (const char *)gUnionMainEmptyString);
    ((struct Obj00610 *)p)->f354C = a;
    ((struct Obj00610 *)p)->f3550 = b;
    p[0x3554] = 0;
}

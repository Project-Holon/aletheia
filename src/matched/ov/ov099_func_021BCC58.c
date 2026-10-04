/*
 * function: func_021BCC58
 * address:  0x021BCC58
 * packet:   pkt_ov099_021BCC58
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3A30  0x021C3A30  data  a4
 *
 * Levers: the loop bound is unsigned (`i < 8u`, gives blo with a signed
 * counter for the signed %4 and /4); the masked value is a local declared
 * before the counter (mask in r3, counter in r4).
 */
#include "../include/Obj07944.h"
#include "../include/Obj22032.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern const u32 d_021C3A30[];

void func_021BCC58(char *p, u32 x)
{
    u32 m;
    int i;

    ((struct Obj22032 *)(*(char * *)&((struct Obj07944 *)p)->f248))->f48 = (x & 0x80000000) != 0;
    m = x & 0x0fffffff;
    for (i = 0; i < 8u; i++) {
        if (m == d_021C3A30[i]) {
            ((struct Obj07944 *)p)->f134C = i % 4;
            ((struct Obj07944 *)p)->f134E = i / 4;
        }
    }
}

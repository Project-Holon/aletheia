/*
 * function: func_0218A0F4
 * address:  0x0218A0F4
 * packet:   pkt_ov096_0218A0F4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020113B0  0x020113B0  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);

int func_0218A0F4(u8 *a, int op, int x, int y, int z)
{
    int r = 0;
    switch (op) {
    case 0:
        if (x < y)
            r = 1;
        break;
    case 1:
        if (x > y)
            r = 1;
        break;
    case 2:
        if (x == y)
            r = 1;
        break;
    case 3:
        if (x != y)
            r = 1;
        break;
    case 4:
        if (x & y)
            r = 1;
        break;
    case 5:
        if (!(x & y))
            r = 1;
        break;
    case 6:
        if (x <= y)
            r = 1;
        break;
    case 7:
        if (x >= y)
            r = 1;
        break;
    }
    if (r == 1)
        func_020113B0((struct Cur *)a, (u32)(*(u8 * *)&((struct Obj00005 *)a)->f14 + z));
    return r;
}

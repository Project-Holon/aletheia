/*
 * file:     unit_021E9A78.c
 * function: func_021E9A78
 * address:  0x021E9A78
 * packet:   pkt_ov093_021E9A78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689CB18  0x0689CB18  thumb
 *   func_0689CB2C  0x0689CB2C  thumb
 *   func_021E9984  0x021E9984  thumb  ov093
 */
#include "../../matched/include/Obj00056.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);
extern u32 func_0689CB18(u8 *p);
extern u8 func_0689CB2C(u8 *p, u8 i);

void func_021E9A78(char *p, const u8 *q, int x, int y, u8 *r)
{
    u32 i;
    u32 n;

    if (x < 0) x = 0;
    func_021E9984((u8 *)p, (u8 *)(p + 0x10c), q[0xb], x, y);
    n = func_0689CB18(r);
    for (i = 0; i < n; i++) {
        if (i >= 2) break;
        p[i + 0x129] = func_0689CB2C(r, i);
    }
    for (; i < 2; i++)
        p[i + 0x129] = 6;
    r[8] = 1;
    *(u8 * *)&((struct Obj00056 *)p)->f15C = r;
    p[0x174] = 0;
}

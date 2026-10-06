/*
 * function: func_0202A19C
 * address:  0x0202A19C
 * packet:   pkt_0202A19C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202A20C  0x0202A20C  thumb
 *   func_0202A21C  0x0202A21C  thumb
 */
#include "../include/Obj15810.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_0202A20C(u8 *p, u32 key, u32 v2, u32 v3);
extern int func_0202A21C(int a0, int a1);

int func_0202A19C(u32 a, u32 *p, u32 c, u32 d, u16 e)
{
    int i = func_0202A20C((u8 *)p, c, d, e);
    u8 *r = (u8 *)func_0202A21C((int)p, *(u16 *)((u8 *)*p + i * 8 + 6));

    if (((struct Obj15810 *)r)->f7 == 2) {
        return 1;
    }
    return 0;
}

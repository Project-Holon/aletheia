/*
 * function: func_021BF41C
 * address:  0x021BF41C
 * packet:   pkt_021BF41C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases the sixth 0x14-byte element handle at +0x1C and the two at +0xA0 and +0xA4.
 */
#include "../include/Obj12120.h"


struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);

void func_021BF41C(int unused, char *q)
{
    unsigned char i;

    for (i = 0; i < 6; i++)
        func_0204B3B4((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)));
    func_0204A8D4(((struct Obj12120 *)q)->fA0);
    func_0204AFD8(((struct Obj12120 *)q)->fA4);
}


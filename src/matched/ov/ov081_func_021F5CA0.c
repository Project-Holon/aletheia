/*
 * function: func_021F5CA0
 * address:  0x021F5CA0
 * packet:   pkt_ov081_021F5CA0
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07714.h"
#include "../include/Obj09917.h"

typedef unsigned char u8;
typedef unsigned short u16;

void func_021F5CA0(u8 *w)
{
    int i;
    int *c = (int *)(w + 0x3000);
    u8 *t = w + 0x300C;

    for (i = 0; i < ((struct Obj07714 *)t)->f182; i++) {
        u8 *e = w + *(u16 *)(t + i * 2 + 0xC0) * 64;

        if (((struct Obj09917 *)e)->f34 == 0) {
            ((struct Obj09917 *)e)->f34 = 1;
            c[0]++;
            ((struct Obj09917 *)e)->f24 = 0x1000;
            *(u16 *)(t + i * 2) = *(u16 *)(t + i * 2 + 0xC0);
        }
    }
    ((struct Obj07714 *)t)->f180 = ((struct Obj07714 *)t)->f182;
    ((struct Obj07714 *)t)->f182 = 0;
}

/*
 * function: func_021F5AE4
 * address:  0x021F5AE4
 * packet:   pkt_ov079_021F5AE4
 * region:   ov079
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13219.h"

typedef unsigned char u8;
typedef unsigned short u16;

void func_021F5AE4(u8 *w)
{
    int *c = (int *)(w + 0x3000);
    int n = ((struct Obj13219 *)w)->f3008 * ((struct Obj13219 *)w)->f300A;

    if (c[0] < n) {
        if (c[1] == 0) {
            *(int *)(w + c[0] * 64 + 0x34) = 1;
            c[0]++;
            c[1] = 0;
        } else {
            c[1]--;
        }
    }
}

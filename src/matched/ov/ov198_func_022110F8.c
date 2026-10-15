/*
 * function: B_PLIST_MAIN_PushSelectionPair
 * address: 0x022110F8
 * packet: pkt_ov198_022110F8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj10854.h"
typedef unsigned char u8;
typedef unsigned short u16;

void B_PLIST_MAIN_PushSelectionPair(u8 *p, int a, int b)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        u8 *q = p + i * 4;
        if (((struct Obj10854 *)q)->f249C == 0xff) {
            ((struct Obj10854 *)q)->f249C = a;
            ((struct Obj10854 *)q)->f249E = b;
            return;
        }
    }
}

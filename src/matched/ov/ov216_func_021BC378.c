/*
 * function: BEACON_DETAIL_GRA_FreeBackground
 * address:  0x021BC378
 * packet:   pkt_021BC378
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25770.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BEACON_DETAIL_GRA_FreeBackground(char *p)
{
    func_020307B0(((struct Obj25770 *)p)->f120);
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned short *)0x04000050 = 0;
}

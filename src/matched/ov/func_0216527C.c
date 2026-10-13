/*
 * function: func_0216527C
 * address:  0x0216527C
 * packet:   pkt_0216527C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:   wild=4
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 *
 * symbols:
 *   GAME_BEACON_SetDetailsBattleBigFour   0x02027430  thumb
 */
#include "../include/Obj05720.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GAME_BEACON_SetDetailsBattleBigFour(void *, unsigned);

void func_0216527C(void *a0, unsigned a1)
{
    ((struct Obj05720 *)a0)->f30 = 0xA;
    ((struct Obj05720 *)a0)->f34 = a1;
    GAME_BEACON_SetDetailsBattleBigFour(a0, a1);
}


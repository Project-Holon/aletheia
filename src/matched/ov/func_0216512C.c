/*
 * function: func_0216512C
 * address:  0x0216512C
 * packet:   pkt_0216512C
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
 *   GAME_BEACON_SetDetailsBattleSpecialPoke   0x020273DC  thumb
 */
#include "../include/Obj05717.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GAME_BEACON_SetDetailsBattleSpecialPoke(void *, unsigned);

void func_0216512C(void *a0, unsigned a1)
{
    ((struct Obj05717 *)a0)->f30 = 0x4;
    ((struct Obj05717 *)a0)->f32 = a1;
    GAME_BEACON_SetDetailsBattleSpecialPoke(a0, a1);
}


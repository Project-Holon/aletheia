/*
 * function: func_0216520C
 * address:  0x0216520C
 * packet:   pkt_0216520C
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
 *   GAME_BEACON_SetDetailsBattleLeader   0x02027414  thumb
 */
#include "../include/Obj05719.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GAME_BEACON_SetDetailsBattleLeader(void *, unsigned);

void func_0216520C(void *a0, unsigned a1)
{
    ((struct Obj05719 *)a0)->f30 = 0x8;
    ((struct Obj05719 *)a0)->f34 = a1;
    GAME_BEACON_SetDetailsBattleLeader(a0, a1);
}


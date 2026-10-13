/*
 * function: GAME_BEACON_SEARCH_SetInfoBattleTrainerStart
 * address:  0x0216519C
 * packet:   pkt_0216519C
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
 *   GAME_BEACON_SetDetailsBattleTrainer   0x020273F8  thumb
 */
#include "../include/Obj05718.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GAME_BEACON_SetDetailsBattleTrainer(void *, unsigned);

void GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(void *a0, unsigned a1)
{
    ((struct Obj05718 *)a0)->f30 = 0x6;
    ((struct Obj05718 *)a0)->f34 = a1;
    GAME_BEACON_SetDetailsBattleTrainer(a0, a1);
}


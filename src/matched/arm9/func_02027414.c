/*
 * function: GAME_BEACON_SetDetailsBattleLeader
 * address:  0x02027414
 * packet:   pkt_02027414
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 *
 * symbols:
 *   GAME_BEACON_SetDetailsBattleLeader  0x02027414  thumb
 */
#include "../include/Obj05719.h"

void GAME_BEACON_SetDetailsBattleLeader(char *p, unsigned short v)
{
    ((struct Obj05719 *)p)->f48 = (((struct Obj05719 *)p)->f48 & ~0xff) | 3;
    ((struct Obj05719 *)p)->f4E = v;
}

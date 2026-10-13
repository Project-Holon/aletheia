/*
 * function: GAME_BEACON_SetDetailsBattleWildPoke
 * address:  0x020273C4
 * packet:   pkt_020273C4
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
 *   GAME_BEACON_SetDetailsBattleWildPoke  0x020273C4  thumb
 */
#include "../include/Obj15763.h"

typedef struct { unsigned short lo : 8; unsigned short hi : 8; } F;

void GAME_BEACON_SetDetailsBattleWildPoke(char *p, unsigned short v)
{
    ((F *)(p + 0x48))->lo = 0;
    ((struct Obj15763 *)p)->f4E = v;
}

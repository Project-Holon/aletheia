/*
 * function: GAME_DATA_GetMysteryRecvFlagA
 * address:  0x020127E0
 * packet:   pkt_020127E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MUSICAL_SHOT_GetFromSave  0x0200A864  thumb
 *   MUSICAL_SHOT_GetTitle  0x0200A890  thumb
 */
#include "../include/Obj15627.h"

int GAME_DATA_GetMysteryRecvFlagA(int a0){ int t0, t1; t0 = MUSICAL_SHOT_GetFromSave((int)((struct Obj15627 *)((char *)(a0)))->f0); t1 = MUSICAL_SHOT_GetTitle((int)t0); return t1; }

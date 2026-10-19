/*
 * function: GAME_DATA_GetMusicalShotExtraData
 * address:  0x020127F0
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
 *   MUSICAL_SHOT_GetExtraData  0x0200A898  thumb
 */
#include "../include/Obj15628.h"

int GAME_DATA_GetMusicalShotExtraData(int a0){ int t0, t1; t0 = MUSICAL_SHOT_GetFromSave((int)((struct Obj15628 *)((char *)(a0)))->f0); t1 = MUSICAL_SHOT_GetExtraData((int)t0); return t1; }

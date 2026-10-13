/*
 * unit:     no
 * function: CONFIG_GetBattleFlag
 * address:  0x02008448
 * packet:   pkt_020082EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj15574.h"

unsigned int CONFIG_GetBattleFlag(int a0){ return ((unsigned int)((((struct Obj15574 *)((char *)(a0)))->f0 << 0x15)) >> 0x1f); }

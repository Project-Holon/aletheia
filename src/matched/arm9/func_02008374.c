/*
 * unit:     no
 * function: CONFIG_GetTextSpeed
 * address:  0x02008374
 * packet:   pkt_020082EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15570.h"

unsigned int CONFIG_GetTextSpeed(int a0){ return ((unsigned int)((((struct Obj15570 *)((char *)(a0)))->f0 << 0x1c)) >> 0x1c); }

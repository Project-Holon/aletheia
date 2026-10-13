/*
 * unit:     no
 * function: CONFIG_GetSoundMode
 * address:  0x02008390
 * packet:   pkt_02008314
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj15571.h"

unsigned int CONFIG_GetSoundMode(char *a0){ return (unsigned int)(((struct Obj15571 *)a0)->f0 << 0x1a) >> 0x1e; }

/*
 * function: GAME_BEACON_SEARCH_SetStartDelay
 * address:  0x02164FC4
 * packet:   pkt_02164FC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj18988.h"

typedef unsigned int u32;

void GAME_BEACON_SEARCH_SetStartDelay(char *p)
{
    ((struct Obj18988 *)p)->fC = 0x708;
}

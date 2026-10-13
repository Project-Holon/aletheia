/*
 * function: GAMESYSTEM_SetAlwaysNetFlag
 * address:  0x02012158
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02012BC8
 *
 * symbols:
 *   GAME_DATA_SetConfigFlag  0x02012BC8  thumb
 */
#include "../include/Obj15624.h"

extern void GAME_DATA_SetConfigFlag(unsigned char *p, int on);
void GAMESYSTEM_SetAlwaysNetFlag(char *p, unsigned int v)
{
    GAME_DATA_SetConfigFlag((unsigned char *)((struct Obj15624 *)p)->f1C, v);
}

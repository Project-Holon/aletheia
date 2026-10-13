/*
 * function: EL_SCOREBOARD_GetFadeOutDuration
 * address: 0x02187D54
 * packet: pkt_ov020_02187D54
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EL_SCOREBOARD_GetMode 0x02187D20 thumb ov020
 */
#include "../include/Obj12551.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 EL_SCOREBOARD_GetMode(char *);
int EL_SCOREBOARD_GetFadeOutDuration(char *p)
{
    if (EL_SCOREBOARD_GetMode(p) == 1) return 60;
    if (((struct Obj12551 *)p)->f15 == ((struct Obj12551 *)p)->f14) return 20;
    return 10;
}

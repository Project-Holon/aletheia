/*
 * function: EL_SCOREBOARD_GetHoldDuration
 * address: 0x02187D74
 * packet: pkt_ov020_02187D74
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EL_SCOREBOARD_GetMode 0x02187D20 thumb ov020
 */
#include "../include/Obj12552.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 EL_SCOREBOARD_GetMode(char *);
int EL_SCOREBOARD_GetHoldDuration(char *p)
{
    if (EL_SCOREBOARD_GetMode(p) == 1) return 120;
    if (((struct Obj12552 *)p)->f15 == ((struct Obj12552 *)p)->f14) return 60;
    return 30;
}

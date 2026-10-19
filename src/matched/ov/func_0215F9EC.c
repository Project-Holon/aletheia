/*
 * function: EVENT_GAMECLEAR_SetGatePoints
 * address:  0x0215F9EC
 * packet:   pkt_0215F9EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_SetGatePoints  0x0200C3B8  thumb
 */
#include "../include/Obj17707.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *GAME_DATA_GetMiscSave(int *p);
extern int MISC_SetGatePoints();

int EVENT_GAMECLEAR_SetGatePoints(int a0)
{
    int a1;
    void *p;

a0 = ((struct Obj17707 *)a0)->f4;
    p = GAME_DATA_GetMiscSave((int *)a0);
loc_0215F9F4:
a1 = 0x5a;
a1 = a1 << 4;
    a0 = MISC_SetGatePoints(p, a1);
loc_0215F9FC:
    return a0;}

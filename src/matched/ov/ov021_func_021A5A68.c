/*
 * function: FIELD_PLAYER_NOGRID_CheckAction
 * address:  0x021A5A68
 * packet:   pkt_ov021_021A5A68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckActionWalk  0x021A5C3C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckActionSlow  0x021A6014  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckActionRail  0x021A64B4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04234.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern int FIELD_PLAYER_NOGRID_CheckActionWalk(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern int FIELD_PLAYER_NOGRID_CheckActionSlow(int *a, int b, int c, int d, int e);
extern int FIELD_PLAYER_NOGRID_CheckActionRail(int *a, int b, int c, int d, int e);

int FIELD_PLAYER_NOGRID_CheckAction(u8 *p, u32 a, u32 b, u32 c, u32 d)
{
    int r;

    switch (FIELD_PLAYER_CORE_GetFormCode((u8 *)(*(u32 *)&((struct Obj04234 *)p)->f14))) {
    case 0:
        r = FIELD_PLAYER_NOGRID_CheckActionWalk(p, b, c, (u16)a, d);
        break;
    case 1:
        r = FIELD_PLAYER_NOGRID_CheckActionSlow((int *)p, b, c, (u16)a, d);
        break;
    case 2:
    case 3:
        r = FIELD_PLAYER_NOGRID_CheckActionRail((int *)p, b, c, (u16)a, d);
        break;
    }
    return r;
}

/*
 * function: FIELD_PLAYER_NOGRID_StartAction
 * address:  0x021A5AD4
 * packet:   pkt_ov021_021A5AD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartActionWalk  0x021A5BC0  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartActionSlow  0x021A5F98  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartActionRail  0x021A635C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01119.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern void FIELD_PLAYER_NOGRID_StartActionWalk(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void FIELD_PLAYER_NOGRID_StartActionSlow(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f);
extern void FIELD_PLAYER_NOGRID_StartActionRail(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);

void FIELD_PLAYER_NOGRID_StartAction(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    switch (FIELD_PLAYER_CORE_GetFormCode((u8 *)(*(u32 *)&((struct Obj01119 *)p)->f14))) {
    case 0:
        FIELD_PLAYER_NOGRID_StartActionWalk(p, a, c, d, (u16)b, e);
        break;
    case 1:
        FIELD_PLAYER_NOGRID_StartActionSlow((int *)p, a, c, d, (u16)b, e);
        break;
    case 2:
    case 3:
        FIELD_PLAYER_NOGRID_StartActionRail(p, a, c, d, (u16)b, e);
        break;
    }
}

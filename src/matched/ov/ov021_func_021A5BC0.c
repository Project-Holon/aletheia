/*
 * function: FIELD_PLAYER_NOGRID_StartActionWalk
 * address:  0x021A5BC0
 * packet:   pkt_ov021_021A5BC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_StartWalkNone  0x021A5EA0  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartWalkStand  0x021A5EA4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartWalkStep  0x021A5EDC  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartWalkTurn  0x021A5F14  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartWalkBlocked  0x021A5F38  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartWalkLedgeJump  0x021A5F74  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01119.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_StartWalkNone(void *p, void *a, int b, int c, int d, int e);
extern void FIELD_PLAYER_NOGRID_StartWalkStand(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void FIELD_PLAYER_NOGRID_StartWalkStep(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void FIELD_PLAYER_NOGRID_StartWalkTurn(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void FIELD_PLAYER_NOGRID_StartWalkBlocked(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void FIELD_PLAYER_NOGRID_StartWalkLedgeJump(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);

void FIELD_PLAYER_NOGRID_StartActionWalk(u8 *p, u32 k, u32 b, u32 c, u32 d, u32 e)
{
    void *a = ((struct Obj01119 *)p)->f1C;

    switch (k) {
    case 0:
        FIELD_PLAYER_NOGRID_StartWalkNone(p, a, b, c, d, e);
        break;
    case 1:
        FIELD_PLAYER_NOGRID_StartWalkStand(p, a, b, c, d, e);
        break;
    case 2:
        FIELD_PLAYER_NOGRID_StartWalkStep(p, a, b, c, d, e);
        break;
    case 3:
        FIELD_PLAYER_NOGRID_StartWalkTurn(p, a, b, c, d, e);
        break;
    case 4:
        FIELD_PLAYER_NOGRID_StartWalkBlocked(p, a, b, c, d, e);
        break;
    case 5:
        FIELD_PLAYER_NOGRID_StartWalkLedgeJump(p, a, b, c, d, e);
        break;
    }
}

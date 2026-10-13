/*
 * function: FIELD_PLAYER_NOGRID_CheckActionWalk
 * address:  0x021A5C3C
 * packet:   pkt_ov021_021A5C3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_CheckWalkFromStand  0x021A5CA4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckWalkStep  0x021A5D04  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckWalkFromTurn  0x021A5DD8  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckWalkFromBlocked  0x021A5E28  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04234.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern int FIELD_PLAYER_NOGRID_CheckWalkFromStand(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern int FIELD_PLAYER_NOGRID_CheckWalkStep(void *a, void *b, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_CheckWalkFromTurn(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern int FIELD_PLAYER_NOGRID_CheckWalkFromBlocked(void *a, void *b, int c, int d, int e, int f);

int FIELD_PLAYER_NOGRID_CheckActionWalk(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    int sw = ((struct Obj04234 *)p)->f0;
    int r = 0;
    void *a = ((struct Obj04234 *)p)->f1C;

    switch (sw) {
    case 0:
        r = FIELD_PLAYER_NOGRID_CheckWalkFromStand(p, a, b, c, d, e);
        break;
    case 1:
        r = FIELD_PLAYER_NOGRID_CheckWalkStep(p, a, b, c, d, e);
        break;
    case 2:
        r = FIELD_PLAYER_NOGRID_CheckWalkFromTurn(p, a, b, c, d, e);
        break;
    case 3:
        r = FIELD_PLAYER_NOGRID_CheckWalkFromBlocked(p, a, b, c, d, e);
        break;
    }
    return r;
}

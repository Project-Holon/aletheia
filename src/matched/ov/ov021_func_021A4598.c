/*
 * function: FIELD_PLAYER_GRID_GetWalkResultOnFoot
 * address:  0x021A4598
 * packet:   pkt_ov021_021A4598
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of ov021_func_021A4B98 with an extra tile-class check (ids
 * classed 0..3 by MAP_ATTR_IsLedgeNorth/164/170/17C) that returns 5.
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStandResultOnFoot  0x021A4544  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStepHitFlags  0x021A5264  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsLedgeNorth  0x021AB158  thumb  ov021
 *   MAP_ATTR_IsLedgeSouth  0x021AB164  thumb  ov021
 *   MAP_ATTR_IsLedgeWest  0x021AB170  thumb  ov021
 *   MAP_ATTR_IsLedgeEast  0x021AB17C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetStandResultOnFoot(u8 *p, u32 r, u8 *q);
extern int FIELD_PLAYER_GRID_GetStepHitFlags(u8 *a, void *b, u32 c, int *d);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int MAP_ATTR_IsLedgeNorth(u16);
extern int MAP_ATTR_IsLedgeSouth(u16);
extern int MAP_ATTR_IsLedgeWest(u16);
extern int MAP_ATTR_IsLedgeEast(u16);

int FIELD_PLAYER_GRID_GetWalkResultOnFoot(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    u16 k;
    u32 t;
    int cls;

    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return FIELD_PLAYER_GRID_GetStandResultOnFoot(a, (u32)b, c);
    }
    r = FIELD_PLAYER_GRID_GetStepHitFlags(a, b, ((struct Obj01657 *)c)->f8, &sp);
    if (((struct Obj01657 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        k = MAP_ATTR_GetTerrainId(sp);
        t = MAP_ATTR_GetFlags(sp);
        if (r & 2) {
            cls = 9;
            if (MAP_ATTR_IsLedgeNorth(k)) {
                cls = 0;
            } else if (MAP_ATTR_IsLedgeSouth(k)) {
                cls = 1;
            } else if (MAP_ATTR_IsLedgeWest(k)) {
                cls = 2;
            } else if (MAP_ATTR_IsLedgeEast(k)) {
                cls = 3;
            }
            if (cls != 9 && cls == ((struct Obj01657 *)c)->f8) {
                return 5;
            }
        }
        if (r == 0) {
            if (!(t & 2)) {
                return 2;
            }
            if (((struct Obj01657 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}

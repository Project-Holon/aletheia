/*
 * function: FIELD_PLAYER_GRID_GetWalkResultOnCycle
 * address:  0x021A4994
 * packet:   pkt_ov021_021A4994
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov021_func_021A4598; the final attribute test also consults
 * FIELD_PLAYER_GRID_IsTileBlockingCycle on the tile id.
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStandResultOnCycle  0x021A491C  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStepHitFlags  0x021A5264  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsLedgeNorth  0x021AB158  thumb  ov021
 *   MAP_ATTR_IsLedgeSouth  0x021AB164  thumb  ov021
 *   MAP_ATTR_IsLedgeWest  0x021AB170  thumb  ov021
 *   MAP_ATTR_IsLedgeEast  0x021AB17C  thumb  ov021
 *   FIELD_PLAYER_GRID_IsTileBlockingCycle  0x021A4960  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetStandResultOnCycle(u8 *, void *, u8 *);
extern int FIELD_PLAYER_GRID_GetStepHitFlags(u8 *a, void *b, u32 c, int *d);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int MAP_ATTR_IsLedgeNorth(u16);
extern int MAP_ATTR_IsLedgeSouth(u16);
extern int MAP_ATTR_IsLedgeWest(u16);
extern int MAP_ATTR_IsLedgeEast(u16);
extern int FIELD_PLAYER_GRID_IsTileBlockingCycle(int a);

int FIELD_PLAYER_GRID_GetWalkResultOnCycle(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    u16 k;
    u32 t;
    int cls;

    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (((struct Obj02084 *)c)->f8 == 9) {
        return FIELD_PLAYER_GRID_GetStandResultOnCycle(a, b, c);
    }
    r = FIELD_PLAYER_GRID_GetStepHitFlags(a, b, ((struct Obj02084 *)c)->f8, &sp);
    if (((struct Obj02084 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
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
            if (cls != 9 && cls == ((struct Obj02084 *)c)->f8) {
                return 5;
            }
        }
        if (r == 0) {
            if (!(t & 2) && FIELD_PLAYER_GRID_IsTileBlockingCycle(k) == 0) {
                return 2;
            }
            if (((struct Obj02084 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}

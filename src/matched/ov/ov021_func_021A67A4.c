/*
 * function: FIELD_PLAYER_NOGRID_GetForcedMoveKind
 * address:  0x021A67A4
 * packet:   pkt_ov021_021A67A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   FIELD_PLAYER_NOGRID_HasFlags  0x021A66F8  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsForcedSlide  0x021AB348  thumb  ov021
 *   RAIL_ATTR_IsForceMoveUp  0x021BB1AC  thumb  ov021
 *   RAIL_ATTR_IsForceMoveDown  0x021BB1B8  thumb  ov021
 *   RAIL_ATTR_IsForceMoveLeft  0x021BB1C4  thumb  ov021
 *   RAIL_ATTR_IsForceMoveRight  0x021BB1D0  thumb  ov021
 *   RAIL_ATTR_IsForceMoveStop  0x021BB1DC  thumb  ov021
 *   RAIL_ATTR_IsSlipDown  0x021BB1E8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19808.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FLDMMDL_GetNowAttr(void *p);
extern int FIELD_PLAYER_NOGRID_HasFlags(u8 *p, u32 m);
extern u16 MAP_ATTR_GetTerrainId(u32 a);
extern int MAP_ATTR_IsForcedSlide(u32 a);
extern int RAIL_ATTR_IsForceMoveUp(int x);
extern int RAIL_ATTR_IsForceMoveDown(int x);
extern int RAIL_ATTR_IsForceMoveLeft(int x);
extern int RAIL_ATTR_IsForceMoveRight(int x);
extern int RAIL_ATTR_IsForceMoveStop(int x);
extern int RAIL_ATTR_IsSlipDown(int x);

u32 FIELD_PLAYER_NOGRID_GetForcedMoveKind(u8 *p)
{
    u32 r4 = FLDMMDL_GetNowAttr((void *)(((struct Obj19808 *)p)->f1C));

    if (!FIELD_PLAYER_NOGRID_HasFlags(p, 2)) {
        r4 = MAP_ATTR_GetTerrainId(r4);
        if (MAP_ATTR_IsForcedSlide(r4) == 1)
            return 1;
        if (RAIL_ATTR_IsForceMoveUp(r4) == 1)
            return 2;
        if (RAIL_ATTR_IsForceMoveDown(r4) == 1)
            return 3;
        if (RAIL_ATTR_IsForceMoveLeft(r4) == 1)
            return 4;
        if (RAIL_ATTR_IsForceMoveRight(r4) == 1)
            return 5;
        if (RAIL_ATTR_IsForceMoveStop(r4) == 1)
            return 6;
        if (RAIL_ATTR_IsSlipDown(r4) == 1)
            return 7;
    }
    return 0;
}

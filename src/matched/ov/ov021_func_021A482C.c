/*
 * function: ov021_func_021A482C
 * address:  0x021A482C
 * packet:   pkt_ov021_021A482C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_IsHoldFlagSet  0x021A5390  thumb  ov021
 *   FIELD_PLAYER_GRID_StartHold  0x021A56F4  thumb  ov021
 *   FLDMMDL_DRAW_SyncFrameGroup  0x0219F7CC  thumb  ov021
 *   FIELD_PLAYER_GRID_EndHold  0x021A5708  thumb  ov021
 *   FIELD_PLAYER_GRID_SetHopFlag  0x021A53A4  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnFootHop  0x021A47B4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02083.h"
#include "../include/Obj19788.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int FIELD_PLAYER_GRID_IsHoldFlagSet(u32 a);
extern int FIELD_PLAYER_GRID_StartHold(u32 a);
extern int FLDMMDL_DRAW_SyncFrameGroup(u32, u32);
extern int FIELD_PLAYER_GRID_EndHold(u32 a);
extern void FIELD_PLAYER_GRID_SetHopFlag(u32 *p, int on);
extern int FIELD_PLAYER_GRID_GetWalkResultOnFootHop(u8 *, u32, u8 *);

int ov021_func_021A482C(u8 *a, u32 b, u8 *c)
{
    if (((struct Obj19788 *)c)->f8 == 9) {
        if (FIELD_PLAYER_GRID_IsHoldFlagSet((u32)a) == 0) {
            FIELD_PLAYER_GRID_StartHold((u32)a);
        }
        if (((struct Obj02083 *)a)->f16 == 1) {
            if (FLDMMDL_DRAW_SyncFrameGroup(b, ((struct Obj02083 *)a)->f14) != 0) {
                ((struct Obj02083 *)a)->f16 = 0;
            }
        }
        ((struct Obj02083 *)a)->f14 = ((struct Obj02083 *)a)->f14 + 1;
        if (((struct Obj02083 *)a)->f14 == 60) {
            FIELD_PLAYER_GRID_EndHold((u32)a);
            FIELD_PLAYER_GRID_SetHopFlag((u32 *)a, 1);
            return 7;
        }
    } else {
        FIELD_PLAYER_GRID_EndHold((u32)a);
        return FIELD_PLAYER_GRID_GetWalkResultOnFootHop(a, b, c);
    }
    return 6;
}

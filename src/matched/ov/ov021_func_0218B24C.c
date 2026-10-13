/*
 * function: FIELD_EVENT_CHECK_CheckRailSignBoard
 * address:  0x0218B24C
 * packet:   pkt_ov021_0218B24C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FIELD_PLAYER_ChooseMoveDirFromKeys  0x021A2FA4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   RAIL_ATTR_IsSignBoard  0x021BB188  thumb
 *   FLDMMDL_RAIL_GetHitBitsDirNoAttr  0x0219E418  thumb
 *   RAIL_SLIPDOWN_StartAtPlayer  0x021C46F8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09449.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u16 FIELD_PLAYER_ChooseMoveDirFromKeys(u8 *p, u32 a1);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int RAIL_ATTR_IsSignBoard(u16 a);
extern int FLDMMDL_RAIL_GetHitBitsDirNoAttr(u32 a, u32 b);
extern u32 RAIL_SLIPDOWN_StartAtPlayer(u32 a, u32 b, u32 c);

int FIELD_EVENT_CHECK_CheckRailSignBoard(char *p, void *q, void *x)
{
    void *a = FIELDMAP_GetFieldPlayer(x);
    void *o = FIELD_PLAYER_GetMmdl(a);
    int r = FIELD_PLAYER_ChooseMoveDirFromKeys(a, ((struct Obj09449 *)p)->f2C);

    if (r == 1) {
        int t = ((struct Obj09449 *)p)->f1C;
        if (t == 0 || t == 3) {
            if (RAIL_ATTR_IsSignBoard(MAP_ATTR_GetTerrainId(((struct Obj09449 *)p)->f38))) {
                if (FLDMMDL_RAIL_GetHitBitsDirNoAttr((u32)o, r) & 3)
                    return RAIL_SLIPDOWN_StartAtPlayer((u32)q, (u32)x, r);
            }
        }
    }
    return 0;
}

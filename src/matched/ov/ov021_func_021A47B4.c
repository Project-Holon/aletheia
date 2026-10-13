/*
 * function: ov021_func_021A47B4
 * address:  0x021A47B4
 * packet:   pkt_ov021_021A47B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStandResultOnFootHop  0x021A4768  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHopStepHitFlags  0x021A569C  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   FIELD_PLAYER_GRID_SetHopFlag  0x021A53A4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12736.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetStandResultOnFootHop(u32, u32, u32);
extern int FIELD_PLAYER_GRID_GetHopStepHitFlags(u8 *a, void *b, int c, int *d);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern void FIELD_PLAYER_GRID_SetHopFlag(u32 *p, int on);

int ov021_func_021A47B4(u32 a, u32 b, u8 *c)
{
    int sp;
    u32 r;
    if (FLDMMDL_CheckPossibleAcmd(b) == 0) {
        return 0;
    }
    if (((struct Obj12736 *)c)->f8 == 9) {
        return FIELD_PLAYER_GRID_GetStandResultOnFootHop(a, b, (u32)c);
    }
    r = FIELD_PLAYER_GRID_GetHopStepHitFlags((u8 *)a, (void *)b, ((struct Obj12736 *)c)->f8, &sp);
    if (sp != -1) {
        if (r & 0x100) {
            if (!(r & 0xFFFFFEFF)) {
                return 2;
            }
        } else if (MAP_ATTR_IsBlocked(sp) == 0) {
            FIELD_PLAYER_GRID_SetHopFlag((u32 *)a, 1);
            return 7;
        }
    }
    return 4;
}

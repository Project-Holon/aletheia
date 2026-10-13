/*
 * function: ov021_func_021A4B98
 * address:  0x021A4B98
 * packet:   pkt_ov021_021A4B98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStandResultOnSurf  0x021A4B54  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStepHitFlags  0x021A5264  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07498.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetStandResultOnSurf(u8 *, void *, u8 *);
extern int FIELD_PLAYER_GRID_GetStepHitFlags(u8 *a, void *b, u32 c, int *d);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);

int ov021_func_021A4B98(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    if (FLDMMDL_CheckPossibleAcmd((int)b) == 0) {
        return 0;
    }
    if (((struct Obj07498 *)c)->f8 == 9) {
        return FIELD_PLAYER_GRID_GetStandResultOnSurf(a, b, c);
    }
    r = FIELD_PLAYER_GRID_GetStepHitFlags(a, b, ((struct Obj07498 *)c)->f8, &sp);
    if (((struct Obj07498 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        u32 t;
        MAP_ATTR_GetTerrainId(sp);
        t = MAP_ATTR_GetFlags(sp);
        if (r == 0) {
            if (t & 2) {
                return 2;
            }
            if (((struct Obj07498 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}

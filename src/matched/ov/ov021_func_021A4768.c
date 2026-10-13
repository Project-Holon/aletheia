/*
 * function: ov021_func_021A4768
 * address:  0x021A4768
 * packet:   pkt_ov021_021A4768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetWalkResultOnFootHop  0x021A47B4  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHoldResultOnFootHop  0x021A482C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09566.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetWalkResultOnFootHop(u32, u32, u32);
extern int FIELD_PLAYER_GRID_GetHoldResultOnFootHop(u32, u32, u32);

int ov021_func_021A4768(u32 a, u32 b, u8 *c)
{
    if (FLDMMDL_CheckPossibleAcmd(b) == 1) {
        if (((struct Obj09566 *)c)->f8 != 9) {
            u32 r = FLDMMDL_GetDirDisp((void *)b);
            if (((struct Obj09566 *)c)->f8 != r && ((struct Obj09566 *)c)->f10 == 0) {
                return 3;
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnFootHop(a, b, (u32)c);
        }
        return FIELD_PLAYER_GRID_GetHoldResultOnFootHop(a, b, (u32)c);
    }
    return 0;
}

/*
 * function: ov021_func_021A4B54
 * address:  0x021A4B54
 * packet:   pkt_ov021_021A4B54
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
 *   FIELD_PLAYER_GRID_GetWalkResultOnSurf  0x021A4B98  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09567.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetWalkResultOnSurf(u32, u32, u32);

int ov021_func_021A4B54(u32 a, u32 b, u8 *c)
{
    if (FLDMMDL_CheckPossibleAcmd(b) == 1) {
        if (((struct Obj09567 *)c)->f8 != 9) {
            u32 r = FLDMMDL_GetDirDisp((void *)b);
            if (((struct Obj09567 *)c)->f8 != r && ((struct Obj09567 *)c)->f10 == 0) {
                return 3;
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnSurf(a, b, (u32)c);
        }
        return 1;
    }
    return 0;
}

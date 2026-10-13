/*
 * function: ov021_func_021A491C
 * address:  0x021A491C
 * packet:   pkt_ov021_021A491C
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
 *   FIELD_PLAYER_GRID_GetWalkResultOnCycle  0x021A4994  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetWalkResultOnCycle(u8 *a, void *b, u8 *c);

int ov021_func_021A491C(u32 a, u32 b, u8 *c)
{
    if (FLDMMDL_CheckPossibleAcmd(b) == 1) {
        if (((struct Obj02084 *)c)->f8 != 9) {
            u32 r = FLDMMDL_GetDirDisp((void *)b);
            if (((struct Obj02084 *)c)->f8 != r && ((struct Obj02084 *)c)->f10 == 0) {
                return 3;
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnCycle((u8 *)a, (void *)b, (u8 *)((u32)c));
        }
        return 1;
    }
    return 0;
}

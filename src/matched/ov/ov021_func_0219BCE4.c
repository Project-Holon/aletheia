/*
 * function: FLDMMDL_MOVE_CanTurnToFellow
 * address:  0x0219BCE4
 * packet:   pkt_ov021_0219BCE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 */
#include "../include/Obj19649.h"

typedef unsigned int u32;

extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_CheckMoveBitMove(void *a0);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);

int FLDMMDL_MOVE_CanTurnToFellow(u32 a, u32 b)
{
    u32 c = ((struct Obj19649 *)b)->f8;
    u32 x = FLDMMDL_GetGridNowX((void *)a);
    u32 y = FLDMMDL_GetGridNowZ((void *)a);
    u32 p = FLDMMDL_GetGridOldX((void *)c);
    u32 q = FLDMMDL_GetGridOldZ((void *)c);
    if (x != p || y != q) {
        if (FLDMMDL_CheckMoveBitMove((void *)c) == 1 || FLDMMDL_CheckMoveBit((void *)c, 0x1808) == 0) {
            return 1;
        }
    }
    return 0;
}

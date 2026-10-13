/*
 * function: FLDMMDL_MOVE_SetHideEffect
 * address:  0x0219BF3C
 * packet:   pkt_0219BF3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb
 */
#include "../include/Obj19650.h"

typedef unsigned int u32;

void *FLDMMDL_GetMoveProcWork(void);

void FLDMMDL_MOVE_SetHideEffect(int a, u32 v)
{
    ((struct Obj19650 *)((char *)FLDMMDL_GetMoveProcWork()))->f4 = v;
}

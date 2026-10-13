/*
 * function: FLDMMDL_SysSetG3dObjCont
 * address:  0x0216D524
 * packet:   pkt_ov010_0216D524
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: str r1, [r0, #0x28]; bx lr.
 */
#include "../include/Obj19121.h"

void FLDMMDL_SysSetG3dObjCont(void *p, void *v)
{
    ((struct Obj19121 *)p)->f28 = v;
}

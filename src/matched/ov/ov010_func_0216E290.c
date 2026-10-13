/*
 * function: FLDMMDL_CloseObjCodeArc
 * address:  0x0216E290
 * packet:   pkt_ov010_0216E290
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards the pointer at +0x14 to the arm9 routine at 0x02049238.
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj19134.h"

extern void ARC_TOOL_DeleteHandle(void *p);

void FLDMMDL_CloseObjCodeArc(char *p)
{
    ARC_TOOL_DeleteHandle(((struct Obj19134 *)p)->f14);
}

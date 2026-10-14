/*
 * function: ZUKAN_DETAIL_FORM_ReleaseIconResources
 * address:  0x021C533C
 * packet:   pkt_021C533C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   (none)
 *
 * Calls 0x0204AFD8 on +0x138, 0x0204ADA4 on +0x134 and 0x02049238 on +0x128 of the second argument.
 */
#include "../include/Obj09213.h"

typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void ARC_TOOL_DeleteHandle(int);

void ZUKAN_DETAIL_FORM_ReleaseIconResources(void *a, char *q)
{
    CLACT_ReleaseCellAnim(((struct Obj09213 *)q)->f138);
    CLACT_ReleasePalette(((struct Obj09213 *)q)->f134);
    ARC_TOOL_DeleteHandle(((struct Obj09213 *)q)->f128);
}

/*
 * function: FIELD_BUILDMODEL_DrawNode
 * address:  0x0218C934
 * packet:   pkt_ov021_0218C934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 */
#include "../include/Obj19544.h"

struct Arg;
void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

void FIELD_BUILDMODEL_DrawNode(unsigned char *p)
{
    if (p != 0)
        G3D_SYSTEM_DrawObject((void *)(((struct Obj19544 *)p)->fC), (struct Arg *)(p + 0x24));
}

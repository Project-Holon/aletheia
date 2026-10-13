/*
 * function: FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry
 * address:  0x0218C990
 * packet:   pkt_ov021_0218C990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetNodeKindTableEntry  0x0218C944  thumb  ov021
 */
#include "../include/Obj19545.h"

typedef unsigned short u16;
typedef unsigned int   u32;
int FIELD_BUILDMODEL_GetNodeKindTableEntry(void *p, u32 idx, u16 *out);

int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(unsigned char *p, int v)
{
    if (p == 0)
        return 0;
    return FIELD_BUILDMODEL_GetNodeKindTableEntry(p, ((struct Obj19545 *)p)->f4, (u16 *)v);
}

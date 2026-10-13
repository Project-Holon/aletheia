/*
 * function: FIELD_BUILDMODEL_PlayNodeSlot
 * address:  0x0218C88C
 * packet:   pkt_ov021_0218C88C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_PlayAnimSet  0x0218C3B0  thumb  ov021
 */
#include "../include/Obj19538.h"

void FIELD_BUILDMODEL_PlayAnimSet(unsigned char *p, int i, int c);

void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *p, int v, int c)
{
    if (p != 0) {
        ((struct Obj19538 *)p)->f4 = v;
        FIELD_BUILDMODEL_PlayAnimSet(p + 0xC, v, c);
    }
}

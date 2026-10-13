/*
 * function: FIELD_BUILDMODEL_PlayNodeCurrentSlot
 * address:  0x0218C89C
 * packet:   pkt_ov021_0218C89C
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
#include "../include/Obj19539.h"

void FIELD_BUILDMODEL_PlayAnimSet(unsigned char *p, int a, int b);

void FIELD_BUILDMODEL_PlayNodeCurrentSlot(unsigned char *p, int v)
{
    if (p != 0)
        FIELD_BUILDMODEL_PlayAnimSet(p + 0xC, ((struct Obj19539 *)p)->f4, v);
}

/*
 * function: FIELD_BUILDMODEL_PlayEntryAnim
 * address:  0x0218C69C
 * packet:   pkt_ov021_0218C69C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetEntryModelId  0x0218C530  thumb  ov021
 *   FIELD_BUILDMODEL_PlayAnimSet  0x0218C3B0  thumb  ov021
 */
#include "../include/Obj12572.h"

unsigned char FIELD_BUILDMODEL_GetEntryModelId(int b);
void FIELD_BUILDMODEL_PlayAnimSet(void *p, int i, int c);

void FIELD_BUILDMODEL_PlayEntryAnim(unsigned char *p, int b, int i, int c)
{
    unsigned char v = FIELD_BUILDMODEL_GetEntryModelId(b);
    if (v >= 0x80 || v >= ((struct Obj12572 *)p)->f1AC)
        v = 0;
    FIELD_BUILDMODEL_PlayAnimSet(*(unsigned char * *)&((struct Obj12572 *)p)->f1D8 + v * 0x18, i, c);
}

/*
 * function: FIELD_BUILDMODEL_GetEntrySlotFrame
 * address:  0x0218C6F4
 * packet:   pkt_ov021_0218C6F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetEntryModelId  0x0218C530  thumb  ov021
 *   FIELD_BUILDMODEL_GetSlotFrame  0x0218C47C  thumb  ov021
 */
#include "../include/Obj12574.h"

unsigned char FIELD_BUILDMODEL_GetEntryModelId(int b);
int FIELD_BUILDMODEL_GetSlotFrame(int *p, int id);

int FIELD_BUILDMODEL_GetEntrySlotFrame(unsigned char *p, int b, int id)
{
    unsigned char v = FIELD_BUILDMODEL_GetEntryModelId(b);
    if (v >= 0x80 || v >= ((struct Obj12574 *)p)->f1AC)
        v = 0;
    return FIELD_BUILDMODEL_GetSlotFrame((int *)(*(unsigned char * *)&((struct Obj12574 *)p)->f1D8 + v * 0x18), id);
}

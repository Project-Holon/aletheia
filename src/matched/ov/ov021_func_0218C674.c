/*
 * function: FIELD_BUILDMODEL_GetEntryAnimKind
 * address:  0x0218C674
 * packet:   pkt_ov021_0218C674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetEntryModelId  0x0218C530  thumb  ov021
 *   FIELD_BUILDMODEL_GetModelDef  0x0218B924  thumb  ov021
 *   FIELD_BUILDMODEL_GetModelAnimKind  0x0218BCB0  thumb  ov021
 */
#include "../include/Obj19537.h"

unsigned char FIELD_BUILDMODEL_GetEntryModelId(int b);
typedef unsigned int   u32;
typedef unsigned char  u8;
int FIELD_BUILDMODEL_GetModelDef(u8 *p, u32 a1);
unsigned char FIELD_BUILDMODEL_GetModelAnimKind(unsigned short *p);

int FIELD_BUILDMODEL_GetEntryAnimKind(unsigned char *p, int b)
{
    unsigned char v = FIELD_BUILDMODEL_GetEntryModelId(b);
    if (v >= 0x80 || v >= ((struct Obj19537 *)p)->f1AC)
        v = 0;
    return FIELD_BUILDMODEL_GetModelAnimKind((short unsigned int *)FIELD_BUILDMODEL_GetModelDef(p, v));
}

/*
 * function: FLDEFF_HIDE_FreeResources
 * address:  0x021D0440
 * packet:   pkt_ov021_021D0440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 */
#include "../include/Obj09743.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern u32 FIELD_G3DOBJ_DeleteObject(u32, u32);
extern void FIELD_G3DOBJ_DeleteResource(u8 *p, int i);

void FLDEFF_HIDE_FreeResources(u16 *p)
{
    int i = 0;
    u32 h = FIELD_EFFECT_GetFieldMapData((u8 *)(((struct Obj09743 *)p)->f4));

    for (; i < 2; i++) {
        FIELD_G3DOBJ_DeleteObject(h, p[4 + i]);
        FIELD_G3DOBJ_DeleteResource((u8 *)h, p[i]);
    }
}

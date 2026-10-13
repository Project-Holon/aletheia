/*
 * function: FLDEFF_KEMURI_Init
 * address:  0x021AC62C
 * packet:   pkt_ov021_021AC62C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05038.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern void FIELD_EFFECT_SetObjectPos(u32 a, u32 *b);
extern u32 FIELD_G3DOBJ_AddObject(u32 a, u32 b, u32 c, u32 *d);

void FLDEFF_KEMURI_Init(u32 a, u32 *b)
{
    u32 *p = (u32 *)FIELD_EFFECT_GetObjectParam(a);
    b[0] = p[0];
    b[1] = FIELD_EFFECT_GetFieldMapData((u8 *)(*(u32 *)b[0]));
    FIELD_EFFECT_SetObjectPos(a, p + 1);
    ((struct Obj05038 *)b)->f8 = FIELD_G3DOBJ_AddObject(b[1], *(u16 *)(b[0] + 4), 0, p + 1);
}

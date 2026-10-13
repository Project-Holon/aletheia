/*
 * function: FLDEFF_KEMURI_LoadResource
 * address:  0x021AC4CC
 * packet:   pkt_ov021_021AC4CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07513.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void FIELD_G3DOBJ_InitResDesc(u32 a);
extern int FIELD_G3DOBJ_SetResDescModel(u32 a, u32 b, u32 c);
extern void FIELD_G3DOBJ_SetResDescAnimeArc(u32 *p, u32 v);
extern void FIELD_G3DOBJ_AddResDescAnimeFile(u32 *a, u32 b);
extern int FIELD_G3DOBJ_AddResourceDefaultPal(u32 a, u32 b, u32 c);

void FLDEFF_KEMURI_LoadResource(u32 *a)
{
    u32 buf[9];
    u32 r6 = FIELD_EFFECT_GetFieldMapData((u8 *)a[0]);
    u32 r4 = FIELD_EFFECT_GetArcHandle((u8 *)a[0]);
    FIELD_G3DOBJ_InitResDesc((u32)buf);
    FIELD_G3DOBJ_SetResDescModel((u32)buf, r4, 0x30);
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)buf, r4);
    FIELD_G3DOBJ_AddResDescAnimeFile(buf, 0x60);
    ((struct Obj07513 *)a)->f4 = FIELD_G3DOBJ_AddResourceDefaultPal(r6, (u32)buf, 0);
}

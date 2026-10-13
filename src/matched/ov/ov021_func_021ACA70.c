/*
 * function: FLDEFF_NAMIPOKE_LoadResources
 * address:  0x021ACA70
 * packet:   pkt_ov021_021ACA70
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
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectManualDraw  0x021C67D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

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
extern u32 FIELD_G3DOBJ_AddObject(u32 a, u32 b, u32 c, u32 d);
extern void FIELD_G3DOBJ_SetObjectManualDraw(u32 a, u32 b, u32 c);

void FLDEFF_NAMIPOKE_LoadResources(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r4 = FIELD_EFFECT_GetFieldMapData((u8 *)a[0]);
    u32 r6 = FIELD_EFFECT_GetArcHandle((u8 *)a[0]);
    FIELD_G3DOBJ_InitResDesc((u32)buf);
    FIELD_G3DOBJ_SetResDescModel((u32)buf, r6, 0x31);
    h[2] = FIELD_G3DOBJ_AddResourceDefaultPal(r4, (u32)buf, 0);
    h[4] = FIELD_G3DOBJ_AddObject(r4, h[2], 0, 0);
    FIELD_G3DOBJ_SetObjectManualDraw(r4, h[4], 1);
    FIELD_G3DOBJ_InitResDesc((u32)buf);
    FIELD_G3DOBJ_SetResDescModel((u32)buf, r6, 0x36);
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)buf, r6);
    FIELD_G3DOBJ_AddResDescAnimeFile(buf, 0x6b);
    FIELD_G3DOBJ_AddResDescAnimeFile(buf, 0x85);
    h[3] = FIELD_G3DOBJ_AddResourceDefaultPal(r4, (u32)buf, 0);
    h[5] = FIELD_G3DOBJ_AddObject(r4, h[3], 0, 0);
    FIELD_G3DOBJ_SetObjectManualDraw(r4, h[5], 1);
}

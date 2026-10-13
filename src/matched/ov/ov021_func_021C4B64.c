/*
 * function: FLDEFF_SPLASH_LoadModel
 * address:  0x021C4B64
 * packet:   pkt_ov021_021C4B64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct P { u32 f0; u16 h4; u16 h6; } P;

extern u32 FIELD_EFFECT_GetFieldMapData(unsigned char *p);
typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void FIELD_G3DOBJ_InitResDesc(u32 a);
extern int FIELD_G3DOBJ_SetResDescModel(u32 a, u32 b, u32 c);
extern void FIELD_G3DOBJ_SetResDescAnimeArc(u32 *a, u32 b);
extern void FIELD_G3DOBJ_AddResDescAnimeFile(u32 *a, u32 b);
extern int FIELD_G3DOBJ_AddResourceDefaultPal(u32 a, u32 b, u32 c);
extern u16 FIELD_G3DOBJ_AddObject(u32 a, u32 b, u32 c, u32 d);
extern void FIELD_G3DOBJ_SetObjectManualDraw(u32 a, u32 b, u32 c);

void FLDEFF_SPLASH_LoadModel(P *p)
{
    u32 buf[9];
    u32 x = FIELD_EFFECT_GetFieldMapData((unsigned char *)p->f0);
    u32 y = FIELD_EFFECT_GetArcHandle((u8 *)p->f0);

    FIELD_G3DOBJ_InitResDesc((u32)buf);
    FIELD_G3DOBJ_SetResDescModel((u32)buf, y, 0x5f);
    FIELD_G3DOBJ_SetResDescAnimeArc(buf, y);
    FIELD_G3DOBJ_AddResDescAnimeFile(buf, 0x6a);
    p->h4 = FIELD_G3DOBJ_AddResourceDefaultPal(x, (u32)buf, 0);
    p->h6 = FIELD_G3DOBJ_AddObject(x, p->h4, 0, 0);
    FIELD_G3DOBJ_SetObjectManualDraw(x, p->h6, 1);
}

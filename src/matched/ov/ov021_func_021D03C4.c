/*
 * function: FLDEFF_HIDE_LoadResources
 * address:  0x021D03C4
 * packet:   pkt_ov021_021D03C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectManualDraw  0x021C67D8  thumb  ov021
 *   sHideFiles  0x021DB92C  data  ov021  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct T {
    u16 a;
    u16 b;
} T;

typedef struct W {
    u16 h[2];
    u32 f4;
    u16 g[2];
} W;

typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern void FIELD_G3DOBJ_InitResDesc(u32 a);
extern int FIELD_G3DOBJ_SetResDescModel(u32 a, u32 b, u32 c);
extern void FIELD_G3DOBJ_SetResDescAnimeArc(u32 *p, u32 v);
extern void FIELD_G3DOBJ_AddResDescAnimeFile(u32 *, u16);
extern int FIELD_G3DOBJ_AddResourceDefaultPal(u32 a, u32 b, u32 c);
extern u16 FIELD_G3DOBJ_AddObject(u32, u32, u32, u32);
extern void FIELD_G3DOBJ_SetObjectManualDraw(u32, u32, u32);
extern const T sHideFiles[];

void FLDEFF_HIDE_LoadResources(W *p)
{
    u32 buf[9];
    u32 k;
    u32 h;
    int i = 0;
    const T *t = sHideFiles;
    u16 *hp = (u16 *)p;
    u16 *q;

    k = FIELD_EFFECT_GetArcHandle((u8 *)p->f4);
    h = FIELD_EFFECT_GetFieldMapData((u8 *)p->f4);
    for (; i < 2; i++, t++) {
        FIELD_G3DOBJ_InitResDesc((u32)buf);
        FIELD_G3DOBJ_SetResDescModel((u32)buf, k, t->a);
        FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)buf, k);
        FIELD_G3DOBJ_AddResDescAnimeFile(buf, t->b);
        q = hp + i;
        hp[i] = FIELD_G3DOBJ_AddResourceDefaultPal(h, (u32)buf, 0);
        q[4] = FIELD_G3DOBJ_AddObject(h, hp[i], 0, 0);
        FIELD_G3DOBJ_SetObjectManualDraw(h, q[4], 1);
    }
}

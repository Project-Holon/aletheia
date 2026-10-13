/*
 * function: FLDEFF_HIDE_Draw
 * address:  0x021D0568
 * packet:   pkt_ov021_021D0568
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3DOBJ_SetAnimeFrame  0x021C6744  thumb  ov021
 *   FIELD_G3DOBJ_IncAnimeFrame  0x021C6694  thumb  ov021
 *   FIELD_G3DOBJ_GetAnimeFrame  0x021C67A8  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectTrans  0x021C6664  thumb  ov021
 *   FIELD_G3DOBJ_DrawObject  0x021C67F4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef struct R {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u16 h18;
    u16 h1a;
    u16 h1c;
    u16 h1e;
    u32 f20;
} R;

extern void FIELD_G3DOBJ_SetAnimeFrame(u32 *a, int idx, int mode, u32 val);
extern int FIELD_G3DOBJ_IncAnimeFrame(u32 *a, int idx, int v);
extern u32 FIELD_G3DOBJ_GetAnimeFrame(u32 a, u32 b, u32 c);
extern void FIELD_EFFECT_GetObjectPos(u32 a, Vec3 *v);
extern void FIELD_G3DOBJ_SetObjectTrans(u32 a, u32 b, Vec3 *v);
extern void FIELD_G3DOBJ_DrawObject(u32 a, u32 b);

void FLDEFF_HIDE_Draw(u32 a, R *b)
{
    Vec3 v;

    if (b->h1a == 1 && b->h1c == 0) {
        FIELD_G3DOBJ_SetAnimeFrame((u32 *)b->f4, b->h18, 0, b->f20);
        if (FIELD_G3DOBJ_IncAnimeFrame((u32 *)b->f4, b->h18, 0x1000) == 0) {
            b->h1c = 1;
        }
        b->f20 = FIELD_G3DOBJ_GetAnimeFrame(b->f4, b->h18, 0);
    } else {
        FIELD_G3DOBJ_SetAnimeFrame((u32 *)b->f4, b->h18, 0, b->f20);
    }
    FIELD_EFFECT_GetObjectPos(a, &v);
    FIELD_G3DOBJ_SetObjectTrans(b->f4, b->h18, &v);
    FIELD_G3DOBJ_DrawObject(b->f4, b->h18);
}

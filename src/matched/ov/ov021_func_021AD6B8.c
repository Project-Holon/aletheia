/*
 * function: FLDEFF_NAMIPOKE_SPLASH_Update
 * address:  0x021AD6B8
 * packet:   pkt_ov021_021AD6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_IncAnimeFrame  0x021C6694  thumb  ov021
 *   FIELD_G3DOBJ_LoopAnimeFrame  0x021C66EC  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 */
typedef unsigned short u16;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct S16 {
    int a;
    int *b;
    int c, d;
} S16;

typedef struct Obj {
    Vec v;
    int padc;
    u16 h10;
    u16 pad12;
    S16 s14;
} Obj;

extern void FIELD_EFFECT_DeleteObject(int a);
typedef unsigned char  u8;
extern unsigned int FIELD_EFFECT_GetFieldMapData(u8 *p);
typedef unsigned int   u32;
extern int FIELD_G3DOBJ_IncAnimeFrame(u32 *a, int idx, int v);
extern int FIELD_G3DOBJ_LoopAnimeFrame(u32 *a, int idx, int v);
extern void FIELD_EFFECT_GetObjectPos(int a, Vec *v);
extern void FIELD_EFFECT_SetObjectPos(int a, Vec *v);

void FLDEFF_NAMIPOKE_SPLASH_Update(int a, Obj *b)
{
    Vec v;
    int r;

    if (b->padc == 1 && b->s14.a == 1) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    r = FIELD_EFFECT_GetFieldMapData((u8 *)(*b->s14.b));
    if (b->s14.c == 0) {
        if (b->padc == 0) {
            if (FIELD_G3DOBJ_IncAnimeFrame((u32 *)r, b->h10, 0x1000) == 0) {
                b->padc = 1;
            }
        }
    } else {
        FIELD_G3DOBJ_LoopAnimeFrame((u32 *)r, b->h10, 0x1000);
    }
    if (b->s14.d != 0) {
        FIELD_EFFECT_GetObjectPos(b->s14.d, &v);
        v.x += b->v.x;
        v.y += b->v.y;
        v.z += b->v.z;
        FIELD_EFFECT_SetObjectPos(a, &v);
    }
}

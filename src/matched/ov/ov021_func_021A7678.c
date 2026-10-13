/*
 * function: FIELD_GROUND_ANIME_TexAnmInit
 * address:  0x021A7678
 * packet:   pkt_ov021_021A7678
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialiser for the animation object FIELD_GROUND_ANIME_TexAnmUpdate steps: allocates the
 * per-track arrays and seeds each track's frame Pair and minimum key.
 * The heap id is u16 in both this signature and func_02030734's: with u32
 * the stack-argument load drops from the first instruction to after the
 * register copies (docs/idioms/a-narrow-parameter-pins-its-home-store-to-
 * the-front-of-the-prologue.md, here for a load).
 *
 * symbols:
 *   FIELD_GROUND_ANIME_GetTexAnmKeyData  0x021A7A28  thumb  ov021
 *   FIELD_GROUND_ANIME_KeyTableUnpack  0x021A7AB0  thumb  ov021
 *   G3D_SYSTEM_GetResourceSize  0x02046C94  arm
 *   func_02030734  0x02030734  arm
 *   FIELD_GROUND_ANIME_GetTexAnmFile  0x021A7A34  thumb  ov021
 *   G3D_SYSTEM_InitResourceByFile  0x02046CE0  arm
 *   FIELD_GROUND_ANIME_KeyTableGetGroupCount  0x021A7A88  thumb  ov021
 *   FIELD_GROUND_ANIME_KeyTableGetKey  0x021A7A40  thumb  ov021
 *   FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame  0x021A7A90  thumb  ov021
 *   FIELD_GROUND_ANIME_GetModelTexVramOffset  0x021A78EC  thumb  ov021
 *   FIELD_GROUND_ANIME_GetTexSize  0x021A797C  thumb  ov021
 *   _FieldGroundAnimeFileName     0x021DDF7C  data  ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Pair { u8 lo; u8 hi; } Pair;

typedef struct Obj {
    u32 f00;
    Pair *f04;
    s32 *f08;
    u32 *f0C;
    s32 *f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 f20[0x1C];
    void *f3C;
} Obj;

extern char _FieldGroundAnimeFileName;
extern int FIELD_GROUND_ANIME_GetTexAnmKeyData(u32 a, u32 b);
struct Out;
struct S02046CE0;
extern void FIELD_GROUND_ANIME_KeyTableUnpack(u32 *src, struct Out *o);
extern int G3D_SYSTEM_GetResourceSize(void);
extern void *func_02030734(u16 heap, u32 size, u32 one, char *file, u32 line);
extern int FIELD_GROUND_ANIME_GetTexAnmFile(u32 a, u32 b);
extern void G3D_SYSTEM_InitResourceByFile(struct S02046CE0 *out, u32 *tag);
extern u32 FIELD_GROUND_ANIME_KeyTableGetGroupCount(u8 *p);
extern Pair FIELD_GROUND_ANIME_KeyTableGetKey(void *t, u32 idx, u32 key);
extern u16 FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame(void *t, u32 idx);
extern int FIELD_GROUND_ANIME_GetModelTexVramOffset(void *a, void *b, u32 idx);
extern u32 FIELD_GROUND_ANIME_GetTexSize(void *a, u32 idx);

void FIELD_GROUND_ANIME_TexAnmInit(Obj *o, u32 a, u32 b, u32 c, u16 heap)
{
    u32 i;
    s32 j;
    s32 n;
    u8 m;
    Pair t;

    o->f18 = c;
    o->f1C = FIELD_GROUND_ANIME_GetTexAnmKeyData(a, b);
    FIELD_GROUND_ANIME_KeyTableUnpack((u32 *)o->f1C, (struct Out *)o->f20);
    o->f3C = func_02030734(heap, G3D_SYSTEM_GetResourceSize(), 1, &_FieldGroundAnimeFileName, 0x2c9);
    G3D_SYSTEM_InitResourceByFile(o->f3C, (u32 *)FIELD_GROUND_ANIME_GetTexAnmFile(a, b));
    o->f14 = FIELD_GROUND_ANIME_KeyTableGetGroupCount(o->f20);
    o->f04 = func_02030734(heap, o->f14 * 2, 1, &_FieldGroundAnimeFileName, 0x2d4);
    o->f08 = func_02030734(heap, o->f14 * 4, 1, &_FieldGroundAnimeFileName, 0x2d5);
    o->f0C = func_02030734(heap, o->f14 * 4, 1, &_FieldGroundAnimeFileName, 0x2d6);
    o->f10 = func_02030734(heap, o->f14 * 4, 1, &_FieldGroundAnimeFileName, 0x2d7);
    for (i = 0; i < o->f14; i++) {
        o->f04[i] = FIELD_GROUND_ANIME_KeyTableGetKey(o->f20, i, 0);
        n = FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame(o->f20, i);
        m = o->f04[i].lo;
        for (j = 0; j < n; j++) {
            t = FIELD_GROUND_ANIME_KeyTableGetKey(o->f20, i, j);
            if (m > t.lo) {
                m = t.lo;
            }
        }
        o->f08[i] = FIELD_GROUND_ANIME_GetModelTexVramOffset((void *)c, o->f3C, m);
        o->f0C[i] = FIELD_GROUND_ANIME_GetTexSize(o->f3C, m);
    }
    o->f00 = 1;
}

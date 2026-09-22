/*
 * function: func_02066E30
 * address:  0x02066E30
 * packet:   pkt_02066E30
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02066B84   0x02066B84  arm
 *   g_02148B2C      0x02148B2C  data
 *   tbl_020A17F0    0x020A17F0  data
 *   tbl_020A17D8    0x020A17D8  data
 *   g_020A8218      0x020A8218  data
 *
 * The composer's 3D-geometry emitter: one textured unit quad per call.
 * func_02066B84 fills a six-word UV/extent buffer from the OAM entry; an
 * affine-double entry is re-centred by half its object extent (objWidth /
 * objHeight tables at 0x020A17F0 / 0x020A17D8); then MTX_TRANSLATE (depth
 * biased by the render context's polygon counter when its gate is set),
 * MTX_SCALE, BEGIN_VTXS(QUADS), four TEXCOORD/VTX_10 pairs, END_VTXS, and the
 * counter advance.  Written with the TwlSDK inlines (G3_Translate, G3_Scale,
 * G3_TexCoord, G3_Vtx10, G3_Begin, G3_End, G2_GetOBJEffect, G2_GetOBJShape)
 * reproduced locally, since sources here are self-contained.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * ends `addeq sp, sp, #0x1c` / `popeq {r4, r5, r6, r7, pc}` at
 * 0x02067040/0x02067044 ahead of the five-instruction counter update at
 * 0x02067048..0x02067058; 1.1p1 -O4,p predicates the update
 * (ldrne/ldrne/ldrne/addne/strne), 584 bytes against 592.
 *
 * Levers, against docs/notes/pkt_02066E30.c.txt (576/386 under 1.1p1, pin
 * refused there on a different source): the SDK inline spellings; w and h
 * as named locals, h declared before w; and the two table reads written as
 * byte offsets, `tbl + shape * 8 + size * 2`, which gives the image's
 * shape-in-ip / size-in-lr assignment (the `[shape][size]` subscript form is
 * the same instructions with those two registers swapped, 10 bytes out).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;
typedef s32            fx32;
typedef s16            fx16;

typedef enum {
    GX_OAM_EFFECT_NONE = 0x0000,
    GX_OAM_EFFECT_AFFINE = 0x0100,
    GX_OAM_EFFECT_NODISPLAY = 0x0200,
    GX_OAM_EFFECT_AFFINE_DOUBLE = 0x0300
} GXOamEffect;

typedef enum {
    GX_OAM_SHAPE_8x8 = 0
} GXOamShape;

typedef struct { u32 attr01; u16 attr2; u16 _3; } GXOamAttr;

#define reg_G3_MTX_SCALE   (*(volatile u32 *)0x0400046C)
#define reg_G3_MTX_TRANS   (*(volatile u32 *)0x04000470)
#define reg_G3_TEXCOORD    (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_10      (*(volatile u32 *)0x04000490)
#define reg_G3_BEGIN_VTXS  (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS    (*(volatile u32 *)0x04000504)

#define GX_FX16ST(x)  ((s16)((x) >> 8))
#define GX_ST(s, t)   ((u32)((u16)GX_FX16ST(s) | ((u16)GX_FX16ST(t) << 16)))
#define GX_VECVTX10(x, y, z) \
    ((u32)(((((x) >> 6) & 0x3ff) << 0) | ((((y) >> 6) & 0x3ff) << 10) | ((((z) >> 6) & 0x3ff) << 20)))
#define FX32_ONE 0x1000
#define FX16_ONE ((fx16)0x1000)

static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_TRANS = (u32)x;
    reg_G3_MTX_TRANS = (u32)y;
    reg_G3_MTX_TRANS = (u32)z;
}
static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}
static inline void G3_TexCoord(fx32 s, fx32 t) { reg_G3_TEXCOORD = GX_ST(s, t); }
static inline void G3_Vtx10(fx16 x, fx16 y, fx16 z) { reg_G3_VTX_10 = GX_VECVTX10(x, y, z); }
static inline void G3_Begin(int prim) { reg_G3_BEGIN_VTXS = (u32)prim; }
static inline void G3_End(void) { reg_G3_END_VTXS = 0; }

static inline GXOamEffect G2_GetOBJEffect(const GXOamAttr *oam)
{
    GXOamEffect effect;
    effect = (GXOamEffect)(oam->attr01 & 0x0300);
    if (effect == GX_OAM_EFFECT_AFFINE || effect == GX_OAM_EFFECT_AFFINE_DOUBLE)
        return effect;
    return (GXOamEffect)(effect | (oam->attr01 & 0x30000000));
}
static inline GXOamShape G2_GetOBJShape(const GXOamAttr *oam)
{
    return (GXOamShape)(oam->attr01 & (0x0000c000 | 0xc0000000));
}

struct Ctx { u32 f00; fx32 f04; u32 f08; };

extern struct Ctx g_02148B2C;
extern const u16 tbl_020A17F0[3][4];
extern const u16 tbl_020A17D8[3][4];
extern const fx32 g_020A8218;
extern void func_02066B84(const GXOamAttr *oam, u32 a, u32 b, u32 c, fx32 *uv);

void func_02066E30(int x, int y, int z, const GXOamAttr *oam, u32 a4, u32 a5, u32 a6)
{
    fx32 uv[6];

    func_02066B84(oam, a4, a5, a6, uv);
    if (G2_GetOBJEffect(oam) == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        GXOamShape shape;
        int h;
        int w;
        shape = G2_GetOBJShape(oam);
        w = *(u16 *)((u8 *)tbl_020A17F0 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2);
        h = *(u16 *)((u8 *)tbl_020A17D8 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2);
        G3_Translate((x + (w >> 1)) << 12, (y + (h >> 1)) << 12,
                     g_02148B2C.f08 ? g_02148B2C.f04 + (z << 12) : z << 12);
    } else {
        G3_Translate(x << 12, y << 12,
                     g_02148B2C.f08 ? g_02148B2C.f04 + (z << 12) : z << 12);
    }
    G3_Scale(uv[4] << 12, uv[5] << 12, FX32_ONE);
    G3_Begin(1);
    G3_TexCoord(uv[0], uv[3]);
    G3_Vtx10(0, FX16_ONE, 0);
    G3_TexCoord(uv[2], uv[3]);
    G3_Vtx10(FX16_ONE, FX16_ONE, 0);
    G3_TexCoord(uv[2], uv[1]);
    G3_Vtx10(FX16_ONE, 0, 0);
    G3_TexCoord(uv[0], uv[1]);
    G3_Vtx10(0, 0, 0);
    G3_End();
    if (g_02148B2C.f08)
        g_02148B2C.f04 += g_020A8218;
}

/*
 * function: func_02194D1C
 * address:  0x02194D1C
 * packet:   pkt_ov021_02194D1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Immediate-mode draw of one sprite through the geometry engine registers:
 * push, translate, uniform scale, texture/palette from the owner's texture
 * keys, material, polygon attributes, an optional triangle (v[2], v[0], v[1])
 * and, when c is 0, a quad (v[5], v[3], v[4], v[6]); then pop. The texture
 * and palette addresses are the NNS key decode folded into the SDK packing
 * macros. Region ov021: ov021 holds this Thumb code and its caller
 * func_02194CE8 directly precedes it; ov009 is ARM here (wave A1 witness).
 *
 * What closed the docs/notes/func_02194D1C.c.txt residue: the SDK G3_Vtx /
 * G3_TexCoord inline shapes, a sub-struct pointer for b+0x1C (the image keeps
 * it in r6), translate loaded z, y, x into locals, and non-const parameters
 * (with const the loads float across the volatile stores).
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef s16 fx16;
typedef s32 fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx16 x, y, z; } VecFx16;

typedef struct Sprite {
    char pad00[0x18];
    u16 color;          /* 0x18 */
    u16 pad1a;
    struct Quad {
        VecFx32 trans;  /* 0x1C */
        fx32 scale;     /* 0x28 */
        VecFx16 v[7];   /* 0x2C */
        int tri;        /* 0x58 */
    } q;
    char pad5c[2];
    u16 rate;           /* 0x5E */
} Sprite;

typedef struct Owner {
    char pad[0xCC8];
    u32 texKey;         /* 0xCC8 */
    u32 plttKey;        /* 0xCCC */
} Owner;

#define reg_G3_MTX_PUSH        (*(volatile u32 *)0x04000444)
#define reg_G3_MTX_POP         (*(volatile u32 *)0x04000448)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_MTX_TRANS       (*(volatile u32 *)0x04000470)
#define reg_G3_COLOR           (*(volatile u32 *)0x04000480)
#define reg_G3_TEXCOORD        (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_16          (*(volatile u32 *)0x0400048C)
#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
#define reg_G3_DIF_AMB         (*(volatile u32 *)0x040004C0)
#define reg_G3_SPE_EMI         (*(volatile u32 *)0x040004C4)
#define reg_G3_BEGIN_VTXS      (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS        (*(volatile u32 *)0x04000504)

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

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    reg_G3_TEXCOORD = (u32)(u16)(fx16)(s >> 8) | ((u32)(u16)(fx16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    reg_G3_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    reg_G3_VTX_16 = (u32)(u16)z;
}

void func_02194D1C(Owner *a, Sprite *b, int c)
{
    struct Quad *q = &b->q;
    fx32 x, y, z;
    fx32 s;

    reg_G3_MTX_PUSH = 0;
    z = q->trans.z;
    y = q->trans.y;
    x = q->trans.x;
    G3_Translate(x, y, z);
    s = q->scale * b->rate / 8;
    G3_Scale(s, s, s);
    reg_G3_TEXIMAGE_PARAM = (((u16)a->texKey & 0x1FFFFFFF)) | 0x0C030000;
    reg_G3_TEXPLTT_BASE = ((a->plttKey & 0xFFFF) << 3) >> 4;
    reg_G3_DIF_AMB = 0x4210FFFF;
    reg_G3_SPE_EMI = 0x4210;
    reg_G3_POLYGON_ATTR = 0x3F1F00C0;
    if (q->tri) {
        reg_G3_BEGIN_VTXS = 0;
        reg_G3_COLOR = b->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(q->v[2].x, q->v[2].y, q->v[2].z);
        G3_TexCoord(0, 0);
        G3_Vtx(q->v[0].x, q->v[0].y, q->v[0].z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(q->v[1].x, q->v[1].y, q->v[1].z);
        reg_G3_END_VTXS = 0;
    }
    if (c == 0) {
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_COLOR = b->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(q->v[5].x, q->v[5].y, q->v[5].z);
        G3_TexCoord(0, 0);
        G3_Vtx(q->v[3].x, q->v[3].y, q->v[3].z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(q->v[4].x, q->v[4].y, q->v[4].z);
        G3_TexCoord(0x8000, 0x8000);
        G3_Vtx(q->v[6].x, q->v[6].y, q->v[6].z);
        reg_G3_END_VTXS = 0;
    }
    reg_G3_MTX_POP = 1;
}

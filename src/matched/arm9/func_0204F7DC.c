/*
 * function: func_0204F7DC
 * address:  0x0204F7DC
 * packet:   pkt_0204F7DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   G3X_Reset          0x0207DA8C  arm
 *   func_02048AE8      0x02048AE8  arm
 *   func_02048B0C      0x02048B0C  arm
 *   func_02048B30      0x02048B30  arm
 *   G3i_LookAt_        0x0207D7C4  arm
 *   MTX_LookAt         0x0207BCA0  arm
 *   MTX_Inverse43      0x0207B67C  arm
 *   MI_Copy36B         0x02082B60  arm
 *   VEC_Subtract       0x0207CA00  arm
 *   VEC_Normalize      0x0207CCA4  arm
 *   MTX_Identity33_    0x0207ADC4  arm
 *   MTX_RotY33_        0x0207AF1C  thumb
 *   func_02048C80      0x02048C80  arm
 *   func_02048CCC      0x02048CCC  arm
 *   FX_Div             0x0207C768  arm
 *   G3_MultTransMtx33  0x0207D950  arm
 *   G3_RotZ            0x0207D888  arm
 *   _s32_div_f         0x0209C0A4  arm
 *   FX_SinCosTable_    0x020A1B38  data
 *   gBillboardQuad     0x020A1514  data
 *
 * billboard.c's draw pass: camera look-at, the four per-mode billboard
 * rotation matrices (full inverse view, Y-axis only, identity, Y-axis),
 * light upload, then one textured quad per visible element through the
 * NitroSDK immediate G3 inlines (g3imm.h, transcribed here as static
 * inlines over the 0x04000440.. registers).  0x0207C768 is FX_Div.
 *
 * Levers, all measured: `fx32 scale = b->scale` as a local (spilled, not
 * re-read for the three FX_Div calls); the four quad-table halfwords read
 * into fx16 locals BEFORE G3_Begin (ldrsh + per-use u16 narrowing); the
 * cell offset written `s0 = ...; s0 += b->offS;` (the one-expression form
 * swaps the mul/ldrsh destinations); a SEPARATE counter j for the light
 * loop (sharing i puts i in the lowest spill slot); declaration order
 * scale, s1/s0/t1/t0, i, j, nx/ny/nz fixes the remaining spill slots.
 * func_02048C80/CCC take a u8 index here (`and r1, r8, #0xff`).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef s32 fx32;
typedef s16 fx16;
typedef int BOOL;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx16 x, y, z; } VecFx16;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct { fx32 m[4][3]; } MtxFx43;

#define reg_G3_MTX_MODE        (*(volatile u32 *)0x04000440)
#define reg_G3_MTX_PUSH        (*(volatile u32 *)0x04000444)
#define reg_G3_MTX_POP         (*(volatile u32 *)0x04000448)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_COLOR           (*(volatile u32 *)0x04000480)
#define reg_G3_NORMAL          (*(volatile u32 *)0x04000484)
#define reg_G3_TEXCOORD        (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_16          (*(volatile u32 *)0x0400048C)
#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
#define reg_G3_DIF_AMB         (*(volatile u32 *)0x040004C0)
#define reg_G3_SPE_EMI         (*(volatile u32 *)0x040004C4)
#define reg_G3_LIGHT_VECTOR    (*(volatile u32 *)0x040004C8)
#define reg_G3_LIGHT_COLOR     (*(volatile u32 *)0x040004CC)
#define reg_G3_BEGIN_VTXS      (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS        (*(volatile u32 *)0x04000504)

#define GX_VECFX10(x, y, z) \
    ((u32)(((((x) >> 3) & 0x3ff) << 0) | \
           ((((y) >> 3) & 0x3ff) << 10) | \
           ((((z) >> 3) & 0x3ff) << 20)))
#define GX_FX16PAIR(a, b)  ((u32)((u32)(u16)(a) | ((u32)(u16)(b) << 16)))
#define GX_FX16ST(x)       ((s16)((x) >> 8))
#define GX_ST(s, t)        ((u32)((u16)GX_FX16ST(s) | ((u16)GX_FX16ST(t) << 16)))

static inline void G3_MtxMode(int mode) { reg_G3_MTX_MODE = (u32)mode; }
static inline void G3_PushMtx(void) { reg_G3_MTX_PUSH = 0; }
static inline void G3_PopMtx(int num) { reg_G3_MTX_POP = (u32)num; }
static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}
static inline void G3_Color(u16 rgb) { reg_G3_COLOR = (u32)rgb; }
static inline void G3_Normal(fx16 x, fx16 y, fx16 z) { reg_G3_NORMAL = GX_VECFX10(x, y, z); }
static inline void G3_TexCoord(fx32 s, fx32 t) { reg_G3_TEXCOORD = GX_ST(s, t); }
static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    reg_G3_VTX_16 = GX_FX16PAIR(x, y);
    reg_G3_VTX_16 = (u32)(u16)z;
}
static inline void G3_PolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc)
{
    reg_G3_POLYGON_ATTR = (u32)((light << 0) | (polyMode << 4) | (cullMode << 6) | misc |
                                (polygonID << 24) | (alpha << 16));
}
static inline void G3_TexImageParam(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr)
{
    reg_G3_TEXIMAGE_PARAM = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}
static inline void G3_TexPlttBase(u32 addr, int texfmt)
{
    u32 param = (u32)(addr >> (4 - (texfmt == 2)));
    reg_G3_TEXPLTT_BASE = param;
}
static inline void G3_MaterialColorDiffAmb(u16 diffuse, u16 ambient, BOOL IsSetVtxColor)
{
    reg_G3_DIF_AMB = (u32)(diffuse | (ambient << 16) | ((IsSetVtxColor != 0) << 15));
}
static inline void G3_MaterialColorSpecEmi(u16 specular, u16 emission, BOOL IsShininess)
{
    reg_G3_SPE_EMI = (u32)(specular | (emission << 16) | ((IsShininess != 0) << 15));
}
static inline void G3_LightVector(int lightID, fx16 x, fx16 y, fx16 z)
{
    reg_G3_LIGHT_VECTOR = (u32)GX_VECFX10(x, y, z) | ((u32)lightID << 30);
}
static inline void G3_LightColor(int lightID, u16 rgb)
{
    reg_G3_LIGHT_COLOR = (u32)(rgb | ((u32)lightID << 30));
}
static inline void G3_Begin(int primitive) { reg_G3_BEGIN_VTXS = (u32)primitive; }
static inline void G3_End(void) { reg_G3_END_VTXS = 0; }

extern const fx16 FX_SinCosTable_[];
static inline fx16 FX_SinIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1)]; }
static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }

extern void G3X_Reset(void);
extern void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, BOOL draw, MtxFx43 *mtx);
extern void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);
extern int  MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst);
extern void MI_Copy36B(const void *pSrc, void *pDest);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern void MTX_Identity33_(MtxFx33 *pDst);
extern void MTX_RotY33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern void G3_MultTransMtx33(const MtxFx33 *mtx, const VecFx32 *trans);
extern void G3_RotZ(fx32 s, fx32 c);

static inline void MTX_Copy43To33(const MtxFx43 *pSrc, MtxFx33 *pDst) { MI_Copy36B(pSrc, pDst); }
static inline void MTX_Identity33(MtxFx33 *pDst) { MTX_Identity33_(pDst); }
static inline void MTX_RotY33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) { MTX_RotY33_(pDst, sinVal, cosVal); }

struct Camera;
extern void func_02048AE8(struct Camera *cam, VecFx32 *out);
extern void func_02048B0C(struct Camera *cam, VecFx32 *out);
extern void func_02048B30(struct Camera *cam, VecFx32 *out);

struct Lights;
struct LightSlot;
struct Rgb555;
extern void func_02048C80(struct LightSlot *slots, u8 i, struct Rgb555 *out);
struct LightSlot;
extern void func_02048CCC(struct LightSlot *slots, u8 i, u16 *out);

struct Slot {
    u32 f00;
    u16 f04;
    u16 f06;
    u8  f08;
    u8  f09;
    u8  f0a;
    u8  f0b;
    u32 vramAddr;   /* 0x0c */
    u32 plttAddr;   /* 0x10 */
    u32 fmt;        /* 0x14 */
    u32 sizeS;      /* 0x18 */
    u32 sizeT;      /* 0x1c */
    u32 f20;
    u32 f24;
};

struct Elem {
    u16 id   : 14;
    u16 mode : 2;
    u16 f02;
    VecFx32 pos;    /* 0x04 */
    u16 cell;       /* 0x10 */
    s16 scaleX;     /* 0x12 */
    s16 scaleY;     /* 0x14 */
    u16 rot;        /* 0x16 */
    u16 alpha : 5;  /* 0x18 */
    u16 polyId : 4;
    u16 visible : 1;
    u16 flipS : 1;
    u16 flipT : 1;
    u16 light : 4;
    u16 f1a;
};

struct Board {
    u16 id;
    u16 pad02;
    struct Slot *ptr0;
    struct Elem *ptr1;
    u16 count0;
    u16 count1;
    fx32 scale;     /* 0x10 */
    u32 f14;
    u32 f18;
    u16 diffuse;    /* 0x1c */
    u16 ambient;    /* 0x1e */
    u16 specular;   /* 0x20 */
    u16 emission;   /* 0x22 */
    u8  polyIdBase; /* 0x24 */
    u8  quadShape;  /* 0x25 */
    u16 pad26;
    u32 lookAtMode; /* 0x28 */
    u32 useLight;   /* 0x2c */
    fx16 lightX;    /* 0x30 */
    fx16 lightY;    /* 0x32 */
    fx16 lightZ;    /* 0x34 */
    s16 offS;       /* 0x36 */
    s16 offT;       /* 0x38 */
};

struct Quad { fx16 y0, y1, x0, x1; };
extern const struct Quad gBillboardQuad[];

void func_0204F7DC(struct Board *b, struct Camera *cam, struct Lights *lights)
{
    MtxFx33 rot[4];
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 target;
    VecFx32 dir;
    MtxFx43 view;
    MtxFx43 inv;
    VecFx32 flat;
    VecFx32 trans;
    VecFx16 lvec;
    u16 lcol;
    fx32 scale;
    fx32 s1, s0, t1, t0;
    int i;
    int j;
    fx16 nx, ny, nz;
    fx16 qy0, qy1, qx0, qx1;

    G3X_Reset();
    b->lookAtMode = 0;
    func_02048AE8(cam, &camPos);
    func_02048B0C(cam, &camUp);
    func_02048B30(cam, &target);
    if (b->lookAtMode == 0) {
        G3i_LookAt_(&camPos, &camUp, &target, 1, &view);
    } else {
        MTX_LookAt(&camPos, &camUp, &target, &view);
    }
    MTX_Inverse43(&view, &inv);
    MTX_Copy43To33(&inv, &rot[0]);

    VEC_Subtract(&camPos, &target, &flat);
    flat.y = 0;
    VEC_Normalize(&flat, &flat);
    MTX_Identity33(&rot[1]);
    MTX_RotY33(&rot[1], flat.x, flat.z);
    MTX_RotY33(&rot[3], flat.x, flat.z);
    MTX_Identity33(&rot[2]);

    VEC_Subtract(&camPos, &target, &dir);
    VEC_Normalize(&dir, &dir);

    if (b->useLight == 1) {
        nx = b->lightX;
        ny = b->lightY;
        nz = b->lightZ;
    } else {
        nx = dir.x;
        ny = dir.y;
        nz = dir.z;
    }

    if (lights != 0) {
        for (j = 0; j < 4; j++) {
            func_02048C80((struct LightSlot *)lights, j, (struct Rgb555 *)(&lvec));
            func_02048CCC((struct LightSlot *)lights, j, &lcol);
            G3_LightVector(j, lvec.x, lvec.y, lvec.z);
            G3_LightColor(j, lcol);
        }
    }

    G3_MtxMode(1);
    scale = b->scale;
    G3_Scale(scale, scale, scale);

    for (i = 0; i < b->count1; i++) {
        struct Slot *s;
        struct Elem *e = &b->ptr1[i];

        if (e->id == 0x3FFF) {
            continue;
        }
        if (!e->visible) {
            continue;
        }
        s = &b->ptr0[e->id];

        if (e->flipS) {
            s0 = (e->cell % s->f0a) * s->f08 << 12;
            s0 += b->offS;
            s1 = s0 + (s->f08 << 12);
        } else {
            s1 = (e->cell % s->f0a) * s->f08 << 12;
            s0 = s1 + (s->f08 << 12);
        }
        if (e->flipT) {
            t0 = (e->cell / s->f0a) * s->f09 << 12;
            t0 += b->offT;
            t1 = t0 + (s->f09 << 12);
        } else {
            t1 = (e->cell / s->f0a) * s->f09 << 12;
            t0 = t1 + (s->f09 << 12);
        }
        G3_PushMtx();
        trans.x = FX_Div(e->pos.x, scale);
        trans.y = FX_Div(e->pos.y, scale);
        trans.z = FX_Div(e->pos.z, scale);
        G3_MultTransMtx33(&rot[e->mode], &trans);
        G3_RotZ(-FX_SinIdx(e->rot), FX_CosIdx(e->rot));
        if (e->mode == 3) {
            G3_Scale(e->scaleX, 0x1000, e->scaleY);
        } else {
            G3_Scale(e->scaleX, e->scaleY, 0x1000);
        }
        G3_TexImageParam(s->fmt, 1, s->sizeS, s->sizeT, 0, 0, 1, s->vramAddr);
        G3_TexPlttBase(s->plttAddr, s->fmt);
        G3_MaterialColorDiffAmb(b->diffuse, b->ambient, 1);
        G3_MaterialColorSpecEmi(b->specular, b->emission, 0);
        G3_PolygonAttr(e->light, 0, 3, b->polyIdBase + e->polyId, e->alpha, 0x8000);
        qy0 = gBillboardQuad[b->quadShape].y0;
        qy1 = gBillboardQuad[b->quadShape].y1;
        qx0 = gBillboardQuad[b->quadShape].x0;
        qx1 = gBillboardQuad[b->quadShape].x1;
        G3_Begin(1);
        if (e->light) {
            G3_Normal(nx, ny, nz);
        } else {
            G3_Color(0x7FFF);
        }
        if (e->mode == 3) {
            G3_TexCoord(s1, t1);
            G3_Vtx(qx0, 0, qy0);
            G3_TexCoord(s1, t0);
            G3_Vtx(qx0, 0, qy1);
            G3_TexCoord(s0, t0);
            G3_Vtx(qx1, 0, qy1);
            G3_TexCoord(s0, t1);
            G3_Vtx(qx1, 0, qy0);
        } else {
            G3_TexCoord(s1, t1);
            G3_Vtx(qx0, qy0, 0);
            G3_TexCoord(s1, t0);
            G3_Vtx(qx0, qy1, 0);
            G3_TexCoord(s0, t0);
            G3_Vtx(qx1, qy1, 0);
            G3_TexCoord(s0, t1);
            G3_Vtx(qx1, qy0, 0);
        }
        G3_End();
        G3_PopMtx(1);
    }
}

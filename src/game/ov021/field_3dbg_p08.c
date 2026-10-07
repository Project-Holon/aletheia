/*
 * file:     field_3dbg_p08.c
 * unit:     yes
 * function: func_021A16E8, func_021A16EC, func_021A1750, func_021A1768, func_021A1780, func_021A1784, func_021A1848, func_021A1934, func_021A195C, func_021A19E8
 * address:  0x021A16E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   func_02049250  0x02049250  arm
 *   func_02046CE0  0x02046CE0  arm
 *   func_02047180  0x02047180  arm
 *   d_021DDE5C  0x021DDE5C  data  ov021
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02047204  0x02047204  arm
 *   FX_Div            0x0207C768  arm
 *   MTX_Identity33_   0x0207ADC4  arm
 *   MTX_RotZ33_       0x0207AF38  thumb
 *   MTX_Scale33_      0x0207AE24  thumb
 *   MTX_Concat33      0x0207B388  arm
 *   FX_SinCosTable_   0x020A1B38  data
 *   func_0207D934  0x0207D934  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_021A15A4  0x021A15A4  thumb  ov021
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_021A1DB4  0x021A1DB4  thumb  ov021
 *   func_021A1C1C  0x021A1C1C  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   d_021DDE74     0x021DDE74  data
 *   d_021D8850     0x021D8850  data
 *   d_021D8840     0x021D8840  data
 */
#include "../../matched/include/Obj19723.h"
#include "../../matched/include/Obj02379.h"
#include "../../matched/include/Obj04231.h"
#include "../../matched/include/Obj07217.h"
#include "../../matched/include/Obj09547.h"
#include "../../matched/include/Obj17997.h"

#define REG_MTX_MODE     (*(volatile u32 *)0x04000440)
#define REG_MTX_IDENTITY (*(volatile u32 *)0x04000454)
#define REG_MTX_SCALE    (*(volatile u32 *)0x0400046C)
#define REG_TEXCOORD     (*(volatile u32 *)0x04000488)
#define REG_VTX_16       (*(volatile u32 *)0x0400048C)
#define REG_BEGIN_VTXS   (*(volatile u32 *)0x04000500)
#define REG_END_VTXS     (*(volatile u32 *)0x04000504)
struct S02046CE0;
struct Tagged;
struct Layer;
struct Bank;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef signed char    s8;

typedef int            fx32_021A1784;

typedef s16            fx16;

typedef struct {
    fx32_021A1784 m[3][3];
} MtxFx33;

typedef struct {
    u16 w0;
    u16 w2;
    fx32_021A1784 f4;
    fx32_021A1784 f8;
    fx32_021A1784 fC;
    fx32_021A1784 f10;
    fx32_021A1784 f14;
    fx32_021A1784 f18;
    u16 rot;
} In021A1784;

typedef struct {
    fx32_021A1784 f0;
    fx32_021A1784 f4;
    fx32_021A1784 f8;
    fx32_021A1784 fC;
    fx32_021A1784 f10;
    fx32_021A1784 f14;
    fx32_021A1784 f18;
    fx32_021A1784 f1C;
    MtxFx33 mtx;
} Out021A1784;

typedef struct {
    fx32_021A1784 f0;
    fx32_021A1784 pad[4];
    fx32_021A1784 f14;
} Q021A1784;

typedef s32 fx32_021A1848;

typedef struct {
    u8 pad[0x20];
    u8 sizeS;
    u8 sizeT;
    u8 repeat;
    u8 flip;
    u8 fmt;
    u8 pltt0;
    u8 pad26[2];
    u32 key;
} Obj021A195C;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

typedef struct {
    u8 *f0[2];
    u16 f8;
    u16 fA;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    void *f18;
    void *f1C;
    u32 *f20[2];
    int f28;
    int f2C;
} Obj021A19E8;

typedef struct {
    u8 b[12];
} Desc021A19E8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02046C94(void);
extern void *func_02049250(void *h, u32 id, u16 heap);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern int func_02047180(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
u32 func_02047204(struct Tagged *p);
fx32_021A1784 FX_Div(fx32_021A1784 numer, fx32_021A1784 denom);
void MTX_Identity33_(MtxFx33 *pDst);
void MTX_RotZ33_(MtxFx33 *pDst, fx32_021A1784 sinVal, fx32_021A1784 cosVal);
void MTX_Scale33_(MtxFx33 *pDst, fx32_021A1784 x, fx32_021A1784 y, fx32_021A1784 z);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
extern void func_0207D934(const void *m);
u32 func_02047388(struct Layer *layer);
u32 func_020473B8(struct Layer *layer);
extern u8 *func_021A15A4(u8 *p, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern u32 *func_021A1DB4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i);
extern void func_021A1C1C(int a, u32 *p);
extern int func_020056A0(void (*cb)(void *), void *arg, int pri);
void func_021A16E8(unsigned char *p, unsigned int v);
void func_021A16EC(u8 *d, void *a, const u8 *s, u32 n);
int func_021A1750(u32 a);
void func_021A1768(u8 *p);
u32 func_021A1780(u8 *p);
void func_021A1784(Out021A1784 *out, const In021A1784 *in, int unused, const Q021A1784 *q);
void func_021A1848(const fx32_021A1848 *a);
void func_021A1934(u8 *p);
void func_021A195C(Obj021A195C *p);
Obj021A19E8 *func_021A19E8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u16 heap);
extern const char d_021DDE5C[];
extern const s16 FX_SinCosTable_[];
extern char d_021DDE74[];
extern Desc021A19E8 d_021D8850[];
extern u8 d_021D8840[];


/*
 * Unlabelled leaf (str r1,[r0,#0x18]; bx lr), filed for the ov026 lane.
 */
void func_021A16E8(unsigned char *p, unsigned int v)
{
    ((struct Obj19723 *)p)->f18 = v;
}


/*
 * Addresses are Black-image addresses.
 * `const u8 *s` is what schedules the second (u16)n truncation ahead of the
 * store of the allocation to d+8.
 */
void func_021A16EC(u8 *d, void *a, const u8 *s, u32 n)
{
    void *r;

    d[0] = s[2];
    d[1] = s[3];
    d[2] = s[4];
    d[3] = s[5];
    d[4] = s[6];
    d[5] = s[7];
    ((struct Obj02379 *)d)->f8 = func_02030734((u16)n, func_02046C94(), 1, d_021DDE5C, 0x2ad);
    r = func_02049250(a, *(const u16 *)&((struct Obj04231 *)s)->f0, n);
    func_02046CE0(((struct Obj02379 *)d)->f8, r);
    func_02047180(((struct Obj02379 *)d)->f8);
    d[6] = 1;
    d[7] = 1;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A1750(u32 a)
{
func_020470D0((u32 *)(((struct Obj07217 *)((u8 *)(a)))->f8));
func_02046EFC((struct Tagged *)(((struct Obj07217 *)((u8 *)(a)))->f8));
((struct Obj07217 *)((u8 *)(a)))->f8 = 0;
((struct Obj07217 *)((u8 *)(a)))->f6 = 0;
return 0;
}


void func_021A1768(u8 *p)
{
    if (p[7] != 0) {
        func_02047204((struct Tagged *)(((struct Obj09547 *)p)->f8));
        p[7] = 0;
    }
}


/*
 * Loads the byte at +0x6 of the object.
 */
u32 func_021A1780(u8 *p)
{
    return ((struct Obj17997 *)p)->f6;
}


static inline fx16 FX_SinIdx(int idx) { return FX_SinCosTable_[idx * 2]; }

static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[idx * 2 + 1]; }





/*
 * Notes: `in` is const (lets in->f4 and out->f4 loads rise above the out->f0
 * store); the 3-way max is four arms each calling FX_Div(.., 0x4000) into
 * out->fC (tail-merged). The fx32 range stores use two locals, both computed
 * before any store, with y declared before x: that keeps (fC<<12)+(w0<<12)
 * unfolded and gives the late f10 store from r2.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1784(Out021A1784 *out, const In021A1784 *in, int unused, const Q021A1784 *q)
{
    MtxFx33 tmp;
    fx32_021A1784 y;
    fx32_021A1784 x;

    out->f4 = FX_Div(in->f4, q->f14);
    out->f0 = FX_Div(in->f4, q->f0);
    out->f8 = in->f4;
    if (out->f4 > out->f0) {
        if (out->f4 > out->f8) {
            out->fC = FX_Div(out->f4, 0x4000);
        } else {
            out->fC = FX_Div(out->f8, 0x4000);
        }
    } else if (out->f0 > out->f8) {
        out->fC = FX_Div(out->f0, 0x4000);
    } else {
        out->fC = FX_Div(out->f8, 0x4000);
    }
    out->f0 = FX_Div(out->f0, out->fC);
    out->f4 = FX_Div(out->f4, out->fC);
    out->f8 = FX_Div(out->f8, out->fC);
    x = in->fC << 12;
    y = in->f10 << 12;
    out->f10 = x;
    out->f14 = x + (in->w0 << 12);
    out->f18 = y;
    out->f1C = y + (in->w2 << 12);
    MTX_Identity33_(&out->mtx);
    MTX_RotZ33_(&out->mtx, FX_SinIdx(in->rot >> 4), FX_CosIdx(in->rot >> 4));
    MTX_Scale33_(&tmp, in->f14, in->f18, 0x1000);
    MTX_Concat33(&out->mtx, &tmp, &out->mtx);
}


static inline void G3_TexCoord(fx32_021A1848 s, fx32_021A1848 t)
{
    REG_TEXCOORD = (u32)(u16)(fx16)(s >> 8) | ((u32)(u16)(fx16)(t >> 8) << 16);
}


static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}


/*
 * Draws one textured quad through the geometry engine registers
 * (MTX_MODE 0x04000440 .. END_VTXS 0x04000504); func_0207D934 is the
 * 3x3 matrix multiply (command 0x1A). The parameter must be const: without
 * it every a[] load is repeated after each volatile register store (340 B).
 *
 * Addresses are Black-image addresses.
 */
void func_021A1848(const fx32_021A1848 *a)
{
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    func_0207D934(a + 8);
    REG_MTX_MODE = 2;
    REG_MTX_SCALE = a[3];
    REG_MTX_SCALE = a[3];
    REG_MTX_SCALE = a[3];
    REG_BEGIN_VTXS = 1;
    G3_TexCoord(a[4], a[6]);
    G3_Vtx(-a[0], a[1], -a[2]);
    G3_TexCoord(a[4], a[7]);
    G3_Vtx(-a[0], -a[1], -a[2]);
    G3_TexCoord(a[5], a[7]);
    G3_Vtx(a[0], -a[1], -a[2]);
    G3_TexCoord(a[5], a[6]);
    G3_Vtx(a[0], a[1], -a[2]);
    REG_END_VTXS = 0;
}


static inline void G3_PolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc)
{
    *(volatile u32 *)0x040004A4 = (u32)((light << 0) | (polyMode << 4) | (cullMode << 6) | misc |
                                        (polygonID << 24) | (alpha << 16));
}


/*
 * G3_MaterialColorDiffAmb(white, white, TRUE) as a literal, then the SDK
 * G3_PolygonAttr inline (int parameters) with polygon id +0x1E, alpha +0x1F.
 * Addresses are Black-image addresses.
 */
void func_021A1934(u8 *p)
{
    *(volatile u32 *)0x040004C0 = 0x7FFFFFFF;
    G3_PolygonAttr(0, 0, 2, p[0x1E], p[0x1F], 0x8000);
}

static inline void G3_TexImageParam(GXTexFmt fmt, GXTexGen gen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    *(volatile u32 *)0x040004A8 = (u32)((addr >> 3) | (fmt << 26) | (gen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}


static inline void G3_TexPlttBase(u32 addr, GXTexFmt fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == GX_TEXFMT_PLTT4)));
    *(volatile u32 *)0x040004AC = param;
}


static inline u32 NNS_GfdGetTexKeyAddr(u32 key) { return (u32)((0x0000FFFF & key) << 3); }

static inline u32 NNS_GfdGetPlttKeyAddr(u32 key) { return (u32)((0x0000FFFF & key) << 3); }


/*
 * SDK G3_TexImageParam / G3_TexPlttBase inlines with the SDK enum parameter
 * types (enum parameters are materialised as temporaries before the body,
 * which gives the load order and the [sp] spill of the tex key), NNS key
 * address inlines, and the format read once into an int local.
 *
 * Addresses are Black-image addresses.
 */
void func_021A195C(Obj021A195C *p)
{
    u32 texKey = func_02047388((struct Layer *)p->key);
    int fmt = p->fmt;

    G3_TexImageParam(fmt, GX_TEXGEN_TEXCOORD, p->sizeS, p->sizeT, p->repeat, p->flip, p->pltt0, NNS_GfdGetTexKeyAddr(texKey));
    G3_TexPlttBase(NNS_GfdGetPlttKeyAddr(func_020473B8((struct Layer *)p->key)), fmt);
}


/*
 * The two loops use separate counters (one shared counter swaps p and the
 * counter between r4 and r5).
 *
 * Addresses are Black-image addresses.
 */
Obj021A19E8 *func_021A19E8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u16 heap)
{
    int i;
    int j;
    Obj021A19E8 *p = func_02030734(heap, 0x30, 1, d_021DDE74, 0x158);

    for (i = 0; i < 2; i++) {
        p->f0[i] = func_021A15A4(d_021D8850[i].b, heap);
    }
    p->f8 = 0;
    p->fA = 0;
    p->fC = 0xFFFF;
    p->fE = 0xFFFF;
    p->f14 = 0xFFFF;
    p->f28 = -1;
    p->f18 = func_0204B100(0x40, 8, heap);
    p->f1C = func_0204B034(d_021D8840, 1, heap);
    func_0204B258(p->f18, p->f1C);
    for (j = 0; j < 2; j++) {
        p->f20[j] = func_021A1DB4((u32)p->f18, a0, a1, a2, a3, (u32)p, a4, a5, heap);
    }
    p->f2C = func_020056A0((void (*)(void *))func_021A1C1C, p, 0x40);
    return p;
}

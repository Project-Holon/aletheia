/*
 * function: func_020155A0
 * address:  0x020155A0
 * packet:   pkt_02014D90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   G3i_FrustumW_    0x0207D760  arm
 *   G3_RotZ          0x0207D888  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *
 * mcss.c's per-cell quad drawer (wave 11, third lane on the family).  Its
 * three callers are the 0x02014D2C..0x020155A0 frame walker (0x020154D0,
 * 0x02015506, 0x02015562), which pass a cell record's six words as
 * x, y, width, height, s, t and a stack record as `pose`.  The body is a
 * straight run of G3 register writes: optional projection, texture palette
 * base, polygon attributes, translate / rotate / scale, one textured quad,
 * then (when the slot is not hidden and alpha is non-zero) the same quad
 * again with polygon id 1, and finally a depth step on *z.
 *
 * FOUR THINGS THE BYTES SETTLED, in the order they were found:
 *  1. FX_SinCosTable_ is declared WITHOUT const.  The second G3_RotZ
 *     re-reads pose->rot and both table entries after the call; const lets
 *     mwcc keep sin/cos across the call in two extra frame slots (0x58
 *     frame against the original's 0x50).  The index is recomputed too.
 *  2. G3_Translate / G3_Scale are the SDK inline functions, not three
 *     plain stores: the original loads pose->sx AND pose->sy (and *z)
 *     before the first register store, which only argument evaluation
 *     produces (58 -> 31 bytes).
 *  3. The second G3_TexPlttBase is written as the SDK's inline expression
 *     `addr >> (4 - (fmt == GX_TEXFMT_PLTT4))`; its 0/1 is a compiler
 *     temporary homed at sp+0x20, the LOWEST slot, which is how the slot
 *     order told a temporary from a declared local.  The alpha value goes
 *     through a block-local `a`, and polyId is declared last: slot order
 *     here follows creation order, not declaration order alone.
 *  4. The depth pointer is `u32 *`, not `fx32 *`.  With a signed pointee
 *     the two +-0x100 tails pick the other register for the 0x140 field
 *     offset the original re-uses to build 0x100 (`subs r0, #0x40`); 22
 *     bytes over four tails that 547 hill and 2000 anneal permuter compiles
 *     could not move, closed by the declaration alone (wave-10 lesson).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef s32 fx32;
typedef volatile u32 vu32;

extern void G3i_FrustumW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f,
                          fx32 scaleW, int draw, void *mtx);
extern void G3_RotZ(fx32 s, fx32 c);
extern s16 FX_SinCosTable_[];

#define REG_MTX_MODE     (*(vu32 *)0x04000440)
#define REG_MTX_RESTORE  (*(vu32 *)0x04000450)
#define REG_MTX_SCALE    (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS    (*(vu32 *)0x04000470)
#define REG_TEXCOORD     (*(vu32 *)0x04000488)
#define REG_VTX_16       (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR (*(vu32 *)0x040004A4)
#define REG_TEXPLTT_BASE (*(vu32 *)0x040004AC)
#define REG_BEGIN_VTXS   (*(vu32 *)0x04000500)
#define REG_END_VTXS     (*(vu32 *)0x04000504)

static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}

/* fx32 texture coordinate to the 12.4 halfword TEXCOORD wants */
#define ST(x) ((u32)(u16)(s16)((x) >> 8))

struct McssSys {
    u8   pad00[0x2c];
    u32  f2c_0 : 1;
    u32  f2c_1 : 1;     /* far plane 512 vs 1024, depth step 0x100 vs 0x400 */
    u32  f2c_r : 30;
    u8   pad30[0x48 - 0x30];
    s32  f48;           /* depth step override when non-zero */
};

struct Cell  { s16 f00; s16 f02; s16 f04; s16 f06; };
struct Frame { u32 f00; struct Cell *f04; };
struct Anim  { u32 f00; struct Frame *f04; };

struct McssWork {
    u8   pad00[0x78];
    struct Anim *f78;
    u8   pad7c[0xc0 - 0x7c];
    s32  fc0;           /* texture format; 2 = GX_TEXFMT_PLTT4 */
    u32  fc4;
    u32  fc8;           /* palette base */
    u8   padcc[0x140 - 0xcc];
    u32  b0  : 8;       /* the flag word, docs/families/mcss.h */
    u32  b1  : 6;
    u32  b4  : 9;
    u32  b23 : 1;
    u32  b24 : 6;
    u32  b30 : 1;
    u32  b31 : 1;
};

struct Pose {
    u16  f00;
    u16  rot;
    fx32 sx;
    fx32 sy;
    s16  ox;
    s16  oy;
};

struct Tex { s32 fmt; u32 f04; u32 plttBase; };

void func_020155A0(struct McssSys *sys, struct McssWork *w, fx32 x, fx32 y,
                   fx32 width, fx32 height, fx32 s, fx32 t,
                   struct Pose *pose, u16 *frame, struct Tex *tex, int id,
                   int proj, u32 *z, u8 flip)
{
    u32 alpha;
    fx32 tx, ty;
    u32 st0, st1, st2, st3;
    u32 sa, ta, sb, tb;
    int idx;
    int polyId;

    {
        u32 a = w->b4;
        if (a == 0x20) {
            a = w->b0 >> 1;
        }
        alpha = (u8)a;
    }
    if (w->b0 == 0x1f || w->b31) {
        polyId = 0;
    } else {
        polyId = id;
        if (polyId > 0x3f) {
            polyId = 0x3f;
        }
    }

    if (proj != 0) {
        G3i_FrustumW_(6 << 16, -6 << 16, -8 << 16, 8 << 16, 0x1000,
                      (sys->f2c_1 ? 0x200 : 0x400) << 12, 0x1000, 1, 0);
        REG_MTX_MODE = 2;
    }
    REG_MTX_RESTORE = 0x1d;

    REG_TEXPLTT_BASE = w->fc8 >> (4 - (w->fc0 == 2));
    REG_POLYGON_ATTR = (w->b0 << 16) | (0xc0 | (polyId << 24));

    tx = (w->f78->f04[*frame].f04[id].f02 + pose->ox) << 8;
    ty = -(w->f78->f04[*frame].f04[id].f04 + pose->oy) << 8;
    G3_Translate(tx, ty, *z);
    idx = pose->rot >> 4;
    G3_RotZ(-FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);

    if (flip == 0) {
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
    } else if (flip & 1) {
        G3_Scale(-pose->sx, pose->sy, 0x1000);
        G3_Translate(-x, y, 0);
        G3_Scale(width, height, 0x1000);
        G3_Translate(-0x100, 0, 0);
        s = 0x200000 - s - width;
    }

    REG_BEGIN_VTXS = 1;
    ta = ST(t) << 16;
    sa = ST(s);
    st0 = sa | ta;
    REG_TEXCOORD = st0;
    REG_VTX_16 = 0;
    REG_VTX_16 = 0;
    tb = ST(t + height) << 16;
    st1 = sa | tb;
    REG_TEXCOORD = st1;
    REG_VTX_16 = 0xFF000000;
    REG_VTX_16 = 0;
    sb = ST(s + width);
    st2 = tb | sb;
    REG_TEXCOORD = st2;
    REG_VTX_16 = 0xFF000100;
    REG_VTX_16 = 0;
    st3 = sb | ta;
    REG_TEXCOORD = st3;
    REG_VTX_16 = 0x100;
    REG_VTX_16 = 0;
    REG_END_VTXS = 0;

    REG_MTX_MODE = 0;
    REG_MTX_RESTORE = 0;
    REG_MTX_MODE = 2;
    REG_MTX_RESTORE = 0x1e;

    if (!w->b23 && alpha != 0) {
        REG_TEXPLTT_BASE = tex->plttBase >> (4 - (tex->fmt == 2));
        REG_POLYGON_ATTR = (alpha << 16) | 0x010000C0;
        G3_Translate(tx, ty, 0);
        idx = pose->rot >> 4;
        G3_RotZ(-FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
        REG_BEGIN_VTXS = 1;
        REG_TEXCOORD = st0;
        REG_VTX_16 = 0;
        REG_VTX_16 = 0;
        REG_TEXCOORD = st1;
        REG_VTX_16 = 0xFF000000;
        REG_VTX_16 = 0;
        REG_TEXCOORD = st2;
        REG_VTX_16 = 0xFF000100;
        REG_VTX_16 = 0;
        REG_TEXCOORD = st3;
        REG_VTX_16 = 0x100;
        REG_VTX_16 = 0;
        REG_END_VTXS = 0;
    }

    if (proj == 0) {
        if (sys->f48 == 0) {
            *z -= ((w->b0 != 0x1f) | w->b30) ? -0x100 : 0x100;
        } else {
            *z -= ((w->b0 != 0x1f) | w->b30) ? -sys->f48 : sys->f48;
        }
    } else if (sys->f2c_1) {
        *z -= ((w->b0 != 0x1f) | w->b30) ? -0x100 : 0x100;
    } else {
        *z -= ((w->b0 != 0x1f) | w->b30) ? -0x400 : 0x400;
    }
}

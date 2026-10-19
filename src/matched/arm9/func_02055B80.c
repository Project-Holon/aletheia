/*
 * function: SPL_EMITTER_UpdateFrameEx
 * address:  0x02055B80
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * symbols:
 *   MTX_MultVec43        0x0207BC08  arm
 *   func_0207D918        0x0207D918  arm
 *   SPLUtil_DrawXYPlane        0x020565C8  arm
 *   func_02055B80_Verts  0x020A1B38  data
 * status:   EXACT
 *
 * Handler row of the rig dispatch (SPL_EMITTER_UpdateSubX / SPL_EMITTER_UpdateSubB pool rows;
 * docs/families/cluster_02052F58.h): a Z-rotation billboard.  Same top as
 * SPL_EMITTER_UpdateFrameMain (POLYGON_ATTR, the three-way scale switch), then instead of
 * the basis hooks it transforms the particle position by the current matrix
 * (MTX_MultVec43, MTX_MultVec43), reads sin/cos from the Verts table at
 * s->f20 >> 4, fills a 4x3 matrix ROW-major { cs*x, sn*x, 0 ; -sn*y, cs*y, 0 ;
 * 0, 0, 1 ; t }, loads it (identity + [translate FIFO] + func_0207D918), mixes
 * the colour and calls the quad emitter SPLUtil_DrawXYPlane DIRECTLY.
 *
 * LOAD-BEARING SHAPES (wave 8):
 *   1. SubC->f30 is read into a local BEFORE the 0x040004A4 store, and
 *      obj->f44 likewise (the image loads both there).
 *   2. `a64 = (s64)(s32)a;` comes BEFORE the scale product, and the product
 *      is written `(s32)((a64 * sc + 0x800) >> 12)` on it.  The FX_Mul(a, sc)
 *      inline is 9 bytes out (the lo/hi halves swap registers), and the
 *      permuter's hill pass (399 singles) could not move it.
 *   3. -proc arm946e, NOT the arm7tdmi recorded in docs/notes/
 *      pkt_02055498.c.txt (that note's 740-out body was measured there).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_UpdateFrameEx.c \
 *       --func SPL_EMITTER_UpdateFrameEx --addr 0x02055B80 --arm --cc ../1.2/sp2
 */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed long long s64;
typedef unsigned char u8;

struct VecFx32 { s32 x, y, z; };
struct MtxFx43 { s32 m[12]; };

struct Bf16 {
    u16 b0 : 5;
    u16 b5 : 5;
    u16 b10 : 6;
};

struct BfSel {
    u32 lo : 6;
    u32 sel : 1;
    u32 hi : 25;
};

struct BfZero {
    u32 f0 : 17;
    u32 sel2 : 2;
    u32 sel1 : 1;
    u32 f20 : 3;
    u32 flag : 1;
    u32 f24 : 8;
};

struct Bf28 {
    u32 lo : 8;
    u32 k : 16;
    u32 mid : 4;
    u32 sel : 3;
    u32 hi : 1;
};

struct SubD {
    struct Bf16 hw;
    u8 pad02[0x0e];
    struct BfSel f10;
};

struct SubC {
    struct BfZero f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8 pad10[0x20];
    s16 f30;
    u8 pad32[0x16];
    struct Bf28 f48;
    u8 pad4c[0x04];
    s16 f50;
    s16 f52;
};

struct SubX {
    struct SubC *f00;
    u8 pad04[0x10];
    struct SubD *f14;
};

struct SubB {
    u8 pad00[0x20];
    struct SubX *f20;
    u8 pad24[0x4e];
    u16 f72;
    u8 pad74[0x04];
    s16 f78;
    s16 f7a;
    s16 f7c;
    s16 f7e;
};

struct Obj {
    u8 pad00[0x3c];
    u32 f3c;
    struct SubB *f40;
    struct MtxFx43 *f44;
};

struct S {
    u8 pad00[0x08];
    struct VecFx32 p1;
    struct VecFx32 p2;
    u16 f20;
    u8 pad22[0x0c];
    struct Bf16 w;
    s32 f30;
    s16 f34;
    u16 f36;
    u32 f38;
    u32 f3c;
    u32 f40;
};

struct Frame {
    struct VecFx32 t;
    struct MtxFx43 m;
};

extern const s16 func_02055B80_Verts[];
extern void MTX_MultVec43(const void *v, const void *m, void *out);
extern void func_0207D918(const void *);
extern void SPLUtil_DrawXYPlane(s32, s32, s32, s32);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void SPL_EMITTER_UpdateFrameEx(struct Obj *obj, struct S *s)
{
    struct Frame f;
    struct SubC *p;
    struct MtxFx43 *mtx;
    s32 n;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 i;
    s32 sn;
    s32 cs;
    s32 sc;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    sc = obj->f40->f20->f00->f30;
    mtx = obj->f44;
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    a = s->f30;
    a64 = (s64)(s32)a;
    n = (s32)((a64 * sc + 0x800) >> 12);
    x = n;
    y = a;
    p = obj->f40->f20->f00;
    switch (p->f48.sel) {
    case 0:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    default:
        break;
    }

    if (p->f00.flag == 0) {
        f.t.x = s->p1.x + s->f38;
        f.t.y = s->p1.y + s->f3c;
        f.t.z = s->p1.z + s->f40;
        MTX_MultVec43(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
        sn = func_02055B80_Verts[2 * i];
        cs = func_02055B80_Verts[2 * i + 1];
        f.m.m[0] = FX_Mul(cs, x);
        f.m.m[1] = FX_Mul(sn, x);
        f.m.m[2] = 0;
        f.m.m[3] = FX_Mul(-sn, y);
        f.m.m[4] = FX_Mul(cs, y);
        f.m.m[5] = 0;
        f.m.m[6] = 0;
        f.m.m[7] = 0;
        f.m.m[8] = 0x1000;
        f.m.m[9] = f.t.x;
        f.m.m[10] = f.t.y;
        f.m.m[11] = f.t.z;
        *(volatile u32 *)0x04000454 = 0;
        func_0207D918(&f.m);
    } else {
        f.t.x = s->p1.x + s->f38 - p->f04;
        f.t.y = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.t.z = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        MTX_MultVec43(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
        sn = func_02055B80_Verts[2 * i];
        cs = func_02055B80_Verts[2 * i + 1];
        f.m.m[0] = FX_Mul(cs, x);
        f.m.m[1] = FX_Mul(sn, x);
        f.m.m[2] = 0;
        f.m.m[3] = FX_Mul(-sn, y);
        f.m.m[4] = FX_Mul(cs, y);
        f.m.m[5] = 0;
        f.m.m[6] = 0;
        f.m.m[7] = 0;
        f.m.m[8] = 0x1000;
        f.m.m[9] = f.t.x;
        f.m.m[10] = f.t.y;
        f.m.m[11] = f.t.z;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(&f.m);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    SPLUtil_DrawXYPlane(obj->f40->f7c, obj->f40->f7e, 0, 0);
}

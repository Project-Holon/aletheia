/*
 * file:     button_man_p10.c
 * function: func_02055FD4
 * address:  0x02055FD4
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * symbols:
 *   func_0207BC08        0x0207BC08  arm
 *   func_0207D918        0x0207D918  arm
 *   func_020565C8        0x020565C8  arm
 *   func_02055FD4_Verts  0x020A1B38  data
 * status:   EXACT
 * note:     EXACT* because the follower at 0x02056420 is the unlabelled leaf
 *           Rig_Hooks[0] (the +Y rotation basis builder, 64 bytes, no lr
 *           save); every byte of this function and its 20-byte pool compares
 *           identical.  Seed 0x02056420 into layout/function_starts.txt.
 *
 * Twin of func_02055B80 (same Z-rotation billboard), transcribed from it.
 * Differences read off the listing:
 *   - everything the tail needs is read into locals BEFORE the 0x040004A4
 *     store: SubC->f30, the f48 scale selector (narrowed to a u8 -- the
 *     `and #0xff`), SubB->f72, s->f34, s->f36 and obj->f44;
 *   - the scale dispatch is an if / else-if / else chain on that u8, not a
 *     switch: the third arm is the ELSE (it serves kind 2 and every other
 *     value), as docs/notes/pkt_02055498.c.txt already read it;
 *   - the quad emitter gets SubB f78/f7a and SubC f50/f52.
 * `sc = p->f30;` must come BEFORE `sel = p->f48.sel;` -- found by
 * tools/permuter.py --mode hill as temp(tmp=p->f30) from a 69-byte residue,
 * applied here as the plain statement order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02055FD4.c \
 *       --func func_02055FD4 --addr 0x02055FD4 --arm --cc ../1.2/sp2
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

extern const s16 func_02055FD4_Verts[];
extern void func_0207BC08(const void *v, const void *m, void *out);
extern void func_0207D918(const void *);
extern void func_020565C8(s32, s32, s32, s32);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_02055FD4(struct Obj *obj, struct S *s)
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
    s32 k34;
    u8 sel;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    p = obj->f40->f20->f00;
    sc = p->f30;
    sel = p->f48.sel;
    c2 = obj->f40->f72;
    k34 = s->f34;
    c1 = s->f36;
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
    if (sel == 0) {
        x = (s32)(((s64)n * k34 + 0x800) >> 12);
        y = (s32)(((a64 * k34) + 0x800) >> 12);
    } else if (sel == 1) {
        x = (s32)(((s64)n * k34 + 0x800) >> 12);
    } else {
        y = (s32)(((a64 * k34) + 0x800) >> 12);
    }

    p = obj->f40->f20->f00;
    if (p->f00.flag == 0) {
        f.t.x = s->p1.x + s->f38;
        f.t.y = s->p1.y + s->f3c;
        f.t.z = s->p1.z + s->f40;
        func_0207BC08(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
        sn = func_02055FD4_Verts[2 * i];
        cs = func_02055FD4_Verts[2 * i + 1];
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
        func_0207BC08(&f.t, mtx, &f.t);
        i = (s32)s->f20 >> 4;
        sn = func_02055FD4_Verts[2 * i];
        cs = func_02055FD4_Verts[2 * i + 1];
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

    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    p = obj->f40->f20->f00;
    func_020565C8(obj->f40->f78, obj->f40->f7a, p->f50, p->f52);
}

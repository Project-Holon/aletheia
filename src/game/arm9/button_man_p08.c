/*
 * file:     button_man_p08.c
 * function: func_02054718
 * address:  0x02054718
 * packet:   pkt_0205429C
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02054718_Verts  0x020A1B38  data
 *   func_02054718_Hooks  0x020A7FE4  data
 *   func_02054718_Hooks2 0x020A7FDC  data
 *   func_0207B5F4        0x0207B5F4  thumb
 *   func_0207B9F0        0x0207B9F0  arm
 *   func_0207D8E0        0x0207D8E0  arm
 *   func_0207D918        0x0207D918  arm
 *
 * Member of the 1.2-pinned 3D rig family (docs/FRONTEND-PINS.md); the
 * original mixes a register `blx rN` (0x020547C0, 0x02054A3C) with an
 * ARMv4T-style `pop {r4, r5, r6, r7, r8, lr}; bx lr` return (0x02054770,
 * 0x02054A44), which no dsi build can emit under -proc arm946e.
 *
 * -proc is arm946e, from the bytes, not from layout/proc_hints.txt: the
 * hint file infers arm7tdmi for pkt_0205429C from its pop-lr epilogues, but
 * under `../1.2/sp2 -proc arm7tdmi` this row compiles to 856 bytes with 640
 * concrete bytes differing (and emits `mov lr, pc; bx rN` where the image
 * has `blx rN`); at arm946e it is 848/848 EXACT.
 *
 * Same source shape as func_02053E1C (docs/notes/pkt_02053218.c.txt) minus
 * the basis-construction half.
 *
 * THE FOUR SOURCE SHAPES THE RESIDUE TURNED ON (wave r8, all measured; the
 * same four take func_02054A68 and func_0205429C to EXACT as well):
 *   1. 0x040004A4: the source order of the `|` chain decides which temporary
 *      claims r0.  The b10 term must be written FIRST --
 *      `v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);`
 *      With `obj->f3c | 0xc0` first the first difference is at +0x14
 *      (obj->f3c -> r1 where the image has r0) and the whole function is
 *      100 concrete bytes out.
 *   2. The scale multiply is `(s64)a * res->f30`, not `(s64)res->f30 * a`:
 *      only with `a` on the left does the smull's product pair land in
 *      r6:r1 as the image has it.
 *   3. `case 0` runs `x = n * s->f34` BEFORE `y = a64 * s->f34`.
 *   4. The three 0x04000470 FIFO stores go through named locals loaded in
 *      REVERSE field order (`qc = p->f0c; q8 = p->f08; q4 = p->f04;`, all
 *      three declared before `s32 c2;`) and stored in forward order.
 *      Written as three direct stores the compiler interleaves load/store
 *      and the row is 22 concrete bytes out.
 *
 * Addresses are Black-image addresses.
 */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed long long s64;
typedef unsigned char u8;

struct VecFx32 { s32 x, y, z; };
struct MtxFx33 { s32 m[9]; };
struct MtxFx43 { s32 m[12]; };

struct Bf16 {
    u16 b0 : 5;
    u16 b5 : 5;
    u16 b10 : 6;
};

struct BfHw {
    u16 a : 9;
    u16 sel2 : 2;
    u16 sel1 : 1;
    u16 b : 4;
};

struct BfSel {
    u32 lo : 6;
    u32 sel : 1;
    u32 hi : 25;
};

struct Bf23 {
    u32 lo : 23;
    u32 sel : 1;
    u32 hi : 8;
};

struct Bf28 {
    u32 lo : 28;
    u32 sel : 3;
    u32 hi : 1;
};

struct SubD {
    struct BfHw hw;
    u8 pad02[0x0e];
    struct BfSel f10;
};

struct SubC {
    struct Bf23 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8 pad10[0x20];
    s16 f30;
    u8 pad32[0x16];
    struct Bf28 f48;
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
    u8 pad74[0x08];
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
    struct MtxFx43 m1;
    struct MtxFx43 m2;
    struct MtxFx43 m3;
};

extern const s16 func_02054718_Verts[];
extern u32 (*const func_02054718_Hooks[])(s32, s32, void *);
extern u32 (*const func_02054718_Hooks2[])(s32, s32, s32, s32);

extern u32 func_0207B5F4(void *, s32, s32, s32);
extern void func_0207B9F0(const void *, const void *, void *);
extern void func_0207D8E0(const void *);
extern void func_0207D918(const void *);

void func_02054718(struct Obj *obj, struct S *s)
{
    struct Frame f;
    struct SubC *p;
    s32 n;
    s32 e;
    s32 i;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->f20 >> 4;
    func_02054718_Hooks[obj->f40->f20->f14->hw.sel2]
        (func_02054718_Verts[2 * i], func_02054718_Verts[2 * i + 1], &f.m2);

    a = s->f30;
    n = (s32)(((s64)a * obj->f40->f20->f00->f30 + 0x800) >> 12);
    x = n;
    y = a;
    a64 = (s64)(s32)a;
    switch (obj->f40->f20->f00->f48.sel) {
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

    func_0207B5F4(&f.m3, x, y, y);
    func_0207B9F0(&f.m2, &f.m3, &f.m1);

    if (obj->f40->f20->f00->f00.sel == 0) {
        f.m1.m[9] = s->p1.x + s->f38;
        f.m1.m[10] = s->p1.y + s->f3c;
        f.m1.m[11] = s->p1.z + s->f40;
        func_0207D8E0(obj->f44);
        func_0207D918(&f.m1);
    } else {
        f.m1.m[9] = s->p1.x + s->f38 - obj->f40->f20->f00->f04;
        f.m1.m[10] = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.m1.m[11] = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(obj->f44);
        func_0207D918(&f.m1);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    e = 0;
    func_02054718_Hooks2[obj->f40->f20->f14->hw.sel1]
        (obj->f40->f7c, obj->f40->f7e, e, e);
}

/*
 * file:     unit_02063784.c
 * unit:     yes
 * function: func_02063784, func_02063790, func_020637AC, func_020637B4, func_020637BC, func_020637D4, func_020637F4, func_02063800, func_0206380C, func_02063828, func_02063A54, func_02063C80, func_02063E54, func_02063F4C
 * address:  0x02063784
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DC_FlushRange   0x020862F0  arm
 *   GX_BeginLoadTex 0x0207F7A0  arm
 *   GX_LoadTex      0x0207F7FC  arm
 *   GX_EndLoadTex   0x0207F9B4  arm
 *   GX_LoadOBJ      0x0207E780  arm
 *   GXS_LoadOBJ     0x0207E804  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207F47C  0x0207F47C  arm
 *   func_0207F4C4  0x0207F4C4  arm
 *   func_0207F560  0x0207F560  arm
 *   func_0207E51C  0x0207E51C  arm
 *   func_0207F6A8  0x0207F6A8  arm
 *   func_0207F6C0  0x0207F6C0  arm
 *   func_0207F754  0x0207F754  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207FA0C  0x0207FA0C  arm
 *   func_0207FA40  0x0207FA40  arm
 *   func_0207FADC  0x0207FADC  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Res {
    u16 f0;
    u16 f2;
    int f4;
    u32 f8;
    int fc;
    u32 f10;
    void *f14;
};

struct Out {
    int f0, f4, f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    u32 f20;
};

typedef struct UnkSelf02063E54 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
} UnkSelf02063E54;

typedef struct UnkOut02063E54 {
    u32 f0;
    u32 f4;
} UnkOut02063E54;

typedef struct Self02063F4C {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
} Self02063F4C;

typedef struct Out02063F4C {
    u32 f0;
    u32 f4;
} Out02063F4C;

typedef struct List02063F4C {
    u16  count;
    u16 *items;
} List02063F4C;

extern void DC_FlushRange(void *p, u32 n);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *src, u32 off, u32 n);
extern void GX_EndLoadTex(void);
extern void GX_LoadOBJ(void *src, u32 off, u32 n);
extern void GXS_LoadOBJ(void *src, u32 off, u32 n);
extern void func_020862F0(u32 a, u32 b);
extern void func_0207F47C(u32 a);
extern void func_0207F4C4(u32 a, u32 b, u32 c);
extern void func_0207F560(void);
extern void func_0207E51C(u32 a, u32 b, u32 c);
extern void func_0207F6A8(u32 a);
extern void func_0207F6C0(u32 a, u32 b, u32 c);
extern void func_0207F754(void);
extern void func_0207E5D0(u32 a, u32 b, u32 c);
extern void func_0207FA0C(void);
extern void func_0207FA40(u32 a, u32 b, u32 c);
extern void func_0207FADC(void);
int func_02063784(unsigned short *p, int i);
void func_02063790(u32 *p);
void func_020637AC(int *p, int i, int v);
int func_020637B4(int *p, int i);
int func_020637BC(const u32 *p, u32 i);
void func_020637D4(u32 *p);
void func_020637F4(char *p, int i, int v);
int func_02063800(char *p, int i);
int func_0206380C(char *p, int i);
void func_02063828(struct Res *r, u32 dst, int mode, struct Out *out);
void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
void func_02063C80(struct Res *r, u32 dst, int mode, struct Out *out);
void func_02063E54(UnkSelf02063E54 *self, u32 a1, int sel, UnkOut02063E54 *out);
void func_02063F4C(Self02063F4C *self, List02063F4C *list, u32 base, int sel, Out02063F4C *out);





int func_02063784(unsigned short *p, int i){ return p[i]; }






void func_02063790(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i] = 0xffffffff;
    }
}





void func_020637AC(int *p, int i, int v){ p[i] = v; }




int func_020637B4(int *p, int i){ return p[i]; }




/*
 * Slot-occupied test of the func_0206380C accessor family: the word at
 * p[i] is not the sentinel -1.  The register-held sentinel tell
 * (docs/FRONTEND-PINS.md): the image materialises `mvn r0, #0` at
 * 0x020637C0 and compares `cmp r1, r0` at 0x020637C4; every dsi 1.x front
 * end folds the constant to `cmn r0, #1` (20 bytes, 12 out, ten spellings
 * measured by earlier lanes).  Under ../2.0/sp2 (also sp2p2, 2.0 base and
 * ../1.2/sp4) the same C is 24 bytes, 0 mismatches.
 */
int func_020637BC(const u32 *p, u32 i)
{
    return p[i] != 0xffffffff;
}





void func_020637D4(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i + 2] = 0xffffffff;
    }
}




void func_020637F4(char *p, int i, int v){ *(int *)(p + i * 4 + 8) = v; }



int func_02063800(char *p, int i){ return *(int *)(p + i * 4 + 8); }





/*
 * Neighbour of func_02063800 (same accessor family): that one returns the
 * slot's raw word, this one reports whether the slot is occupied, i.e. not
 * the sentinel -1.
 */
int func_0206380C(char *p, int i){ int v = *(int *)(p + i * 4 + 8); int s = -1; return v != s; }






/*
 * Upload one VRAM resource: optionally repoint the 2D/3D VRAM control word,
 * flush the source range, hand it to the matching GX loader (3D texture,
 * main OBJ, sub OBJ), then fill the caller's descriptor.  When f8 (the bank
 * control word) is zero the two halfword dimensions are translated from
 * pixel sizes (1,2,4,8,0x10,0x20) to GX size codes 0..5; otherwise they are
 * stored raw.
 *
 * 1.1p1 CSEs the shared zero into a callee-saved register (costing r8 and a
 * six-register frame) and cross-jumps the two VRAM-control arms, giving 532
 * bytes against the original's 556; under ../2.0/sp2 the same C is 556
 * bytes, 0 mismatches.  See docs/FRONTEND-PINS.md.
 */
void func_02063828(struct Res *r, u32 dst, int mode, struct Out *out)
{
    u32 bank = r->f8;

    switch (mode) {
    case 0:
        break;
    case 1:
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | bank;
        break;
    case 2:
        *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFCFFFEF) | bank;
        break;
    }
    DC_FlushRange(r->f14, r->f10);
    switch (mode) {
    case 0:
        GX_BeginLoadTex();
        GX_LoadTex(r->f14, dst, r->f10);
        GX_EndLoadTex();
        break;
    case 1:
        GX_LoadOBJ(r->f14, dst, r->f10);
        break;
    case 2:
        GXS_LoadOBJ(r->f14, dst, r->f10);
        break;
    }
    if (r->f8 == 0) {
        int a, b;
        switch (r->f2) {
        case 1:    a = 0; break;
        case 2:    a = 1; break;
        case 4:    a = 2; break;
        case 8:    a = 3; break;
        case 0x10: a = 4; break;
        case 0x20: a = 5; break;
        default:   a = 0; break;
        }
        out->fc = a;
        switch (r->f0) {
        case 1:    b = 0; break;
        case 2:    b = 1; break;
        case 4:    b = 2; break;
        case 8:    b = 3; break;
        case 0x10: b = 4; break;
        case 0x20: b = 5; break;
        default:   b = 0; break;
        }
        out->f10 = b;
    } else {
        out->fc = r->f2;
        out->f10 = r->f0;
    }
    out->f14 = r->f4;
    out->f18 = 0;
    out->f1c = 1;
    out->f20 = r->f8;
    func_020637AC((int *)out, mode, dst);
}






void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out)
{
    u32 bank = r->f8;

    switch (mode) {
    case 0:
        break;
    case 1:
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | bank;
        break;
    case 2:
        *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFCFFFEF) | bank;
        break;
    }
    DC_FlushRange(r->f14, r->f10);
    switch (mode) {
    case 0:
        GX_BeginLoadTex();
        GX_LoadTex(r->f14, dst, r->f10);
        GX_EndLoadTex();
        break;
    case 1:
        GX_LoadOBJ(r->f14, dst, r->f10);
        break;
    case 2:
        GXS_LoadOBJ(r->f14, dst, r->f10);
        break;
    }
    if (r->f8 == 0) {
        int a, b;
        switch (r->f2) {
        case 1:    a = 0; break;
        case 2:    a = 1; break;
        case 4:    a = 2; break;
        case 8:    a = 3; break;
        case 0x10: a = 4; break;
        case 0x20: a = 5; break;
        default:   a = 0; break;
        }
        out->fc = a;
        switch (r->f0) {
        case 1:    b = 0; break;
        case 2:    b = 1; break;
        case 4:    b = 2; break;
        case 8:    b = 3; break;
        case 0x10: b = 4; break;
        case 0x20: b = 5; break;
        default:   b = 0; break;
        }
        out->f10 = b;
    } else {
        out->fc = r->f2;
        out->f10 = r->f0;
    }
    out->f14 = r->f4;
    out->f18 = 0;
    out->f1c = 1;
    out->f20 = r->f8;
    func_020637AC((int *)out, mode, dst);
}






/*
 * Upload one VRAM resource: optionally repoint the 2D/3D VRAM control word,
 * flush the source range, then fill the caller's descriptor.  Sibling of
 * func_02063828/func_02063A54 with the GX upload itself left out (the
 * caller has already moved the bytes).  When f8 (the bank
 * control word) is zero the two halfword dimensions are translated from
 * pixel sizes (1,2,4,8,0x10,0x20) to GX size codes 0..5; otherwise they are
 * stored raw.
 *
 * 1.1p1 CSEs the shared zero into a callee-saved register (costing r8 and a
 * six-register frame) and cross-jumps the two VRAM-control arms, giving 444
 * bytes against the original's 468; under ../2.0/sp2 the same C is 468
 * bytes, 0 mismatches.  See docs/FRONTEND-PINS.md.
 */
void func_02063C80(struct Res *r, u32 dst, int mode, struct Out *out)
{
    u32 bank;

    DC_FlushRange(r->f14, r->f10);
    bank = r->f8;
    switch (mode) {
    case 0:
        break;
    case 1:
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | bank;
        break;
    case 2:
        *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFCFFFEF) | bank;
        break;
    }
    if (r->f8 == 0) {
        int a, b;
        switch (r->f2) {
        case 1:    a = 0; break;
        case 2:    a = 1; break;
        case 4:    a = 2; break;
        case 8:    a = 3; break;
        case 0x10: a = 4; break;
        case 0x20: a = 5; break;
        default:   a = 0; break;
        }
        out->fc = a;
        switch (r->f0) {
        case 1:    b = 0; break;
        case 2:    b = 1; break;
        case 4:    b = 2; break;
        case 8:    b = 3; break;
        case 0x10: b = 4; break;
        case 0x20: b = 5; break;
        default:   b = 0; break;
        }
        out->f10 = b;
    } else {
        out->fc = r->f2;
        out->f10 = r->f0;
    }
    out->f14 = r->f4;
    out->f18 = 0;
    out->f1c = 1;
    out->f20 = r->f8;
    func_020637AC((int *)out, mode, dst);
}




void func_02063E54(UnkSelf02063E54 *self, u32 a1, int sel, UnkOut02063E54 *out)
{
    u32 a = self->fC;
    u32 b = self->f8;

    func_020862F0(a, b);

    switch (sel) {
    case 1:
        if (self->f4 != 0) {
            func_0207F47C(self->f4);
            func_0207F4C4(a, a1, b);
            func_0207F560();
        } else {
            func_0207E51C(a, a1, b);
        }
        break;
    case 2:
        if (self->f4 != 0) {
            func_0207F6A8(self->f4);
            func_0207F6C0(a, a1, b);
            func_0207F754();
        } else {
            func_0207E5D0(a, a1, b);
        }
        break;
    case 0:
        func_0207FA0C();
        func_0207FA40(a, a1, b);
        func_0207FADC();
        break;
    }

    out->f0 = self->f0;
    out->f4 = self->f4;
    func_020637F4((char *)out, sel, a1);
}



/*
 * The LIST form of src/matched/func_02063E54.c: the same three-arm dispatch on
 * `sel`, the same twelve callees in the same order, the same
 * `out->f0 = self->f0; out->f4 = self->f4; func_020637F4(out, sel, base);`
 * tail -- but run once per entry of a (count, u16 *items) list instead of once
 * per call.  Reading it as "func_02063E54 with a loop around it" is what made
 * the body writable at all; every callee declaration below is lifted unchanged
 * from that already-exact sibling.
 *
 * THE ELEMENT SIZE, and what `self->f0 == 3` means.  Both operands of the
 * per-entry address arithmetic are scaled by one `step` that is 0x20 when
 * self->f0 == 3 and 0x200 otherwise (`moveq r8, #0x20` / `movne r8, #0x200`,
 * one predicated pair at 0x02063F68 and 0x02063F80 that the two `mul`s then
 * consume).  self->f0 is also the word copied to out->f0, so it is a format
 * code and not a count -- the same field func_02063E54 copies out untouched.
 *
 * FOUR THINGS THE BYTES FORCED, in the order they cost time:
 *
 *   1. The two products are NAMED LOCALS computed before func_020862F0, not
 *      expressions at the six call sites.  Writing `a + step * i` inline gives
 *      `mla r0, r6, r4, r5` repeated in every arm where the image has one
 *      `mul r4, r8, r7` / `mul r6, r8, r0` pair at 0x02063FA8 and a plain
 *      `add r0, r5, r4` per arm -- 325 concrete bytes, and 24 bytes of size.
 *
 *   2. The loop is `if (n != 0) { do { ... } while (n > i); }`, not a `while`.
 *      The image tests the count once with `movs r0, r0 / beq #0x2064080`
 *      before the body and then closes with `cmp r0, r1, lsr #16 / bhi` at the
 *      bottom; `i` is a u16, which is what the `lsl #0x10` / `lsr #0x10` pair
 *      around the increment is.
 *
 *   3. DECLARATION ORDER.  `d` (the destination product) must be declared
 *      BEFORE `a` (the self->fC base).  Declared the other way round the two
 *      swap registers, giving `mul r5, r8, r7` / `mov r0, r4` /
 *      `add r0, r4, r5` for the image's `mul r4, r8, r7` / `mov r0, r5` /
 *      `add r0, r5, r4` -- 14 concrete bytes and nothing else, exactly
 *      docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 *   4. The `default:` arm of the switch is explicit and empty, the same tell
 *      as src/matched/func_02072AA0.c: without it the last case is
 *      if-converted into the compare chain instead of getting its own `beq`.
 *
 *   5. THE `../2.0/sp2` PIN.  With all of the above right, dsi/1.1p1 is
 *      size-exact at 356 bytes with exactly ONE concrete byte out, and the
 *      permuter cannot move it: `--explain` reports no register substitution
 *      at all, `--mode hill --budget 800 --types` exhausts 271 single
 *      mutations with no improvement, and `--mode anneal --budget 2000 --types`
 *      compiles 2000 candidates and plateaus twice at the same point.  The
 *      byte is the first half of the step selection: the image predicates BOTH
 *      arms (`moveq r8, #0x20` then `movne r8, #0x200`), 1.1p1 makes the first
 *      unconditional (`mov r8, #0x20` then `movne r8, #0x200`).  Neither the
 *      ternary, the spelled-out if/else, nor the initialise-then-override form
 *      moves it, because under 1.1p1 the variable is provably dead before the
 *      selection and the front end drops the redundant predicate.  ../2.0/sp2
 *      keeps both predicates and is byte-exact; ../1.2/sp2 is 360 bytes.
 *      Five of this cluster's seven other matched rows are already 2.0
 *      (func_0206380C, func_02063828, func_02063A54, func_02063C80,
 *      func_02063E54 is 1.1p1) -- see docs/families/cluster_020637F4.h.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02063F4C.c \
 *       --func func_02063F4C --addr 0x02063F4C --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 356 = original 356, 13 of 13 sites resolved
 */
void func_02063F4C(Self02063F4C *self, List02063F4C *list, u32 base, int sel,
                   Out02063F4C *out)
{
    u32 step;
    u16 n;
    u16 i;
    u32 d;
    u32 a;
    u32 t;

    step = (self->f0 == 3) ? 0x20 : 0x200;
    n = list->count;
    i = 0;
    if (n != 0) {
        do {
            a = self->fC;
            d = step * i;
            t = step * list->items[i];
            func_020862F0(a, self->f8);
            switch (sel) {
            case 1:
                if (self->f4 != 0) {
                    func_0207F47C(self->f4);
                    func_0207F4C4(a + d, base + t, step);
                    func_0207F560();
                } else {
                    func_0207E51C(a + d, base + t, step);
                }
                break;
            case 2:
                if (self->f4 != 0) {
                    func_0207F6A8(self->f4);
                    func_0207F6C0(a + d, base + t, step);
                    func_0207F754();
                } else {
                    func_0207E5D0(a + d, base + t, step);
                }
                break;
            case 0:
                func_0207FA0C();
                func_0207FA40(a + d, base + t, step);
                func_0207FADC();
                break;
            default:
                break;
            }
            i = i + 1;
        } while (n > i);
    }
    out->f0 = self->f0;
    out->f4 = self->f4;
    func_020637F4((char *)((UnkOut02063E54 *)((char *)out)), sel, base);
}

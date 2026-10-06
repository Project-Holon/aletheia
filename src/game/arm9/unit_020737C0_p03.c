/*
 * file:     unit_020737C0_p03.c
 * unit:     yes
 * function: func_02073AD0, func_02073B3C
 * address:  0x02073AD0
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
 *   g_0214E934     0x0214E934  data
 *   func_0208A24C  0x0208A24C  arm
 *   func_02089638  0x02089638  arm
 *   func_020894DC  0x020894DC  arm
 *   func_0208C86C  0x0208C86C  arm
 *   func_0208C884  0x0208C884  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 *   func_02073BB0  0x02073BB0  arm
 */
struct X;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed   int   s32;

struct Ent { u32 a; u32 b; };

struct Slot {
    u8  pad_00[0x44];
    s32 f44;          /* 0x44 */
    u8  pad_48[0x08];
    s32 f50;          /* 0x50 */
    u8  f54[4];       /* 0x54 */
};

struct Obj {
    u8  pad_00[0x08];
    u8  f08[0x10];    /* 0x08 */
    u8  f18[0x14];    /* 0x18 */
    u32 b0 : 1;       /* 0x2c */
    s32 b1 : 1;
    u32 b2 : 30;
    u8  pad_30[0x18];
    u32 f48;          /* 0x48 */
    u32 f4c;          /* 0x4c */
};

extern unsigned short func_0208A24C(int dB);
extern void func_02089638(u32 chBitMask, int volume, int shift);
extern void func_020894DC(u32 a, u32 b, u32 c, u32 d);
extern void func_0208C86C(void *p);
extern void func_0208C884(void *p);
extern u32  func_02089D40(void);
extern void func_02089B38(u32 a);
extern void func_02089CD4(u32 a);
extern void func_02073BB0(struct X *x);
extern struct Ent g_0214E934[];


/*
 * Pushes the base value v to +0x44 and re-emits every one of the +0x50 active
 * slots: each slot byte at +0x54+i indexes the 8-byte records of g_0214E934,
 * whose second word is added to the base, converted by func_0208A24C, and
 * handed to func_02089638 as (1 << k, low byte, arithmetic high half).
 *
 * PINNED ../2.0/sp2 on the store/load schedule tell, the same pin its only
 * caller func_02075858 (pkt_02075698) already carries and for the same
 * front-end reason. Under dsi/1.1p1 -O4,p this body is 108 bytes with every
 * instruction and every register correct but 11 bytes out, entirely in the
 * three-instruction window at +0008: the image stores `str r1,[r7,#0x44]`
 * before loading the loop bound `ldr r0,[r7,#0x50]`, and 1.1p1 hoists the
 * load above the store at every spelling tried (a `volatile` store through
 * &s->f44, a `volatile` f50 field, the bound bound to a named local, the
 * guard written as an explicit early return). Under the pin the same C is
 * 108 bytes, 0 concrete mismatches: BYTE-CORRECT.
 *
 * Two shape levers were needed and are worth keeping: the `f50 <= 0` guard
 * must NOT be written as a separate early return (that emits a second
 * `cmp r0,#0`; the bare `for` gives the single predicated `pople`), and
 * `u32 k` must be declared BEFORE `s32 i` or the two swap r5/r6
 * (declaration-order-decides-which-register-a-local-gets).
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. The PC24
 * at +003C to func_0208A24C is unattested: 0x0208A24C has exactly one branch
 * reference anywhere in the image and it is this call, so no cut frees it and
 * only a `matched` entry at 0x0208A24C would close this row.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02073AD0.c \
 *       --func func_02073AD0 --addr 0x02073AD0 --cc ../2.0/sp2 --arm
 */
void func_02073AD0(struct Slot *s, s32 v)
{
    u32 k;
    s32 i;

    s->f44 = v;
    for (i = 0; i < s->f50; i++) {
        s32 r;
        k = s->f54[i];
        r = func_0208A24C(s->f44 + (s32)g_0214E934[k].b);
        func_02089638((u32)(1 << k), (u32)r & 0xff, r >> 8);
    }
}


/*
 * Teardown guarded on bit 1 of the flags word at +0x2C: releases the slot
 * mask built from +0x48, tears down the two sub-objects at +0x08 and +0x18,
 * clears the bit, then brackets func_02089B38(1) with the save/restore pair
 * func_02089D40 / func_02089CD4. The unguarded tail call to func_02073BB0
 * runs either way.
 *
 * PINNED ../2.0/sp2 on the repeated-small-constant tell, per the 2026-09-19
 * correction at the top of
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md,
 * and the same pin its packet sibling func_02073AD0 carries. The literal 1 is
 * live twice here (the `1 << o->f48` shift argument and the func_02089B38
 * argument). Under dsi/1.1p1 -O4,p that is exactly the wall the idiom
 * describes: 1.1p1 pools the 1 into a callee-saved register, giving
 * `mov r6,#1` / `lsl r2,r6,r0` / `mov r0,r6` where the image rematerialises
 * `mov r2,#1` / `lsl r2,r2,r0` / `mov r0,#1`, and the pooled register widens
 * the prologue from `push {r3,r4,r5,lr}` to `push {r4,r5,r6,lr}`. 116 bytes,
 * 6 out, all six in those five instructions. Under the pin the same C is
 * 116 bytes, 0 concrete mismatches: BYTE-CORRECT. This is a second instance
 * of the corrected idiom and is reported as such.
 *
 * The other lever, which cost the first half of the residue: the guard is a
 * SIGNED one-bit bitfield. The image reads it `lsl #30 / asrs #31`, so `s32
 * b1 : 1` is required; `(o->flags >> 1) & 1` on a plain u32 word compiles to
 * `lsr #1 / tst #1` and is 12 bytes out
 * (shift-pair-with-no-matching-type-is-a-bitfield).
 *
 * CAPPED AT MATCH for lack of outside witnesses, not for codegen. Two PC24
 * sites are unattested, and each target has exactly one branch reference
 * anywhere in the image, which is the call inside this function, so no cut
 * frees either: +0040 func_0208C884 and +006C func_02073BB0.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02073B3C.c \
 *       --func func_02073B3C --addr 0x02073B3C --cc ../2.0/sp2 --arm
 */
void func_02073B3C(struct Obj *o)
{
    if (o->b1) {
        u32 saved;

        func_020894DC(o->f4c, 0, 1u << o->f48, 0);
        func_0208C86C(&o->f08);
        func_0208C884(&o->f18);
        o->b1 = 0;
        saved = func_02089D40();
        func_02089B38(1);
        func_02089CD4(saved);
    }
    func_02073BB0((struct X *)o);
}

/*
 * file:     unit_020737C0.c
 * unit:     yes
 * function: func_020737C0, func_02073838, func_02073898, func_020738C0, func_02073A60, func_02073AB4, func_02073AD0, func_02073B3C, func_02073BB0, func_02073BE0, func_02073BF0, func_02073CA0
 * address:  0x020737C0
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
 *   g_0214E8E4     0x0214E8E4  data
 *   g_0214E8E8     0x0214E8E8  data
 *   func_02073CEC  0x02073CEC  arm
 *   func_02060468  0x02060468  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_020729C0  0x020729C0  arm
 *   func_02089660  0x02089660  arm
 *   func_02089540  0x02089540  arm
 *   func_020604AC  0x020604AC  arm
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   g_0214E934     0x0214E934  data
 *   func_0208A24C  0x0208A24C  arm
 *   func_02089638  0x02089638  arm
 *   func_020894DC  0x020894DC  arm
 *   func_0208C86C  0x0208C86C  arm
 *   func_0208C884  0x0208C884  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 *   g_0214E8F4     0x0214E8F4  data
 */
#include "../../matched/include/Obj08946.h"

struct A;
struct Obj;
struct X_020737C0;
struct DList;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct S {
    char pad_00[8];
    void (*f08)(void);  /* 0x08 */
    u32  f0c;           /* 0x0c -- back-pointer to the object */
    char pad_10[8];
    void (*f18)(void);  /* 0x18 */
    u32  f1c;           /* 0x1c -- back-pointer to the object */
    char pad_20[0xc];
    u32  f2c;           /* 0x2c -- flags */
    char pad_30[0x1c];
    u32  f4c;           /* 0x4c */
    u32  f50;           /* 0x50 */
} S;

typedef unsigned short u16;

struct X_020737C0 { u8 pad00[0x4c]; u32 f4c; u32 f50; };

typedef signed   int  s32;

struct SlotDesc { u32 a; u32 b; };

struct SndObj {
    u8  pad_00[0x28];
    u32 f28;
    s32 flag0 : 1;
    u32 flag_hi : 31;
    u32 f30;
    s32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    s32 f48;
    u32 f4c;
    s32 f50;
    u8  f54[4];
};

struct A {
    u8  p00[0x2c];
    union {
        u32 w;
        struct { int b0 : 1; int b1 : 1; int hi : 30; } f;
    } u;
    u8  p30[0x10];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
};

typedef struct {
    u32 unk00[0xb];
    int unk2c : 1;
} Obj02073AB4;

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

struct X_02073BB0 { u8 pad00[0x2c]; u32 f2c; u8 pad2[0x48 - 0x30]; u32 f48; };

struct Obj_02073BF0 {
    u8  pad00[0x28];
    u32 f28;
    u8  pad2c[4];
    u32 f30;
    s32 f34;
    u32 f38;      /* callback */
    u32 f3c;
    s32 f40;      /* frame counter */
    u8  pad44[0xc];
    s32 f50;      /* active slot count */
    u8  f54[4];   /* slot indices */
};

typedef void (*SndSeqCb)(u32 arg, s32 n, u32 *table, u32 base, u32 f28, u32 f3c);

struct Obj_02073CA0 {
    u8  pad_00[0x2c];
    u32 b0 : 1;       /* 0x2c */
    s32 b1 : 1;
    u32 b2 : 30;
    u8  pad_30[0x18];
    u32 f48;          /* 0x48 */
    u32 f4c;          /* 0x4c */
};

extern void func_02060468(int p0, int p1);
extern void func_02073CEC(struct A *a);
extern int func_0207292C(int mask);
extern void func_02072974(u32);
extern u32  func_0209C2B0(u32 a, s32 b);
extern s32  func_020729C0(void);
extern void func_02089660(u32 chan, int fmt, u32 data, int loopmode,
                          int a, int b, int vol, int pan, u32 period, int e);
extern void func_02089540(s32 chan, u32 a, u32 b, void (*cb)(void *), void *arg);
extern void func_020604AC(void *list, void *node);
extern u32  func_02087988(void);
extern void func_0208799C(u32 tok);
extern void func_020894B4(u32, u32, u32, u32);
extern void func_0208C808(void *);
extern void func_0208C828(void *);
extern unsigned short func_0208A24C(int dB);
extern void func_02089638(u32 chBitMask, int volume, int shift);
extern void func_020894DC(u32 a, u32 b, u32 c, u32 d);
extern void func_0208C86C(void *p);
extern void func_0208C884(void *p);
extern u32  func_02089D40(void);
extern void func_02089B38(u32 a);
extern void func_02089CD4(u32 a);
extern void func_02072A08(u32);
extern void func_020605B4(volatile struct DList *list, void *elem);
void func_020737C0(S *p);
int func_02073838(u8 *o, int n, u8 *src);
void func_02073898(struct X_020737C0 *x);
int func_020738C0(struct SndObj *o, int fmt, u32 base, u32 len, u32 rate, s32 frames, u32 cb, u32 ctx);
void func_02073A60(struct A *a);
void func_02073AB4(Obj02073AB4 *p);
void func_02073AD0(struct Slot *s, s32 v);
void func_02073B3C(struct Obj *o);
void func_02073BB0(struct X_02073BB0 *x);
void func_02073BE0(void *o);
void func_02073BF0(struct Obj_02073BF0 *o, u32 arg);
void func_02073CA0(struct Obj_02073CA0 *o);
extern u32  g_0214E8E4;
extern u8   g_0214E8E8[];
extern struct SlotDesc g_0214E934[];
extern u32 g_0214E8F4[];







/*
 * Constructor for the 0x54-byte sound object: lazily create the heap through
 * func_02060468(g_0214E8E8, 0) behind the one-shot latch g_0214E8E4, install
 * the two callbacks (func_02073CA0 at +0x08, func_02073CEC at +0x18) each with
 * the object itself as the following context word, null the handle pair at
 * +0x4C/+0x50, and clear bits 0 and 1 of the flags word at +0x2C.
 *
 * PINNED ../2.0/sp2, the pin four cluster siblings carry (func_02073AD0,
 * func_02073B3C, func_02073CA0, func_02074894). docs/notes/func_020737C0.c.txt
 * recorded this exact C as a 57-byte DIFF at 116 bytes against 120 under
 * dsi/1.1p1, where the read-modify-write of +0x2C is hoisted above the six
 * stores and the two `bic` immediates collapse. Under the pin the same C is
 * 120 bytes, 0 concrete mismatches.
 *
 * Two 1-bit clears must stay two statements: `p->f2c &= ~3` folds to one
 * `bic r0,r0,#3` and loses four bytes, which is what proves the source clears
 * two separate 1-bit fields rather than a 2-bit one.
 *
 * The note's second cap is also gone: the pool word naming g_0214E8E4 is this
 * function's own, but the 2026-09-21 sole-ref widening attests it (data start
 * in a data section), so this is EXACT and not MATCH.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020737C0.c \
 *       --func func_020737C0 --addr 0x020737C0 --cc ../2.0/sp2 --arm
 */
void func_020737C0(S *p)
{
    if (g_0214E8E4 == 0) {
        func_02060468((int)g_0214E8E8, 0);
        g_0214E8E4 = 1;
    }

    p->f08 = (void (*)(void))func_02073CA0;
    p->f0c = (u32)p;
    p->f18 = (void (*)(void))func_02073CEC;
    p->f1c = (u32)p;
    p->f4c = 0;
    p->f50 = 0;
    p->f2c &= ~1;
    p->f2c &= ~2;
}






int func_02073838(u8 *o, int n, u8 *src) {

    u32 m = 0;
    int i;
    for (i = 0; i < n; i++) {
        o[0x54 + i] = src[i];
        m |= 1u << src[i];
    }
    if (func_0207292C(m) == 0) return 0;
    ((struct Obj08946 *)o)->f50 = n;
    ((struct Obj08946 *)o)->f4C = m;
    return 1;
}








/*
 * Releases the registered slot when one is held: the mask to drop is the value
 *  * in +0x4c itself, and the same zero then clears +0x4c and +0x50 out of one
 *  * `mov r0, #0`.
 */
void func_02073898(struct X_020737C0 *x)
{
    if (x->f4c == 0) return;
    func_02072974(x->f4c);
    x->f4c = 0;
    x->f50 = 0;
}






/*
 * The sound object's start: tear down a running instance, size the per-slot
 * buffer (func_0209C2B0 is the divide), claim a hardware channel through
 * func_020729C0 (negative = none, answer 0), set up one PCM channel per slot
 * byte at +0x54 with its buffer address recorded in g_0214E934, arm the timer
 * func_02089540 with the callback func_02073BE0 (a 16-byte tail-call leaf,
 * filed EXACT alongside this so the pool word has a `matched` witness), link
 * the object into g_0214E8E8, latch the parameters, and prime one step of
 * func_02073BF0 with the frame count forced to 1 inside a
 * func_02087988/func_0208799C bracket.
 *
 * One lever: the first quotient is its own statement (`size = div(...);
 * size = (size * frames) << 5;`).  Folded into one expression the multiply
 * comes out `mul r0, fp, r0` instead of the image's `mul r1, r0, fp`.
 */
int func_020738C0(struct SndObj *o, int fmt, u32 base, u32 len,
                  u32 rate, s32 frames, u32 cb, u32 ctx)
{
    u32 size;
    u32 period;
    int i;
    u32 tok;

    if (o->flag0) func_02073AB4((Obj02073AB4 *)o);
    size = func_0209C2B0(len, o->f50 * (frames << 5));
    size = (size * frames) << 5;
    o->f30 = size;
    if (fmt == 1) size >>= 1;
    period = func_0209C2B0(rate * size, frames);
    o->f48 = func_020729C0();
    if (o->f48 < 0) return 0;
    for (i = 0; i < o->f50; i++) {
        u8 slot = o->f54[i];
        g_0214E934[slot].a = o->f30 * i + base;
        g_0214E934[slot].b = 0;
        func_02089660(slot, fmt, g_0214E934[slot].a, 1, 0, o->f30 >> 2,
                      0x7f, 0, rate << 5, 0x40);
    }
    func_02089540(o->f48, period, period, func_02073BE0, o);
    func_020604AC(g_0214E8E8, o);
    o->f28 = fmt;
    o->f34 = frames;
    o->f38 = cb;
    o->f3c = ctx;
    o->f40 = 0;
    o->f44 = 0;
    o->flag0 = 1;
    tok = func_02087988();
    o->f34 = 1;
    func_02073BF0((struct Obj_02073BF0 *)o, 0);
    o->f34 = frames;
    func_0208799C(tok);
    return 1;
}




void func_02073A60(struct A *a) {
    func_020894B4(a->f4c, 0, 1u << a->f48, 0);
    if (a->u.f.b1) return;
    func_0208C808((u8 *)a + 8);
    func_0208C828((u8 *)a + 0x18);
    a->u.w |= 2u;
}






/*
 * Guards the call on bit 0 of the flags word at +0x2C, which the original reads
 * as a signed one-bit field (lsl #31 / asrs #31).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073AB4.c \
 *       --func func_02073AB4 --addr 0x02073AB4 --cc 1.1p1 --arm
 */
void func_02073AB4(Obj02073AB4 *p)
{
    if (p->unk2c != 0) {
        func_02073B3C((struct Obj *)p);
    }
}





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
    func_02073BB0((struct X_02073BB0 *)((struct X_020737C0 *)o));
}



/*
 * EXACT* only because the follower at 0x02073BE0 carries no func_ label in the
 *  * generated listing (it saves no lr), so the inferred extent runs 64 bytes
 *  * instead of the 48 this unit reproduces. No byte of the 48 differs. The
 *  * follower is an unlabelled ARM routine whose words the listing prints as
 *  * `.word` data; seeding 0x02073BE0 in layout/function_starts.txt is the
 *  * integrator's call, not this lane's.
 *  *
 *  * `x->f2c &= ~1` is the bic spelling: the masked-assignment form is what this
 *  * front end turns into `bic r0, r0, #1` without a materialised mask.
 */
void func_02073BB0(struct X_02073BB0 *x)
{
    func_02072A08(x->f48);
    func_020605B4((volatile struct DList *)g_0214E8E8, x);
    x->f2c &= ~1;
}



/*
 * The timer callback func_020738C0 hands to func_02089540 (the pool word at
 * 0x02073A58): steps the sequence object with argument 1.  An unlabelled leaf
 * (`ldr ip,[pc,#4]; mov r1,#1; bx ip` plus the pool word) that disasm.py
 * prints as a .word run after pool_02073BDC.
 */
void func_02073BE0(void *o)
{
    func_02073BF0(o, 1);
}



/*
 * Per-frame step of the sound object: base = f30 / f34 (func_0209C2B0),
 * fill g_0214E8F4[0 .. f50) with each slot's buffer address plus
 * base * frame, hand the table to the callback at +0x38, then advance the
 * frame counter at +0x40 and wrap it at +0x34.
 *
 * The callback's argument list is (arg, o->f50, g_0214E8F4, base, f28, f3c):
 * the COUNT of entries in the table goes second and the per-frame base
 * fourth (the image's r1 is the f50 the loop test just loaded, r3 the base
 * it copied out of r0 before the multiply).  docs/notes/pkt_02073BF0.c.txt
 * had them as (base, table, i) leftovers, 27 bytes out.  With the right
 * list the residue was 9 bytes, which tools/permuter.py --mode hill closed
 * with two mutations: declaration order step, i, base, and the slot's
 * buffer address bound to its own local before the add.
 */
void func_02073BF0(struct Obj_02073BF0 *o, u32 arg)
{
    u32 step;
    s32 i;
    u32 base;
    u32 addr;

    base = func_0209C2B0(o->f30, o->f34);
    step = base * o->f40;
    for (i = 0; i < o->f50; i++) {
        addr = g_0214E934[o->f54[i]].a;
        g_0214E8F4[i] = addr + step;
    }
    ((SndSeqCb)o->f38)(arg, o->f50, g_0214E8F4, base, o->f28, o->f3c);
    o->f40 = o->f40 + 1;
    if (o->f40 >= o->f34) o->f40 = 0;
}



/*
 * Sound-object teardown guarded on bit 1 of the flags word at +0x2C: releases
 * the channel mask built from +0x48 with the handle at +0x4C, then brackets
 * func_02089B38(1) with the save/restore pair func_02089D40 / func_02089CD4.
 * It is func_02073B3C's tail with the two sub-object teardowns removed.
 *
 * PINNED ../2.0/sp2 on the repeated-small-constant tell, exactly as its
 * cluster siblings func_02073AD0 and func_02073B3C already are (see
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md and
 * those two files' headers). The literal 1 is live twice (the `1 << o->f48`
 * shift argument and the func_02089B38 argument); under dsi/1.1p1 -O4,p this
 * body is 76 bytes with every instruction and relocation right but 5 bytes
 * out, all five from 1.1p1 pooling the 1 into a callee-saved register
 * (`mov r5,#1` / `lsl r2,r5,r2` / `mov r0,r5`), which also widens the
 * prologue from `push {r4,lr}` to `push {r3,r4,r5,lr}`. Under the pin the
 * same C is 76 bytes, 0 concrete mismatches.
 *
 * The guard is a SIGNED one-bit bitfield: the image reads it `lsl #30 /
 * asrs #31`, so `s32 b1 : 1` is required
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073CA0.c \
 *       --func func_02073CA0 --addr 0x02073CA0 --cc ../2.0/sp2 --arm
 */
void func_02073CA0(struct Obj_02073CA0 *o)
{
    u32 saved;

    if (!o->b1) return;
    func_020894DC(o->f4c, 0, 1u << o->f48, 0);
    saved = func_02089D40();
    func_02089B38(1);
    func_02089CD4(saved);
}

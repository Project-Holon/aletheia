/*
 * file:     unit_020737C0_p04.c
 * unit:     yes
 * function: func_02073BE0, func_02073BF0, func_02073CA0
 * address:  0x02073BE0
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
 *   g_0214E8F4     0x0214E8F4  data
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_020894DC  0x020894DC  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int    s32;

struct Ent { u32 a; u32 b; };

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

extern u32 func_0209C2B0(u32 a, s32 b);
extern void func_020894DC(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02089D40(void);
extern void func_02089B38(u32 a);
extern void func_02089CD4(u32 a);
extern struct Ent g_0214E934[];
extern u32 g_0214E8F4[];


void func_02073BF0(struct Obj_02073BF0 *o, u32 arg);


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

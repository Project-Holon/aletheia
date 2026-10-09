/*
 * file:     wipe_sub_p06.c
 * unit:     yes
 * function: func_02023964, func_02023A50, func_02023AAC, func_02023AB0, func_02023AF4, func_02023B48, func_02023B74, func_02023BFC, func_02023C3C, func_02023CFC, func_02023D18, func_02023D40, func_02023D60, func_02023D94, func_02023DA8, func_02023DC4, func_02023DDC, func_02023E0C, func_02023E9C
 * address:  0x02023964
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02022EA0  0x02022EA0  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02022F0C  0x02022F0C  thumb
 *   func_02022E20  0x02022E20  thumb
 *   func_02022E88  0x02022E88  thumb
 *   func_02022EF4  0x02022EF4  thumb
 *   func_02022F24  0x02022F24  thumb
 *   _s32_div_f  0x0209C0A4  arm
 *   reg_DISPCNT_SUB  0x04001000  data
 *   reg_BLDCNT      0x0400004A  data
 *   reg_BLDCNT_SUB  0x0400104A  data
 *   sub_020056A0  0x020056A0  thumb
 *   sub_02023D94  0x02023D94  thumb
 *   sub_02023DA8  0x02023DA8  thumb
 *   sub_02023DC4  0x02023DC4  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_0207D658  0x0207D658  arm
 */
#include "../../matched/include/Obj02305.h"
#include "../../matched/include/Obj06900.h"
#include "../../matched/include/Obj06901.h"
#include "../../matched/include/Obj04734.h"

struct Obj;
struct Args2;
struct Args4;
struct Args3;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Desc {
    u32 f00;
    u16 f04;
    u16 f06;
};

typedef signed int     s32;

struct Wipe {
    u8  pad000[0x314];
    s32 step_bound;   /* 0x314  see the note above: a floor, not a ceiling */
    s32 step;         /* 0x318 */
    s32 frame_limit;  /* 0x31c */
    s32 frame;        /* 0x320 */
    s32 f324;         /* 0x324 */
    s32 f328;         /* 0x328 */
    s32 f32c;
    s32 f330;         /* 0x330 */
};

struct Struct_02023CFC {
    void *val;
    u32 idx;
};

struct Item_02023D18 {
    void *val;
    u32 field_4;
    u32 field_8;
    u32 field_C;
};

struct Big_02023D18 {
    u8 pad[0x10];
    struct Item_02023D18 items[1][1];
};

struct Item_02023D40 {
    void *val;
    u32 field_4;
    u32 field_8;
};

struct Rec {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 fC;
};

struct Args2 {
    u32 f0;
    u32 f4;
};

struct Args4 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
};

struct Args3 {
    u32 f0;
    u32 f4;
    u32 f8;
};

typedef signed char    s8;

typedef short          s16_0;

struct Anim {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0a;
    u16 f0c;
    u16 f0e;
    s8  f10;
    u8  f11;
    u16 f12;
    s16_0 f14;
    u16 f16;
    u16 f18;
    s16_0 f1a;
    u32 f1c;
};

typedef signed short   s16_02023E9C;

struct Interp {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0a;
    u16 f0c;
    u16 f0e;
    signed char f10;
    u8  f11;
    s16_02023E9C f12;
    s16_02023E9C f14;
    s16_02023E9C f16;
    u16 f18;
    s16_02023E9C f1a;
    u32 f1c;
};

extern void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void func_02022F0C(u32 a0, u8 *a1, u32 a2);
extern void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6, u32 a7, u32 a8, u32 a9);
extern int func_02022E88(int a0, int a1, int a2, int a3);
extern u32  func_02022EF4(void *p);
extern void func_02022F24(u32 a0, u8 *a1, u32 a2);
void func_02023AB0(void *p);
void func_02023AF4(u8 *desc, u8 *out, s32 num, s32 den);
void func_02023B48(u32 val, u32 engine);
extern void *sub_020056A0(void *cb, void *param, u32 flag);
extern u32 sub_02023D94(void *obj, struct Args2 *args);
extern u32 sub_02023DA8(void *obj, struct Args4 *args);
extern u32 sub_02023DC4(void *obj, struct Args3 *args);
extern void func_020056A0(u32 fn, void *rec, u32 one);
extern void sub_02023B48(u32 a, u32 b);
extern u32  func_02030EAC(void *obj);
extern void sub_02023B74(u32 a, u32 b, u32 c, u32 d);
extern void sub_02023BFC(u32 a, u32 b, u32 c);
extern void func_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);
extern void func_0207D658(u32 addr, int plane, int brightness);
void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC);
void func_02023D40(void *obj, void *val, u32 f4, u32 f8);
void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_02023DDC(void *a0, short *a1);
void func_02023B74(u32 a0, u32 a1, u32 a2, u32 a3);
void func_02023BFC(u32 a, u32 flag, u32 engine);
void sub_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);




/*
 * The setup of the 0x334-byte scanline wipe object (struct WipeScan in
 * docs/families/wipe_sub.h): clears it through func_02022EA0, fills both
 * 0xC0-row tables with 1 or 0 by the descriptor's +6 halfword, stamps ten
 * words at +0x30c..+0x330 in the image's (non-ascending) order, installs
 * the scanline callback through func_02022F0C and arms the window.
 *
 * The 2026-09-20 note was two bytes long because it called
 * func_02022F0C(a0, desc, a3): the image passes (a6, w, a7) -- the
 * sp+0x40 and sp+0x44 stack arguments around the object, matching
 * func_02022F0C's own (u32, u8 *, u32) parameter list.  With that call
 * corrected the rest of the note's body compiles byte for byte.
 */
void func_02023964(u8 *w, struct Desc *d, u32 a2, u32 a3, u32 a4, u32 a5,
                   u32 a6, u32 a7)
{
    func_02022EA0(w, a4, 1, 0, 0);

    if (d->f06 == 0) {
        MI_CpuFill8(w, 1, 0xC0);
        MI_CpuFill8(w + 0xC0, 1, 0xC0);
    } else {
        MI_CpuFill8(w, 0, 0xC0);
        MI_CpuFill8(w + 0xC0, 0, 0xC0);
    }

    ((struct Obj02305 *)w)->f30C = d->f00;
    ((struct Obj02305 *)w)->f310 = d->f04;
    ((struct Obj02305 *)w)->f324 = d->f06;
    ((struct Obj02305 *)w)->f328 = a7;
    ((struct Obj02305 *)w)->f314 = a2;
    ((struct Obj02305 *)w)->f318 = 0;
    ((struct Obj02305 *)w)->f31C = a3;
    ((struct Obj02305 *)w)->f320 = 0;
    ((struct Obj02305 *)w)->f32C = a5;
    ((struct Obj02305 *)w)->f330 = a6;

    func_02022F0C(a6, w, a7);

    if (d->f06 == 1) {
        func_02022E20(a5, 0x20, 0x3F, 0, a4, 0, 0, 0, 0, d->f06);
    } else {
        func_02022E20(a5, 0x3F, 0x20, 0, a4, 0, 0, 0, 0, d->f06);
    }

    func_02022E88(a5, 1, a4, ((struct Obj02305 *)w)->f324);
}


/*
 * The per-frame poll of the 0x334-byte wipe object built by
 * func_020238B4: it ticks the frame counter at +0x320 against the frame
 * limit at +0x31c, and on expiry advances the step index at +0x318
 * against the bound at +0x314.
 *
 * THE COMPARISON IS `<=`, NOT `>`, and it is the function's only real
 * decision.  Written `if (w->step + 1 > w->step_bound)` the function is
 * 92 bytes with every other byte right and ONE wrong: the branch at
 * +0x2a comes out `ble` where the image has `bgt`.  The image branches to
 * the redraw block when step+1 is GREATER than the +0x314 bound, so the
 * fall-through -- the source's first arm -- is the `<=` case, which is
 * the one that calls func_02023AB0/func_02022EF4 and answers 0
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That makes
 * +0x314 a floor rather than a ceiling: the object is retired while the
 * step index is still inside it and keeps redrawing once it is past,
 * which reads backwards until you notice func_02023AB0 is what pushes
 * the NEXT step in, so "inside the bound" here means "there is another
 * step to load".
 *
 * Every field is past the Thumb immediate reach, so the whole group is
 * addressed off ONE register offset (movs #0x32 / lsls #4 = 0x320) that
 * the compiler then bumps by -4, -8, -0xc and +0x10 per access
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Declaring the
 * fields as members of one struct is what keeps that single base; four
 * separate far offsets would each cost their own pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023A50.c \
 *       --func func_02023A50 --addr 0x02023A50 --cc 1.1p1 --thumb
 */
u32 func_02023A50(struct Wipe *w)
{
    s32 f;

    f = w->frame + 1;
    w->frame = f;
    if (f >= w->frame_limit) {
        w->frame = 0;
        if (w->step + 1 <= w->step_bound) {
            w->step = w->step + 1;
            func_02023AB0(w);
            func_02022EF4(w);
        } else {
            func_02022F24(w->f330, (u8 *)w, w->f328);
            return 1;
        }
    }

    return 0;
}


void func_02023AAC(struct Obj *obj){ }


/*
 * cap: the only call site of func_02023AF4 (0x02023AF4) inside the image is at
 *      0x02023ADA, which is inside this function, so the `label` class refuses
 *      it (no witness outside 02023AB0..02023AF2).  Every byte reproduces:
 *      the listing extent reads 68 only because of two bytes of 00 00 padding
 *      at 0x02023AF2; the code is 66.  Promotes to EXACT the moment
 *      func_02023AF4 has its own manifest entry.
 */
void func_02023AB0(void *p)
{
    int i;

    for (i = 0; i < ((struct Obj06900 *)p)->f310; i++) {
        func_02023AF4((void *)(((struct Obj06900 *)p)->f30C + i * 4), p,
                      ((struct Obj06900 *)p)->f318,
                      ((struct Obj06900 *)p)->f314);
    }
}


/*
 * Paints the run [min(lo,hi), max(lo,hi)) of the 0xC0-byte row table at
 * out+0xC0 with a two-tone pattern: the starting value is the descriptor's
 * +2 halfword when lo <= hi and its logical inverse when the bounds are
 * swapped, and the value flips once at split = (hi - lo) * num / den + lo.
 *
 * The notes' four-register rotation (near in r2 against the image's r7,
 * 13 bytes over eleven spellings and both compilers) came from writing the
 * flip with two HAND-HOISTED constant locals `one`/`zero` and a while
 * loop.  Written plainly -- `near = near == 0` in a for loop, the else
 * arm as `flag == 0` -- mwcc hoists the two constants itself, numbers
 * `near` after the loop's address temporary, and the whole function is
 * byte-exact.  The inline-helper spelling (`if (v == 0) return 1;
 * return 0;`) and `v ? 0 : 1` compile identically.  The bounds are still
 * unsigned (`bhi`), the lo <= hi arm still comes first, and the split is
 * still `q + lo` with q a named local.
 *
 * EXACT* only because the 82-byte body is followed by a two-byte pad.
 */
void func_02023AF4(u8 *desc, u8 *out, s32 num, s32 den)
{
    u32 lo = desc[0];
    u32 hi = desc[1];
    s32 q = (s32)(hi - lo) * num / den;
    s32 split = q + lo;
    s32 i;
    s32 end;
    s32 near;

    if (lo <= hi) {
        i = lo;
        end = hi;
        near = ((struct Obj06901 *)desc)->f2;
    } else {
        i = hi;
        end = lo;
        near = ((struct Obj06901 *)desc)->f2 == 0;
    }

    for (; i < end; i++) {
        if (i == split)
            near = near == 0;
        out[0xc0 + i] = near;
    }
}


#define REG_DISPCNT     (*(volatile u32 *)0x04000000)

#define REG_DISPCNT_SUB (*(volatile u32 *)0x04001000)


void func_02023B48(u32 val, u32 engine)
{
    if (engine == 0) {
        REG_DISPCNT = (REG_DISPCNT & 0xffff1fff) | (val << 13);
    } else {
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & 0xffff1fff) | (val << 13);
    }
}



/*
 * Merge bits into one of the two DS display-control halfwords.  a2 picks the
 * register bank (0x04000048 or the 0x04001048 engine-2 twin), a3 picks which
 * six-bit field: the low one (mask ~0x3f, source bit 0, extra bit 0x20) or
 * the middle one (mask ~0x3f00, source aligned to bit 8, extra bit 0x2000).
 * Both registers are read-modify-written as volatile halfwords.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023B74.c \
 *       --func func_02023B74 --addr 0x02023B74 --cc 1.1p1 --thumb
 */
void func_02023B74(u32 a0, u32 a1, u32 a2, u32 a3)
{
    if (a2 == 0) {
        if (a3 == 0) {
            u32 v = *(volatile u16 *)0x04000048;

            v = (v & ~0x3f) | a0;
            if (a1 != 0) {
                v |= 0x20;
            }
            *(volatile u16 *)0x04000048 = v;
        } else {
            u32 v = *(volatile u16 *)0x04001048;

            v = (v & ~0x3f) | a0;
            if (a1 != 0) {
                v |= 0x20;
            }
            *(volatile u16 *)0x04001048 = v;
        }
    } else {
        if (a3 == 0) {
            u32 v = *(volatile u16 *)0x04000048;

            v = (v & ~0x3f00) | (a0 << 8);
            if (a1 != 0) {
                v |= 0x2000;
            }
            *(volatile u16 *)0x04000048 = v;
        } else {
            u32 v = *(volatile u16 *)0x04001048;

            v = (v & ~0x3f00) | (a0 << 8);
            if (a1 != 0) {
                v |= 0x2000;
            }
            *(volatile u16 *)0x04001048 = v;
        }
    }
}



#define REG_BLDCNT     (*(volatile u16 *)0x0400004A)


#define REG_BLDCNT_SUB (*(volatile u16 *)0x0400104A)



void func_02023BFC(u32 a, u32 flag, u32 engine)
{
    u32 val;

    if (engine == 0) {
        val = (REG_BLDCNT & ~0x3f) | a;
        if (flag != 0) {
            val |= 0x20;
        }
        REG_BLDCNT = (u16)val;
    } else {
        val = (REG_BLDCNT_SUB & ~0x3f) | a;
        if (flag != 0) {
            val |= 0x20;
        }
        REG_BLDCNT_SUB = (u16)val;
    }
}



/*
 * Window-bounds setter: picks one of the four window-bounds register
 * pairs (WIN0H/WIN0V and WIN1H/WIN1V, each in the main or the sub
 * engine) and writes the packed horizontal and vertical limits.
 *
 * The four bodies are textually identical in the original, which is why
 * the value expressions are repeated in each arm rather than hoisted:
 * a shared pair of locals computes once and costs 24 bytes less than the
 * image.  The second halfword is one register plus #4, so each arm holds
 * a pointer to the base register and indexes it [0] and [2]; spelling
 * both addresses absolutely puts two pool words per arm in the image
 * where the original has one.
 *
 * The leading argument shuffle (r4 <- r2, r2 <- r3) is the fourth
 * argument's register being recycled for the fifth.
 */
void sub_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub)
{
    if (win == 0) {
        if (sub == 0) {
            u16 *p = (u16 *)0x04000040;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        } else {
            u16 *p = (u16 *)0x04001040;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        }
    } else {
        if (sub == 0) {
            u16 *p = (u16 *)0x04000042;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        } else {
            u16 *p = (u16 *)0x04001042;
            p[0] = (x2 << 8 & 0xff00) | (x1 & 0xff);
            p[2] = (y2 << 8 & 0xff00) | (y1 & 0xff);
        }
    }
}



void func_02023CFC(struct Struct_02023CFC *table, void *val, u32 idx)
{
    struct Struct_02023CFC *entry = &table[idx];

    entry->val = val;
    entry->idx = idx;
    sub_020056A0(sub_02023D94, entry, 1);
}


void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC)
{
    struct Item_02023D18 *entry = (struct Item_02023D18 *)((u8 *)obj + 0x10 + (fC << 5) + (f8 << 4));

    entry->val = val;
    entry->field_4 = f4;
    entry->field_8 = f8;
    entry->field_C = fC;
    sub_020056A0(sub_02023DA8, entry, 1);
}


void func_02023D40(void *obj, void *val, u32 f4, u32 f8)
{
    struct Item_02023D40 *entry = (struct Item_02023D40 *)((u8 *)obj + 0x68 + f8 * 12);

    entry->val = val;
    entry->field_4 = f4;
    entry->field_8 = f8;
    sub_020056A0(sub_02023DC4, entry, 1);
}


void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    struct Rec *r = (struct Rec *)(p + 0x80 + f * 32 + e * 16);

    r->f0 = a;
    r->f2 = b;
    r->f4 = c;
    r->f6 = (u16)d;
    r->f8 = e;
    r->fC = f;
    func_020056A0(0x02023DDD, r, 1);
}


/*
 * The two-field member of the sub_02023DC4/sub_02023DA8 forwarder family:
 * unpack the two words of `args` as positional arguments to
 * sub_02023B48, then tail-call func_02030EAC on the first argument and
 * return its result. `ldm r1, {r0, r1}` is the two-word load; a plain
 * struct-by-value copy or two separate field reads through the pointer
 * both produce the same pair of loads once the fields are consecutive
 * words read in order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02023D94.c \
 *       --func sub_02023D94 --addr 0x02023D94 --cc 1.1p1 --thumb
 */
u32 sub_02023D94(void *obj, struct Args2 *args)
{
    sub_02023B48(args->f0, args->f4);
    return func_02030EAC(obj);
}


/*
 * The four-field member of the sub_02023DC4/sub_02023D94 forwarder
 * family: unpack the four words of `args` as positional arguments to
 * sub_02023B74, then tail-call func_02030EAC on the first argument and
 * return its result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02023DA8.c \
 *       --func sub_02023DA8 --addr 0x02023DA8 --cc 1.1p1 --thumb
 */
u32 sub_02023DA8(void *obj, struct Args4 *args)
{
    sub_02023B74(args->f0, args->f4, args->f8, args->fC);
    return func_02030EAC(obj);
}


/*
 * A three-field struct forwarder: unpack the three words of `args` as
 * positional arguments to sub_02023BFC, then tail-call the ARM function
 * func_02030EAC on the first argument and return its result. The `blx`
 * is the interworking call the linker rewrites a Thumb `bl` into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02023DC4.c \
 *       --func sub_02023DC4 --addr 0x02023DC4 --cc 1.1p1 --thumb
 */
u32 sub_02023DC4(void *obj, struct Args3 *args)
{
    sub_02023BFC(args->f0, args->f4, args->f8);
    return func_02030EAC(obj);
}


void func_02023DDC(void *a0, short *a1)
{
    func_02023C3C(a1[0], a1[1], a1[2], a1[3],
                  ((struct Obj04734 *)a1)->f8, ((struct Obj04734 *)a1)->fC);
    func_02030EAC(a0);
}


/*
 * wipe_sub.c: the per-frame step of the brightness/blend interpolation
 * record that func_02023E9C arms (docs/families/wipe_sub.h, struct Interp).
 * It advances the record's running position f1a towards the target f0a by
 * the per-step delta f14 scaled by the sign f10, pushes the result to the
 * hardware register of whichever engine the f04 bit mask selects, and
 * clears the active flag f1c once the target is reached.
 *
 * FOUR SPELLINGS ARE LOAD-BEARING.  The earlier note
 * (docs/notes/pkt_02023E0C.c.txt) read this function as a whole-function
 * register permutation the allocator would not move; it is not.  It is
 * four shape decisions, and with them the allocation falls out on its own.
 * The note's own draft is 140 bytes against 144 with 127 concrete bytes
 * out; each of the four below is worth a measured step:
 *
 *   1. THE TWO POINTER LOCALS ARE HOISTED to the top of the else arm,
 *      before the f18 accumulate and its test, not created inside the
 *      inner `if`.  This is the whole four-byte size gap: the image emits
 *      `adds r3, r4, #0 / adds r2, r4, #0 / adds r3, #0x1a / adds r2,
 *      #0x18` unconditionally on the else path.  127 bytes out -> 76.
 *
 *   2. THE MULTIPLY IS `step * p->f14`, not `p->f14 * step`.  The image's
 *      `muls r1, r0, r1` keeps `step` in the accumulator, and the
 *      accumulator holds the chain's SECOND operand
 *      (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-
 *      operand.md).  24 bytes out -> 19.
 *
 *   3. BOTH `if`s ARE WRITTEN WITH THE NEGATED CONDITION, so the arm the
 *      image falls through into is the source's first
 *      (docs/idioms/the-fall-through-arm-is-the-source-order.md).  The
 *      outer one is `if (target != cur + v && cur != target) { <advance> }
 *      else { <snap to target> }`, and the inner one is `if (p->f1a !=
 *      target) { <decrement the timer> } else { flag = 1; }`.  Written the
 *      other way round the image's two `beq` to one target come out as a
 *      `beq`/`bne` pair and everything after shifts by one instruction.
 *      76 -> 24 for the outer, 19 -> 8 for the inner.
 *
 *   4. `cur` IS A NAMED LOCAL read BEFORE `target`.  This is the last
 *      eight bytes.  The image loads f1a (offset 0x1a) and only then f0a
 *      (offset 0xa); with `p->f1a` left inline in the condition the
 *      compiler evaluates `target = p->f0a` first and the two `movs
 *      #imm`/`ldrsh` pairs come out in the other order.  Binding the f1a
 *      read to its own local ahead of `target` pins it
 *      (docs/idioms/cmp-operand-order-names-the-temporary.md is the same
 *      tell).  8 -> 0.
 *
 * Statement order of `flag = 0` is NOT a lever: first, second, third and
 * fourth position all compile identically (the compiler sinks the zero to
 * where the image has it, `movs r7, #0` after the two loads).  That was
 * measured, not assumed.
 *
 * Two further facts confirming the earlier note's structural reads, which
 * did survive: the two entry tests really are one `||` (here written as
 * the negated `&&`), and the f1a store is `p->f1a + (s16)v` so the
 * truncation is on the delta and not on the sum -- the image's `lsls
 * r1,r1,#0x10 / asrs r1,r1,#0x10` narrows v alone.  The engine register
 * words are the plain constants 0x04000050 and 0x04001050; the second is
 * NOT 0x04001000 + 0x50 computed at run time, as src/pending/
 * func_02023EF4.c's header already records for the sibling.
 *
 * The two arms of the engine select tail-merge onto one call site, which
 * is what the image's shared `movs r2,#0x1a / ldrsh / ldr r1,[r4] / blx`
 * at +0x74 is; writing the two calls out in full is what produces it
 * (docs/idioms/switch-arms-tail-merge.md).
 *
 * Nothing here is version specific: 0x04000050 and 0x04001050 are DS
 * hardware register addresses and every other constant is a field offset
 * or a flag bit.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02023E0C.c \
 *       --func func_02023E0C --addr 0x02023E0C --cc 1.1p1 --thumb
 */
void func_02023E0C(struct Anim *p)
{
    s8  step;
    int v;
    s16_0 target;
    int flag;
    u16 *timer;
    s16_0 *pos;
    s16_0 cur;

    step = p->f10;
    v = step * p->f14;
    cur = p->f1a;
    target = p->f0a;
    flag = 0;
    if (target != cur + v && cur != target) {
        p->f1a = p->f1a + (s16_0)v;
        pos = &p->f1a;
        timer = &p->f18;
        p->f18 = p->f18 + p->f16;
        if ((u16)p->f18 >= (u16)p->f08) {
            *pos = (s16_0)*pos + step;
            if (p->f1a != target) {
                *timer = *timer - p->f08;
            } else {
                flag = 1;
            }
        }
    } else {
        p->f1a = target;
        flag = 1;
    }
    if (p->f04 & 1) {
        func_0207D658((u32)((void *)0x04000050), p->f00, p->f1a);
    } else if (p->f04 & 2) {
        func_0207D658((u32)((void *)0x04001050), p->f00, p->f1a);
    }
    if (flag == 1)
        p->f1c = 0;
}


/*
 * Initialises the 0x20-byte interpolation record the packet's other two
 * functions drive. The two stack arguments are widened through the usual
 * lsls/lsrs #0x18 pair into the full words at +0x00 and +0x04, so they are
 * int-typed parameters narrowed with a (u8) cast, not u8 parameters.
 *
 * Field roles: f08 = step count, f0a = from, f1a = to, f12 = |to - from|,
 * f10 = the sign (+1 or -1), f14 = per-step delta, f16 = its remainder,
 * f18 = the running accumulator (cleared here), f1c = the active flag.
 *
 * Three spellings are load-bearing and were each isolated against the
 * bytes:
 *   - `p->f1c = 1;` must be the FIRST statement. The constant 1 has to
 *     land in r0 before the two stack arguments are widened; written
 *     anywhere later in the block the allocator promotes it to r6 and the
 *     whole entry block shifts register bank (19 and 14 bytes wrong for
 *     the two later positions tried).
 *   - the negation re-reads the field: the original is `ldrsh` + `subs
 *     r1,#0x13` + `muls`, four bytes more than the `rsbs` the compiler
 *     folds from a cached value. The volatile-qualified read is what
 *     defeats that fold; without it the function compiles 84 bytes, not
 *     88. The `-1` multiplier and the `-1` stored to f10 in the other arm
 *     share one register, derived from the 0x12 field offset.
 *   - `/` and `%` on the same operands are two separate _s32_div_f calls
 *     (docs/idioms/div-and-mod-are-two-calls.md); f14 takes the quotient
 *     from r0 and f16 the remainder from r1.
 */
void func_02023E9C(struct Interp *p, u16 steps, s16_02023E9C from, s16_02023E9C to,
                   u32 a4, u32 a5)
{
    p->f1c = 1;
    p->f00 = (u8)a4;
    p->f04 = (u8)a5;
    p->f12 = to - from;
    p->f08 = steps;
    p->f1a = to;
    p->f0a = from;

    if (p->f12 > 0) {
        p->f10 = -1;
    } else {
        p->f10 = 1;
        p->f12 = *(volatile s16_02023E9C *)&p->f12 * -1;
    }

    p->f14 = p->f12 / steps;
    p->f16 = p->f12 % steps;
    p->f18 = 0;
}

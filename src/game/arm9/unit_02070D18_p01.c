/*
 * file:     unit_02070D18_p01.c
 * unit:     yes
 * function: func_02070D18, func_02070DDC, func_02070F2C
 * address:  0x02070D18
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
 *   func_0206DDA4  0x0206DDA4  arm
 *   g_02148DB0  0x02148DB0  data
 *   g_02149BC0  0x02149BC0  data
 *   FX_DivAsync       0x0207C930  arm
 *   FX_GetDivResult   0x0207C86C  arm
 */
#include "../../matched/include/Obj08939.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int    s32;

struct Vec { s32 a, b, c; };

struct Owner {
    u32 flags;   /* 0x00 */
    s32 f04;
    s32 f08;
    s32 f0c;
    struct Vec v10;   /* 0x10 */
};

struct Desc {
    u8 f00;
    u8 idx;      /* 0x01 */
    u8 slot;     /* 0x02 */
    u8 mode;     /* 0x03 */
};

struct Bank {
    u8  pad_00[0xc4];
    u32 bits[1];  /* 0xc4 */
};

typedef unsigned short u16;

typedef signed short s16;

typedef signed long long s64;

struct Src { u8 pad_00[0x18]; s32 f18; s32 f1c; s16 f20; s16 f22;
             s32 f24; s32 f28; u16 f2c; u16 f2e; };

struct Dst { s32 f00; s32 f04; u8 pad_08[8]; s32 f10; s32 f14;
             u8 pad_18[0x18]; s32 f30; s32 f34; };

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void FX_DivAsync(s32 num, s32 den);
extern s32  FX_GetDivResult(void);
void func_02070D18(u8 *a);


/*
 * The wide sibling of func_02070C5C (docs/notes/pkt_02070C5C.c.txt): the same
 * flag-driven fan-out of func_0206DDA4 commands over one object, with a
 * leading bit-5/bit-3 block and a `first` latch.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md).  The image
 * writes the two arms of the bit-1 fan-out out SEPARATELY, each closing with
 * its own unconditional branch to the join: `bl 0x0206DDA4` / `b 0x02070DBC`
 * at 0x02070D8C/0x02070D90 for the 0x19 arm and `bl 0x0206DDA4` /
 * `b 0x02070DBC` at 0x02070D9C/0x02070DA0 for the 0x1a arm, with the shared
 * `add r1, r5, #0x28` hoisted between the `cmp r4, #0` and the `beq` at
 * 0x02070D78..0x02070D80.  1.1p1 -O4,p cross-jumps the pair into ONE `bl` and
 * one branch, giving 188 bytes against the original's 196.  Under the pin the
 * same C is 196 bytes, 0 mismatches.
 */
void func_02070D18(u8 *a)
{
    u32 f;
    u32 first;

    f = ((struct Obj08939 *)a)->f0;
    first = 0;
    if ((f & 4) == 0)
        first = 1;
    if ((f & 0x20) != 0 && (f & 8) == 0) {
        if (first != 0) {
            func_0206DDA4(0x1c, a + 0x4c, 3);
            first = 0;
        }
        func_0206DDA4(0x1b, a + 0x10, 3);
    }
    f = ((struct Obj08939 *)a)->f0;
    if ((f & 2) == 0) {
        if (first != 0)
            func_0206DDA4(0x19, a + 0x28, 0xc);
        else
            func_0206DDA4(0x1a, a + 0x28, 9);
    } else {
        if (first != 0)
            func_0206DDA4(0x1c, a + 0x4c, 3);
    }
    f = ((struct Obj08939 *)a)->f0;
    if ((f & 1) == 0)
        func_0206DDA4(0x1b, a + 4, 3);
}


struct Row { struct Vec v; s32 pad[3]; };  /* 0x18 bytes */

extern struct Bank *g_02148DB0;
extern struct Row  g_02149BC0[];

/*
 * PIN: ../2.0/sp2, the same pin its packet-mate src/matched/func_02070F2C.c
 * carries, here on the "kept branches" tell combined with the re-read tell.
 * The image keeps `beq 0x02070EF4` (`03 00 00 0a`) at 0x02070EE0 over the
 * THREE-instruction guard body at 0x02070EE4..0x02070EEC
 * (`00 00 9c e5` ldr r0,[ip] / `08 00 80 e3` orr r0,r0,#8 /
 * `00 00 8c e5` str r0,[ip]), closing it with `b 0x02070F0C`
 * (`05 00 00 ea`) at 0x02070EF0, and the guard body RE-READS the flags word
 * the `str r1, [ip]` at 0x02070EC0 has just written.  1.1p1 -O4,p predicates
 * the block AND forwards the still-live value, emitting
 * `orrne r0, r3, #8` / `strne r0, [ip]` / `bne`, giving 328 bytes against the
 * original's 336 with every byte before 0x02070EAC identical modulo the
 * eight-byte pool displacement.  Under the pin the same C is 336 bytes,
 * 0 mismatches.
 *
 * The C lever, needed under BOTH front ends: the three-word row copy at
 * 0x02070F04/0x02070F08 (`ldm r0, {r0, r1, r2}` / `stm r3, {r0, r1, r2}`) is
 * a struct assignment, not three field assignments.  Written out field by
 * field, 1.1p1 and 2.0 both emit three `ldr`/`str` pairs off separate pool
 * words: 344 bytes and 298 concrete out.
 */
void func_02070DDC(struct Owner *oo, s32 *src, struct Desc *d, u32 f)
{
    struct Owner *o = oo;
    u32 m;

    m = d->mode;

    if (f & 4) {
        o->flags |= 1;
        if (m & 2) {
            u32 i = d->idx;
            g_02148DB0->bits[i >> 5] |= 1U << (i & 0x1f);
        }
    } else {
        o->f04 = src[0];
        o->f08 = src[1];
        o->f0c = src[2];
        if (m & 2) {
            u32 i = d->idx;
            g_02148DB0->bits[i >> 5] &= ~(1U << (i & 0x1f));
            g_02149BC0[i].v.a = src[3];
            g_02149BC0[i].v.b = src[4];
            g_02149BC0[i].v.c = src[5];
        }
    }

    if (m & 1) {
        u32 j = d->slot;
        o->flags |= 0x20;
        if (g_02148DB0->bits[j >> 5] & (1U << (j & 0x1f))) {
            o->flags |= 8;
        } else {
            o->v10 = g_02149BC0[j].v;
        }
    }

    o->flags |= 0x10;
}


/*
 * The 64-bit sibling of src/matched/func_02071034.c (docs/notes/pkt_02070DDC.c.txt),
 * and the member of the 0x02071CDC constructor family that carries the full
 * s32 2x2 block AND the f24/f28 cross terms.
 *
 * THE LEVER THE NOTE WAS MISSING, and it closes the 12-byte residue the note
 * records at this address: THE TWO f18 PRODUCTS ARE COMPUTED x7 (f18*f20)
 * FIRST, x6 (f18*f22) SECOND, even though x6 is the one stored first, to
 * d->f00.  Writing them in store order (x6 then x7) gives the allocator's
 * choice, r7 for x6 and r6 for x7, which is exactly the image's pair
 * REVERSED: 14 concrete bytes out, in the six instructions at +0x3C..+0x4C
 * plus `str`/`add`/`mul` at +0x68/+0x94/+0xF8.  Swapping the two statements
 * takes it to 0.  Declaration order (x7,x6), the commutative order of the
 * `x7 + x6` addend, and reversing each smull's operands are all 13-14 out.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md) in its
 * scheduling form.  The image loads the two s16 fields in the order f22 then
 * f20 -- `ldrsh r5, [sb, #0x22]` (`f2 52 d9 e1`) at 0x02070F54 and
 * `ldrsh r0, [sb, #0x20]` (`f0 02 d9 e1`) at 0x02070F5C, straddling the
 * `ldr r3, [sb, #0x18]` -- and then consumes them in the OPPOSITE order,
 * f22's product into r6 and f20's into r7.  1.1p1 -O4,p refuses to separate
 * the load from its first use: it swaps the two `ldrsh`es to match the
 * consumption order and carries the swap through both lsr/orr pairs, the same
 * 264 bytes with 8 concrete bytes out.  No source ordering reaches 0 under
 * 1.1p1, because whichever statement order is written, 1.1p1 reorders the
 * loads to follow it.  Under the pin the same C is 264 bytes, 0 mismatches.
 */
void func_02070F2C(struct Dst *d, struct Src *s)
{
    s32 c, e;
    s32 a, b, p, r;
    s32 x6, x7, x5, x4;
    s32 n;

    c = (s32)s->f2c << 12;
    e = (s32)s->f2e << 12;
    FX_DivAsync(e, c);

    a = (s32)s->f22;
    p = s->f18;
    b = (s32)s->f20;
    r = s->f1c;

    x7 = (s32)(((s64)p * b) >> 12);
    x6 = (s32)(((s64)p * a) >> 12);
    x5 = (s32)(((s64)r * b) >> 12);
    x4 = (s32)(((s64)r * a) >> 12);

    d->f00 = x6;
    d->f14 = x4;
    d->f04 = ((0 - x5) * FX_GetDivResult()) >> 12;

    FX_DivAsync(c, e);

    n = s->f18 - (x7 + x6);
    d->f30 = ((s32)s->f2c * n << 3)
           - ((s32)s->f2c * (s32)(((s64)s->f18 * s->f24) >> 8));
    n = ((x5 - x4) - s->f1c) + 0x2000;
    d->f34 = ((s32)s->f2e * (s32)(((s64)s->f1c * s->f28) >> 8))
           + ((s32)s->f2e * n << 3);

    d->f10 = (x7 * FX_GetDivResult()) >> 12;
}

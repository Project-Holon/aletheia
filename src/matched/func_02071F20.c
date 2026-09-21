/*
 * function: func_02071F20
 * address:  0x02071F20
 * packet:   pkt_02071F20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * One of the two CALLERS of the 0x02071CDC constructor family
 * (docs/notes/pkt_02071DD4.c.txt).  It builds a 0x4c-byte command record
 * on the stack, fills the record's 2x3 matrix block by dispatching on the
 * low three bits of the object's flag word through a pointer table, then
 * applies the object's f30/f34 scales to the two rows -- each through the
 * family's `>> 12` on an s64 product, which folds to `lsr #0xc` +
 * `orr ..., lsl #20` -- and hands the record to func_0206DDA4.
 *
 * Each scale is skipped outright when it is already the unit 0x1000, so
 * both are guarded compares against 0x1000 rather than multiplies by one.
 *
 * Three levers, all measured, and all needed:
 *
 * L1  f30/f34 ARE `volatile`.  The image RE-READS the scale from the
 *     object before the second and third multiply of each block
 *     (`ldr r2,[r4,#0x30]` at 0x02071FC4, `ldr r1,[r4,#0x30]` at
 *     0x02071FDC); 1.1p1 otherwise forwards the register it still holds
 *     live and batches all three smulls, which is 8 bytes short.  But
 *     plain `volatile` also re-reads for the GUARD compare and comes out
 *     4 bytes LONG, so the guard's own load is bound to a local `s` and
 *     the FIRST multiply uses that local while the other two re-read.
 * L2  THE CALL'S BASE IS A POINTER LOCAL.  The image spends two
 *     instructions on the argument, `add r1, sp, #0` then
 *     `add r1, r1, #4` (0x02072040/0x02072048); `&r.f04` folds to a
 *     single `add r1, sp, #4` and loses 4 bytes.  `(s32 *)&r` bound
 *     first, then `base + 1`, reproduces the pair.
 * L3  THE FOUR HEADER CONSTANTS ARE ORDERED BY THE STORES, NOT THE
 *     DECLARATIONS.  mwcc emits the constant movs in order of the first
 *     store that uses each, and sinks any constant whose store sits
 *     after the zero run.  `f04, f48, f40, f44` is the only one of the
 *     orderings measured that gives the image's `mov r1,#0 / mov r3,#3 /
 *     mov r2,#2 / mov r0,#0x1000`; f44-first is 27 bytes out and
 *     f48-first 8, differing by a pure rotation of the three non-zero
 *     constants.  Declaration order and binding the constants to locals
 *     at all are both insensitive.
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *   data_020A8458  0x020A8458  data
 */

typedef unsigned char u8;
typedef signed int   s32;
typedef unsigned int u32;
typedef signed long long s64;

typedef struct Obj {
    u32 f00;
    u8  pad04[0x2c];
    volatile s32 f30;
    volatile s32 f34;
} Obj;

typedef struct Rec {
    u32 hdr;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3c;
    s32 f40;
    s32 f44;
    s32 f48;
} Rec;

typedef void (*Fill)(s32 *out, Obj *o);

extern void func_0206DDA4(u32 hdr, s32 *body, s32 n);
extern Fill data_020A8458[];

void func_02071F20(Obj *o)
{
    Rec r;
    s32 z;
    s32 three = 3;
    s32 two = 2;
    s32 unit = 0x1000;

    z = 0;
    if (o->f00 & 8) {
        r.hdr = 0x00101610;
    } else {
        r.hdr = 0x00101810;
    }
    r.f04 = three;
    r.f48 = two;
    r.f40 = z;
    r.f44 = unit;
    r.f34 = z;
    r.f30 = z;
    r.f2c = z;
    r.f28 = z;
    r.f24 = z;
    r.f20 = z;
    r.f14 = z;
    r.f10 = z;

    data_020A8458[o->f00 & 7](&r.f08, o);

    {
        s32 s = o->f30;
        if (s != 0x1000) {
            r.f08 = (s32)(((s64)s * r.f08) >> 12);
            r.f0c = (s32)(((s64)o->f30 * r.f0c) >> 12);
            r.f38 = (s32)(((s64)o->f30 * r.f38) >> 12);
        }
    }
    {
        s32 s = o->f34;
        if (s != 0x1000) {
            r.f18 = (s32)(((s64)s * r.f18) >> 12);
            r.f1c = (s32)(((s64)o->f34 * r.f1c) >> 12);
            r.f3c = (s32)(((s64)o->f34 * r.f3c) >> 12);
        }
    }

    {
        s32 *base = (s32 *)&r;
        func_0206DDA4(r.hdr, base + 1, 0x12);
    }
}

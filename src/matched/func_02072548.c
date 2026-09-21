/*
 * function: func_02072548
 * address:  0x02072548
 * packet:   pkt_02072548
 * region:   arm9
 * compiler: ../2.0/sp2
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
 *   data_020A8478  0x020A8478  data
 *
 * Derived from src/matched/func_02071F20.c, its sibling and the other caller of
 * the 0x02071CDC constructor family (docs/notes/pkt_02071DD4.c.txt, "NOT
 * ATTEMPTED").  Same 0x4c-byte stack record, same two header constants
 * (0x00101610 / 0x00101810), same 2x3 fill dispatched through the low three
 * flag bits -- through data_020A8478 here rather than data_020A8458 -- and the
 * same two f30/f34 scale blocks.  L1, L2 and L3 above all transferred
 * unchanged, including the `volatile` f30/f34 with the guard's own load bound
 * to `s`, and were not re-derived.
 *
 * What this one adds over func_02071F20: three flag-guarded writes back into
 * the OBJECT, ahead of the dispatch -- bit 0 sets f1c and f18 to the unit
 * scale, bit 1 sets h22 to 0x1000 and h20 to 0, bit 2 clears f28 and f24.  The
 * store order inside each pair is high field first, and each guard re-reads
 * o->f00 (`ldr r0,[r4]` at 0x020725AC, 0x020725BC, 0x020725D8, 0x020725EC).
 * h20/h22 are s16: the pair is `strh`.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md), and exactly
 * the one docs/notes/pkt_02071DD4.c.txt flagged at this address in advance.
 * The image keeps `tst r0, #2` at 0x020725C0 (`02 00 10 e3`) and `beq 0x020725D8`
 * at 0x020725C4 (`03 00 00 0a`) over the FOUR-instruction bit-1 guard body at
 * 0x020725C8..0x020725D4 (`mov r0,#0x1000` / `strh r0,[r4,#0x22]` /
 * `mov r0,#0` / `strh r0,[r4,#0x20]`).  1.1p1 -O4,p predicates it to
 * `movne/strhne/movne/strhne` -- and, having done so, reverses the pair to
 * h20-then-h22 -- giving 388 bytes against the original's 392, 226 concrete
 * bytes out and the whole body shifted by four.  The bit-0 and bit-2 guards,
 * being two instructions each, are predicated under BOTH front ends and are
 * not evidence either way.  Under the pin the same C is 392 bytes,
 * 0 mismatches.
 */

typedef unsigned char u8;
typedef signed short s16;
typedef signed int   s32;
typedef unsigned int u32;
typedef signed long long s64;

typedef struct Obj {
    u32 f00;
    u8  pad04[0x18 - 4];
    s32 f18;
    s32 f1c;
    s16 h20;
    s16 h22;
    s32 f24;
    s32 f28;
    u8  pad2c[0x30 - 0x2c];
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
extern Fill data_020A8478[];

void func_02072548(Obj *o)
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

    if (o->f00 & 1) {
        o->f1c = unit;
        o->f18 = unit;
    }
    if (o->f00 & 2) {
        o->h22 = 0x1000;
        o->h20 = 0;
    }
    if (o->f00 & 4) {
        o->f28 = 0;
        o->f24 = 0;
    }

    data_020A8478[o->f00 & 7](&r.f08, o);

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

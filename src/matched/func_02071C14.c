/*
 * function: func_02071C14
 * address:  0x02071C14
 * packet:   pkt_02071360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 128-byte constructor of the cluster_02071360 family: f18/f1c
 * straight into the diagonal slots f00/f14, f04/f10 zeroed, and BOTH
 * translations through a 64-bit product against the diagonal:
 *   f30 = (f18 * ((-f2c << 11) - f24 * f2c)) >> 8  +  f2c << 15
 *   f34 = (f1c * (f28 * f2e + (-f2e << 11))) >> 8  +  f2e << 15
 *
 * What the image needs, all found by tools/permuter.py (hill then anneal,
 * 21 -> 6 -> 1 byte out, the last byte an s16 type probe whose value-
 * preserving u16 form closes it):
 *   - the four source halfword/word reads bound to locals BEFORE the first
 *     store to d->f30 (the image loads f2c, f24, f2e, f28 ahead of that
 *     store; f18/f1c and the final f2e are re-read after it);
 *   - the f34 multiplier computed into its own local ahead of the f30
 *     product (permuter `temp` + `hoist-up`);
 *   - the f2c local typed u16, the field's own type (s32 swaps r5/r6).
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 is 128 bytes with 6
 * concrete bytes out, a single swapped pair -- 1.1p1 schedules the final
 * `ldrh r1, [r1, #0x2e]` one slot EARLIER, ahead of `lsr r2, lr, #8`.
 * Under ../2.0/sp2 it is 0 out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02071C14.c \
 *       --func func_02071C14 --addr 0x02071C14 --arm --cc ../2.0/sp2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;
typedef long long      s64;

struct SRC {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    s16 f22;
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
};

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

void func_02071C14(struct DST *d, struct SRC *s)
{
    u16 c;
    s32 e, x, y;
    s64 m;
    s32 t34;

    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;

    c = s->f2c;
    x = s->f24;
    e = s->f2e;
    y = s->f28;

    t34 = y * e + ((0 - e) << 11);

    m = (s64)s->f18 * (((0 - c) << 11) - x * c);
    d->f30 = (s32)(m >> 8) + (c << 15);

    m = (s64)s->f1c * t34;
    d->f34 = (s32)(m >> 8) + ((s32)s->f2e << 15);

    d->f10 = 0;
}

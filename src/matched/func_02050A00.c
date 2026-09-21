/*
 * function: func_02050A00
 * address:  0x02050A00
 * packet:   pkt_02050984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The third arm of the handler table func_02050984 dispatches through (see
 * src/pending/func_02050984.c).  88 bytes, a leaf: the command halfword at
 * c->f02 packs two bytes, a repeat count in the high half and a value in the
 * low half.  While the entry's repeat counter at +0x14 is below the count,
 * store the value at +0x10 and bump the counter; once it reaches the count,
 * reset the counter and advance +0x10 by one instead.  +0x12 is zeroed on
 * both paths.  Returns 0 (the "command consumed, keep going" verdict the
 * dispatcher in func_02050944 tests).
 *
 * The comparison is SIGNED (`bge`), so both sides are promoted `int`s and the
 * counter is compared as an int, not as an unsigned halfword.
 *
 * Two shapes are load-bearing, both worth 8 bytes each:
 *
 *   - The high byte must land in a `u8` LOCAL, not be written inline in the
 *     comparison.  `if (n < ((v & 0xff00) >> 8 & 0xff))` lets mwcc fold the
 *     shift into the compare's shifter operand (`cmp r2, r1, asr #8`) and drop
 *     the redundant `and #0xff` entirely, losing the original's separate
 *     `asr r1,r1,#8` / `and r1,r1,#0xff` pair (80 bytes, 56 out).
 *   - The LOW byte must be extracted into its own local BEFORE the `if`, not
 *     spelled `v & 0xff` at its single use inside the taken arm.  The original
 *     issues `and r3, r3, #0xff` above the `bge`; written at the use it lands
 *     after it, which is the last 8 bytes (88 bytes, 8 out).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A00.c \
 *       --func func_02050A00 --addr 0x02050A00 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct Ent {
    u16 pad00[8];
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Cmd {
    u16 f00;
    u16 f02;
};

int func_02050A00(struct Ent *e, struct Cmd *c)
{
    int v = c->f02;
    int n = e->f14;
    unsigned char hi = (unsigned char)((v & 0xff00) >> 8);
    unsigned char lo = (unsigned char)v;

    if (n < hi) {
        e->f10 = lo;
        e->f12 = 0;
        e->f14 = (u16)(n + 1);
    } else {
        int cur = e->f10;
        e->f14 = 0;
        e->f12 = 0;
        e->f10 = (u16)(cur + 1);
    }
    return 0;
}

/*
 * function: func_0203C0DC
 * address:  0x0203C0DC
 * packet:   pkt_0203C0DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores one byte at +0x4E, negating it first unless it is 1005 or 1006.  The
 * threshold is written `v - 1005 > 1`, and 1005 is not encodable as an ARM
 * immediate in a `sub`, so mwcc builds it the other way round: `mvn r2, #1004`
 * is -1005 and one `add` finishes the subtraction.  The comparison is
 * unsigned (`rsbhi`), and the negation is `rsb r1, r1, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C0DC.c \
 *       --func func_0203C0DC --addr 0x0203C0DC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void func_0203C0DC(u8 *p, u32 v)
{
    if (v - 1005 > 1)
        v = -v;
    p[0x4E] = (u8)v;
}

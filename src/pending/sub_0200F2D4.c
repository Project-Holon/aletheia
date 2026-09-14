/*
 * function: sub_0200F2D4
 * address:  0x0200F2D4
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0203D5D4  0x0203D5D4  arm
 *   func_0203CF5C  0x0203CF5C  arm
 *   sub_0200F2D4_Flag  0x02146178  data
 *
 * A one-byte latch, gated on func_0203D5D4() reporting exactly 2: while
 * gated, the flag either turns on (set from func_0203CF5C's result) if it
 * was off, or is cleared if it was already on. Outside the gate, it just
 * calls func_0203CF5C() for effect and leaves the flag alone.
 *
 * Every concrete byte matches; sub_0200F2D4_Flag is referenced only by
 * this one function's pool word, so that relocation stays unresolved
 * under the honesty rule (the `literal` class needs a witness outside the
 * range under test, and there isn't one).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200F2D4.c \
 *       --func sub_0200F2D4 --addr 0x0200F2D4 --cc 1.1p1
 *
 * Closes to EXACT the day another function's pool loads the same address.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0203D5D4(void);
extern u32 func_0203CF5C(void);

extern u8 sub_0200F2D4_Flag;

void sub_0200F2D4(void)
{
    if (func_0203D5D4() == 2) {
        if (sub_0200F2D4_Flag == 0) {
            sub_0200F2D4_Flag = (u8)func_0203CF5C();
        } else {
            sub_0200F2D4_Flag = 0;
        }
    } else {
        func_0203CF5C();
    }
}

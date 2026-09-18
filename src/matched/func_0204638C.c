/*
 * function: func_0204638C
 * address:  0x0204638C
 * packet:   pkt_020461F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Expand the low eight bits of the argument into a nibble mask: bit i set
 * turns nibble i into 0xf, so bit 0 gives 0x0000000f and bit 7 gives
 * 0xf0000000.  The 0xf0000000 sits in a register outside the loop and the
 * per-iteration shift is a register (i * 4) rather than a constant, which
 * is why the loop carries a second index register: the count itself would
 * not do, the shift needs it scaled.
 *
 * The loop is a plain `for` from zero to eight; the compiler folds the test
 * into `cmp #8` / `blt` with both the test and the or predicated on a `tst`,
 * and the accumulator lives in lr.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204638C.c  *       --func func_0204638C --addr 0x0204638C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

u32 func_0204638C(u32 bits)
{
    int i;
    u32 out = 0;

    for (i = 0; i < 8; i++) {
        if (bits & (1 << i))
            out |= 0xF0000000 >> (i * 4);
    }
    return out;
}

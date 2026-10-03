/*
 * function: func_0203A634
 * address:  0x0203A634
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *
 * Bit test against a channel mask: 0xFF is always live, otherwise the bit of
 * the argument named by the index func_02039338() reports decides, and a zero
 * index falls back to the 0x80 bit.  `1 << f()` is emitted as the shifted
 * register of a `tst`, and each success path is the conditional
 * `movne r0, #1` / `popne` pair, so the source is the return chain above a
 * final plain `return 0;`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A634.c \
 *       --func func_0203A634 --addr 0x0203A634 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 func_02039338(void);

u32 func_0203A634(u32 a0)
{
    if (a0 == 0xFF)
        return 1;
    if (a0 & (1 << func_02039338()))
        return 1;
    if (func_02039338() == 0 && (a0 & 0x80) != 0)
        return 1;
    return 0;
}

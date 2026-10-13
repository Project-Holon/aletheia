/*
 * function: sub_0202F114
 * address:  0x0202F114
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Bit i of a byte array, inverted: 1 when the bit is clear.  Unlabelled leaf
 * in the 0x0202F114..0x0202F190 gap between TIME_ICON_Update and func_0202F190.
 *
 * The byte index and the bit number are both `u8` locals: the original
 * truncates each with its own `lsls #0x18`/`lsrs #0x18` pair, and `i >> 3`
 * or `i & 7` folded into the shift expression loses them (the front end
 * knows both are already in range and drops the conversions).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F114.c \
 *       --func sub_0202F114 --addr 0x0202F114 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 sub_0202F114(const u8 *p, u32 i)
{
    u8 idx = (u8)(i >> 3);
    u8 bit = (u8)(i & 7);

    if ((p[idx] & (1 << bit)) != 0)
        return 0;
    return 1;
}

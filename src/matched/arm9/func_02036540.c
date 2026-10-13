/*
 * function: GFL_NET_RING_BUFF_ReadU16
 * address:  0x02036540
 * packet:   pkt_0203640C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_RING_BUFF_ReadByte  0x02036500  arm
 *
 * Packs two bytes read through src/matched/GFL_NET_RING_BUFF_ReadByte.c into one halfword,
 * high byte first.  The same call is made twice with the same argument.
 *
 * The shape that reproduces the original is `hi = (u16)(call << 8);` - the
 * `u16` narrowing folded into the shift, which mwcc encodes as `lsl r4, r0,
 * #24` (`(x << 8) mod 2^16` starts its life as `x << 24`) with the companion
 * half of the pair spent as the *shift operand* of the `orr`, `orr r0, r0, r4,
 * lsr #16`.  Spelling the mask as a value first - `hi = (u8)call;` or
 * `(u8)hi << 8` - makes mwcc emit `and r4, r0, #0xFF` followed by
 * `orr r0, r0, r4, lsl #8` instead: the same two instructions, the same
 * result, different bytes.  This is the unequal-shift-pair tell of
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * one level up: with the mask inline mwcc picks the AND form, so the mask has
 * to be on the narrowed *variable*, not on the shifted expression.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_RING_BUFF_ReadU16.c \
 *       --func GFL_NET_RING_BUFF_ReadU16 --addr 0x02036540 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 GFL_NET_RING_BUFF_ReadByte(u32 a);

u32 GFL_NET_RING_BUFF_ReadU16(u32 a)
{
    u16 hi;
    u32 lo;

    hi = (u16)(GFL_NET_RING_BUFF_ReadByte(a) << 8);
    lo = GFL_NET_RING_BUFF_ReadByte(a);
    return (u16)(hi | lo);
}

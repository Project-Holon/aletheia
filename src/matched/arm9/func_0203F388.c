/*
 * unit:     no
 * function: GF_STANDARD_RandLcg
 * address:  0x0203F388
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The standard 32-bit LCG (multiplier 0x41c64e6d, increment 0x6073) over a
 * caller-supplied seed word, returning the top halfword.  0x6073 is not an
 * ARM rotated immediate, so the increment is two `add`s; the `lsl`/`lsr`
 * pair after the first `lsr` is the u16 return type's truncation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_RandLcg.c \
 *       --func GF_STANDARD_RandLcg --addr 0x0203F388 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u16 GF_STANDARD_RandLcg(u32 *seed)
{
    u32 v = *seed * 0x41c64e6d + 0x6073;

    *seed = v;
    return (u16)(v >> 16);
}

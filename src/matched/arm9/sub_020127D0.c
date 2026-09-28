/*
 * function: sub_020127D0
 * address:  0x020127D0
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Address-of-element on a 0x1E8-byte record array at +0x214: the pair of
 * constants 0x214 and 0x1E8 differ by 0x2c, so the compiler materialises the
 * larger one from a pool-free `movs`/`lsls` pair and derives the stride with
 * a `subs` (see docs/idioms/a-constant-pair-...).  Entry attested by the
 * pool word 0x020127D1 that func_020127C4 loads.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020127D0.c \
 *       --func sub_020127D0 --addr 0x020127D0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


u8 *sub_020127D0(u8 *o, u32 idx)
{
    return o + 0x214 + idx * 0x1E8;
}


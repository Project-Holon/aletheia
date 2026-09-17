/*
 * function: func_0202BE54
 * address:  0x0202BE54
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * symbols:
 *   _u32_div_f   0x0209C2B0  arm
 * status:   EXACT
 *
 * Returns (p[9] * a) / 0x7f truncated to a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE54.c \
 *       --func func_0202BE54 --addr 0x0202BE54 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_0202BE54(u8 *p, u32 a)
{
    return (u8)((p[9] * a) / 0x7f);
}

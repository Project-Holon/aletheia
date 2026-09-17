/*
 * function: func_0202A20C
 * address:  0x0202A20C
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Returns func_0202A1CC's result, clamped to zero when negative.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202A20C.c \
 *       --func func_0202A20C --addr 0x0202A20C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

extern s32 func_0202A1CC(u8 *p, u32 a);

u32 func_0202A20C(u8 *p, u32 a)
{
    s32 r = func_0202A1CC(p, a);

    return r < 0 ? 0u : (u32)r;
}

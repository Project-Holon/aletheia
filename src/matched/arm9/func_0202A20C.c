/*
 * function: func_0202A20C
 * address:  0x0202A20C
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns func_0202A1CC's result, clamped to zero when negative.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202A20C.c \
 *       --func func_0202A20C --addr 0x0202A20C --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202A1CC was filed as an EXACT entry this
 * wave (pkt_0202A19C) with the struct-container spelling of the bounded scan.
 */

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

struct Container;
extern u32 func_0202A1CC(const struct Container *c, u32 key, u32 v2, u32 v3);

u32 func_0202A20C(u8 *p, u32 key, u32 v2, u32 v3)
{
    s32 r = func_0202A1CC((const struct Container *)p, key, v2, v3);

    return r < 0 ? 0u : (u32)r;
}

/*
 * function: func_0202A188
 * address:  0x0202A188
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns the halfword at entry i (times 8 plus 6) of the +0 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202A188.c \
 *       --func func_0202A188 --addr 0x0202A188 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0202A20C(u8 *p, u32 key, u32 v2, u32 v3);

u32 func_0202A188(u8 *p, u32 a, u32 v2, u32 v3)
{
    u32 i = func_0202A20C(p, a, v2, v3);

    return *(u16 *)(*(u32 *)p + i * 8 + 6);
}

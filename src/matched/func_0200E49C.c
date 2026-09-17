/*
 * function: func_0200E49C
 * address:  0x0200E49C
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 1 when func_0200E4B0's result is 0x63 or more, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E49C.c \
 *       --func func_0200E49C --addr 0x0200E49C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0200E4B0(u8 *p, u32 a, u32 count);

u32 func_0200E49C(u8 *p, u32 a, u32 count)
{
    return func_0200E4B0(p, a, count) >= 0x63 ? 1 : 0;
}

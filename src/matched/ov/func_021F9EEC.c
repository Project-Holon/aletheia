/*
 * function: func_021F9EEC
 * address:  0x021F9EEC
 * packet:   pkt_021F9EEC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Step one byte short of the end, or report 1 when there is no buffer.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_0209C0A4(u8 *p, u32 n, u32 m);

u32 func_021F9EEC(u8 *p, u32 n)
{
    u32 m;

    if (p == 0) {
        return 1;
    }
    m = n - 1;
    return func_0209C0A4(p + m, n, m);
}

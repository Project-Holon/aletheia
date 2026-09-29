/*
 * function: func_0219C0D4
 * address:  0x0219C0D4
 * packet:   pkt_ov021_0219C0D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0216D684  0x0216D684  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 *func_0216D684(u32, u32);

void func_0219C0D4(u32 a, u32 b, u32 c)
{
    u32 *p = func_0216D684(a, 12);
    p[1] = b;
    p[2] = c;
}

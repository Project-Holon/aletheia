/*
 * function: func_021CBF98
 * address:  0x021CBF98
 * packet:   pkt_ov021_021CBF98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A 16-bit random value: the arm9 random source scaled down by 0xFFFF.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f  0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020056EC(u32 max);
extern u32 _u32_div_f(u32 a, u32 b);

u16 func_021CBF98(void *ctx)
{
    return func_020056EC(0xffffffff) / 0xffff;
}

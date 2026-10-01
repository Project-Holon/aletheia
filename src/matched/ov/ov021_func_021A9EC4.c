/*
 * function: func_021A9EC4
 * address:  0x021A9EC4
 * packet:   pkt_ov021_021A9EC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A9DC8  0x021A9DC8  thumb
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned int u32;

extern u32 func_021A9DC8(u32 a);

u32 func_021A9EC4(u32 a)
{
    return func_021A9DC8(a) % a;
}

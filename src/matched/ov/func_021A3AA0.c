/*
 * function: func_021A3AA0
 * address:  0x021A3AA0
 * packet:   pkt_021A3AA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216D3CC(int a0);
extern void *func_021A3960();

int func_021A3AA0(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D3CC((int)func_021A3960(a, b, c, d)) == 1) {
    return 1;
}
return 0;
}


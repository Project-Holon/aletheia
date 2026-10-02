/*
 * function: func_02197DF4
 * address:  0x02197DF4
 * packet:   pkt_02197DF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216D3CC(int a0);

int func_02197DF4(u32 a)
{
if (func_0216D3CC(*(u32 *)((u8 *)(a) + 12)) == 0) {
    return 0;
}
*(u32 *)((u8 *)(a)) = 2;
return 1;
}


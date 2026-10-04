/*
 * function: func_0219FFBC
 * address:  0x0219FFBC
 * packet:   pkt_ov021_0219FFBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02189A78  0x02189A78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern u32 func_02189A78(u8 *p);

void func_0219FFBC(u32 a, u32 *p)
{
    p[1] += func_02189A78((u8 *)func_0216D534(func_0216D67C((void *)a)));
}

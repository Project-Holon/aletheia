/*
 * function: func_0219C9E0
 * address:  0x0219C9E0
 * packet:   pkt_ov021_0219C9E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   d_021D75D0  0x021D75D0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216E3C4(void *p);
extern u16 d_021D75D0[][2];

void func_0219C9E0(u32 a, u16 *x, u16 *y)
{
    u8 *d = func_0216E3C4((void *)a);
    u16 *t = d_021D75D0[d[7]];
    *x = t[0];
    *y = t[1];
}

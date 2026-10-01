/*
 * function: func_0219ADC8
 * address:  0x0219ADC8
 * packet:   pkt_ov021_0219ADC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D4D78  0x021D4D78  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern u8 *func_0216D69C(u32);
extern Step d_021D4D78[];

void func_0219ADC8(u32 a)
{
    u8 *p = func_0216D69C(a);
    while (d_021D4D78[p[0]](a, p) == 1) {
    }
}

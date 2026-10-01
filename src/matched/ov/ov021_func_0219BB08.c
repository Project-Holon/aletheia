/*
 * function: func_0219BB08
 * address:  0x0219BB08
 * packet:   pkt_ov021_0219BB08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219BC48  0x0219BC48  thumb  ov021
 *   d_021D538C  0x021D538C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern u8 *func_0216D69C(u32);
extern int func_0219BC48(u32, u8 *);
extern Step d_021D538C[];

void func_0219BB08(u32 a)
{
    u8 *p = func_0216D69C(a);
    if (func_0219BC48(a, p)) {
        while (d_021D538C[p[0]](a, p) == 1) {
        }
    }
}

/*
 * function: func_0219BAE0
 * address:  0x0219BAE0
 * packet:   pkt_ov021_0219BAE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219BC48  0x0219BC48  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_0216D684(u32, u32);
extern int func_0219BC48(u32, u8 *);
extern void func_0216D674(u32, u32);
extern void func_0216DA50(u32);

void func_0219BAE0(u32 a)
{
    u8 *p = func_0216D684(a, 12);
    func_0219BC48(a, p);
    func_0216D674(a, 0);
    func_0216DA50(a);
    p[1] = 0;
}

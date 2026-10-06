/*
 * function: func_02198318
 * address:  0x02198318
 * packet:   pkt_ov021_02198318
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0216D6BC(int a0, int a1, int a2);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
extern void func_02163F10(u32);
extern void func_0216D7CC(u8 *p);

void func_02198318(u32 a, u32 b, u16 c, u16 d)
{
    u16 *p;

    p = func_0216D6BC((u32)a, (u32)12, c);
    p[0] = d;
    p[1] = c;
    func_0216D5E0((u32)a, (u16)b);
    func_0216D674((void *)a, d);
    func_02163F10(a);
    func_0216D7CC((u8 *)a);
}

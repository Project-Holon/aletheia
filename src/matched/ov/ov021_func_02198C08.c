/*
 * function: func_02198C08
 * address:  0x02198C08
 * packet:   pkt_ov021_02198C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 *func_0216D6BC(u32, u32);
extern void func_02163E7C(int a, int b);
extern int func_0216D60C(int a0, int a1);
extern u32 func_0216D674(u32, u32);
extern void func_0216D568(void *p, u32 v);
extern u32 func_0216D7CC(u32);

void func_02198C08(u32 a, u32 b, u32 c, u32 d)
{
    u16 *p;

    p = func_0216D6BC(a, 8);
    p[0] = b;
    p[1] = d;
    p[2] = c;
    func_02163E7C(a, ((b << 16) >> 16));
    func_0216D60C(a, (u16)b);
    func_0216D674(a, d);
    func_0216D568((void *)a, 32);
    func_0216D7CC(a);
}

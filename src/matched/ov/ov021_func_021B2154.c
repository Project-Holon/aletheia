/*
 * function: func_021B2154
 * address:  0x021B2154
 * packet:   pkt_ov021_021B2154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B1E74  0x021B1E74  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B8484  0x021B8484  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021B1E74(u32 a);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0219E348(void *a);
extern void func_021B8484(u8 *p, u32 a, u32 b, int c);
extern void func_021B7DC0(u32, void *);
extern void func_0219E2C0(void *a, void *r);

int func_021B2154(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = func_021B1E74(b);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0219E348((void *)h);
    func_021B8484((u8 *)o, x, y, z);
    func_021B7DC0(o, buf);
    func_0219E2C0((void *)h, buf);
    return 0;
}

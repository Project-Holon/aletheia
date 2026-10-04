/*
 * function: func_0219DCC4
 * address:  0x0219DCC4
 * packet:   pkt_ov021_0219DCC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E354  0x0219E354  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0219E348(void *a);
extern void func_0219E354(u32 a);
extern void func_021B8028();
extern u8 func_021B8040(u8 *p);
extern void func_0216D89C();
extern void func_0216D568(void *p, u32 v);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u8 *p);

int func_0219DCC4(u32 o)
{
    u32 a;
    u8 buf[12];

    a = (u32)func_0219E348((void *)o);
    func_0219E354(o);
    func_021B8028(a, buf);
    func_0216D89C(o, buf);
    if (func_021B8040((u8 *)a)) {
        return 0;
    }
    func_0216D568((void *)o, 0x440);
    func_0216D674((void *)o, 0);
    func_0216D7CC((u8 *)o);
    return 0;
}

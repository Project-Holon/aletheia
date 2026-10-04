/*
 * function: func_0219D680
 * address:  0x0219D680
 * packet:   pkt_ov021_0219D680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D528  0x0216D528  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0219D604  0x0219D604  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D67C(void *a0);
extern u32 func_0216D528(u8 *p);
extern u16 func_0216D598(void *p);
extern void func_021C6628(u32, u32);
extern int func_0216DFC4(void *a, u32 id);
extern void func_0219D604(u8 *s, u16 k);

void func_0219D680(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0216D528(func_0216D67C((void *)a));
    u16 v = func_0216D598((void *)a);
    func_021C6628(*(u32 *)(s + 4), b);
    if (func_0216DFC4((void *)a, v) == 0) {
        func_0219D604(s, v);
    }
}

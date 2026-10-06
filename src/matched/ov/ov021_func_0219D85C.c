/*
 * function: func_0219D85C
 * address:  0x0219D85C
 * packet:   pkt_ov021_0219D85C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0219E334  0x0219E334  thumb  ov021
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_0216D7E0  0x0216D7E0  thumb  ov010
 *   func_0216D7D8  0x0216D7D8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern int func_0216DCB4(void *a0);
extern void *func_0216D67C(void *a0);
extern void *func_0216D530(void *p);
extern void func_0219E2F4(void *o, void *out);
extern int func_0219E334(u32 a, u32 b);
typedef unsigned char  u8;
extern u32 func_021BB3C4(u8 *p, char *a1);
extern void func_0216D7E0(void *p, u32 v);
extern void func_0216D7D8(void *p, u32 v);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);

u32 func_0219D85C(u32 a)
{
    u32 v1[2];
    u32 v0[2];
    u32 r6 = -1;
    u32 r5 = -1;
    u32 t;
    if (func_0216DCB4((void *)a) == 0) {
        t = (u32)func_0216D530(func_0216D67C((void *)a));
        func_0219E2F4((void *)a, v0);
        func_0219E334(a, (u32)v1);
        r6 = func_021BB3C4((u8 *)t, (char *)v1);
        r5 = func_021BB3C4((u8 *)t, (char *)v0);
    }
    func_0216D7E0((void *)a, r6);
    func_0216D7D8((void *)a, r5);
    if (r5 == -1) {
        func_0216D568((void *)a, 0x800);
        return 0;
    }
    func_0216D570((char *)a, 0x800);
    return 1;
}

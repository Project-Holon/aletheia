/*
 * function: func_0219D8DC
 * address:  0x0219D8DC
 * packet:   pkt_ov021_0219D8DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219D85C  0x0219D85C  thumb  ov021
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219DA80  0x0219DA80  thumb  ov021
 *   func_0219DB04  0x0219DB04  thumb  ov021
 *   func_0219DB5C  0x0219DB5C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_0219D85C(u32);
extern int func_0216DB24(int a0);
typedef unsigned char  u8;
extern u32 func_0216D7DC(void *p);
extern u32 func_0216D7E4(void *p);
extern void *func_0216E3C4(void *p);
extern void func_0219DA80(u32, u32, u32, u32);
extern int func_0219DB04(u32 a, u32 b, u32 c, u32 d);
extern void func_0219DB5C(void *a, u32 b, u32 c, u8 *d);

void func_0219D8DC(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DA80((u32)a, b, c, d);
        func_0219DB04((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}

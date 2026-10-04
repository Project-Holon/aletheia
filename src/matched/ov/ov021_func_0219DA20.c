/*
 * function: func_0219DA20
 * address:  0x0219DA20
 * packet:   pkt_ov021_0219DA20
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
 *   func_0219DBC8  0x0219DBC8  thumb  ov021
 *   func_0219DB44  0x0219DB44  thumb  ov021
 *   func_0219DAA4  0x0219DAA4  thumb  ov021
 *   func_0219DB48  0x0219DB48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_0219D85C(u32);
extern int func_0216DB24(int a0);
typedef unsigned char  u8;
extern u32 func_0216D7DC(void *p);
extern u32 func_0216D7E4(void *p);
extern void *func_0216E3C4(void *p);
extern void func_0219DBC8(u32 a, u32 b, u32 c, u8 *d);
extern void func_0219DB44(u32, u32, u32, u32);
extern void func_0219DAA4(u32, u32, u32, u32);
extern int func_0219DB48(u32 a, u32 b, u32 c, u32 d);

void func_0219DA20(u32 a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C(a) != 0 && func_0216DB24(a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DBC8(a, b, c, (u8 *)d);
        func_0219DB44(a, b, c, d);
        func_0219DAA4(a, b, c, d);
        func_0219DB48(a, b, c, d);
    }
}

/*
 * function: func_0219C814
 * address:  0x0219C814
 * packet:   pkt_ov021_0219C814
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C7EC  0x0219C7EC  thumb  ov021
 *   func_0219CFB0  0x0219CFB0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u32 func_0216D67C(u32);
extern u32 func_0216D520(u32);
extern u16 *func_0216E3C4(u32);
extern void func_0219CBD4(u32, u32, u16 *, u16 *);
extern u16 func_0219C7EC(u32, u32);
extern void func_0219CFB0(u32, u32, u16 *, u16 *, u32, u32, u32);

int func_0219C814(u32 a, u16 *b)
{
    u32 m = func_0216D520(func_0216D67C(a));
    u16 *p = func_0216E3C4(a);
    u16 loc[2];
    func_0219CBD4(m, *p, &loc[1], &loc[0]);
    if (loc[1] != 0xFFFF && (2 & loc[0]) == 0) {
        *b = func_0219C7EC(a, *p);
        return 1;
    }
    *b = 0xFFFF;
    func_0219CFB0(m, a, p, b, 0, 0, 0);
    return 0;
}

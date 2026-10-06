/*
 * function: func_021A70D0
 * address:  0x021A70D0
 * packet:   pkt_ov021_021A70D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219F058  0x0219F058  thumb  ov021
 *   func_021A35F0  0x021A35F0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A7258  0x021A7258  thumb  ov021
 *   func_021A3674  0x021A3674  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3074(unsigned char *p);
extern void func_0219F058(u32 a, u16 *o1, u16 *o2);
extern int func_021A35F0(u32 a, u32 b, u32 c, u32 d);
extern u16 func_0216D5F8(void *p);
extern void func_021A7258(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021A3674(u8 *p, u32 b, u32 c);

void func_021A70D0(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    u16 v[2];
    void *h;
    h = func_021A3074((unsigned char *)b[1]);
    func_0219F058((u32)h, &v[0], &v[1]);
    func_021A35F0(b[1], 0, 0, 0);
    if (d == 0)
        c = func_0216D5F8(h);
    func_021A7258(a, b, 1, e, c, v[0], v[1]);
    func_021A3674((u8 *)b[1], f, g);
}

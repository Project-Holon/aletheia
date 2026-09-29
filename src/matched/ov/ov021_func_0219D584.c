/*
 * function: func_0219D584
 * address:  0x0219D584
 * packet:   pkt_ov021_0219D584
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_0219D524  0x0219D524  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0216D518(u32);
extern void func_021C6AE0(u32 *);
extern void func_021C6AF0(u32 *, u32, u16);
extern void func_021C6AF8(u32 *, u32);
extern void func_021C6AFC(u32 *, u16);
extern u32 func_021C6574(u32, u32 *, u32);
extern void func_0219D524(u32 *, u32, u32);

u32 func_0219D584(u32 a, u32 *b, u32 c, u16 *d)
{
    u32 buf[9];
    u32 t;
    u32 r;
    int i;
    t = func_0216D518(a);
    func_021C6AE0(buf);
    if (d[0] != 0xFFFF) {
        func_021C6AF0(buf, t, d[0]);
    }
    if (d[1] != 0xFFFF) {
        func_021C6AF0(buf, t, d[1]);
    }
    func_021C6AF8(buf, t);
    for (i = 0; i < 3; i++) {
        if (d[i + 2] != 0xFFFF) {
            func_021C6AFC(buf, d[i + 2]);
        }
    }
    r = func_021C6574(b[1], buf, 0);
    func_0219D524(b, c, r);
    return r;
}

/*
 * function: func_02197FC0
 * address:  0x02197FC0
 * packet:   pkt_ov021_02197FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_0216D6BC(u8 *, u32);
extern void func_02163E7C(u8 *, u16);
extern void func_0216D60C(u8 *, u16);
extern void func_0216D674(u8 *, u16);
extern void func_0216D568(u8 *, u32);
extern void func_0216D7CC(u8 *);

void func_02197FC0(u8 *a, u32 b, u32 c, u16 d, u16 e)
{
    u16 *r;

    r = func_0216D6BC(a, 12);
    r[0] = e;
    r[1] = d;
    *(u32 *)(r + 2) = b;
    *(u32 *)(r + 4) = c;
    func_02163E7C(a, b);
    func_0216D60C(a, b);
    func_0216D674(a, e);
    func_0216D568(a, 0x20);
    func_0216D7CC(a);
}

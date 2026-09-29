/*
 * function: func_021984C0
 * address:  0x021984C0
 * packet:   pkt_ov021_021984C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u8 *func_0216D6BC(u8 *, u32);
extern void func_02163F10(u8 *);
extern void func_02163E7C(u8 *, u16);
extern void func_0216D568(u8 *, u32);
extern void func_0216D60C(u8 *, u16);
extern void func_0216D674(u8 *, u16);
extern void func_0216D7CC(u8 *);
extern void func_020061E4(void);

void func_021984C0(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g, u32 h)
{
    u8 *r;

    r = func_0216D6BC(a, 16);
    r[12] = b;
    *(u32 *)r = c;
    r[13] = d;
    r[14] = e;
    r[15] = f;
    *(u16 *)(r + 8) = g;
    if (c == 0) {
        func_02163F10(a);
    } else {
        func_02163E7C(a, b);
    }
    func_0216D568(a, 0xa0);
    func_0216D60C(a, b);
    func_0216D674(a, e);
    func_0216D7CC(a);
    if (h != 0) {
        func_020061E4();
    }
}

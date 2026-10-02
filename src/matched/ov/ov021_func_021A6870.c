/*
 * function: func_021A6870
 * address:  0x021A6870
 * packet:   pkt_ov021_021A6870
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A6714  0x021A6714  thumb  ov021
 *   func_021A6720  0x021A6720  thumb  ov021
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A6750  0x021A6750  thumb  ov021
 *   func_021A6768  0x021A6768  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_021A6780  0x021A6780  thumb  ov021
 *   func_021A6798  0x021A6798  thumb  ov021
 *   func_021A6BAC  0x021A6BAC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A66F8(u8 *p, u32 m);
extern void func_0216D550(u32 o, u32 v);
extern void func_021A6714(u8 *p);
extern void func_021A6720(u8 *p);
extern void func_021A3964(u32 o, u32 v);
extern void func_021A6750(u8 *p);
extern void func_021A6768(u8 *p);
extern u16 func_0216D608(u32 o);
extern u16 func_021642A4(int i);
extern void func_0216D60C(u32 o, u32 v);
extern void func_021A6780(u8 *p);
extern void func_021A6798(u8 *p);
extern void func_021A6BAC(u8 *p);

void func_021A6870(u8 *p)
{
    u32 o = *(u32 *)(p + 0x1C);

    if (func_021A66F8(p, 0x59))
        func_0216D550(o, 0x18);
    if (func_021A66F8(p, 1)) {
        func_021A6714(p);
        func_021A6720(p);
        func_021A3964(*(u32 *)(p + 0x14), 0);
    }
    if (func_021A66F8(p, 0x18)) {
        func_021A6750(p);
        func_021A6768(p);
        func_0216D60C(o, func_021642A4(func_0216D608(o)));
    }
    if (func_021A66F8(p, 0x20)) {
        func_021A6780(p);
        func_0216D60C(o, 3);
    }
    if (func_021A66F8(p, 0x40)) {
        func_021A6798(p);
        func_021A6BAC(p + 0xC);
    }
}

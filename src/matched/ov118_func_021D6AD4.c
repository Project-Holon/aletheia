/*
 * function: func_021D6AD4
 * address:  0x021D6AD4
 * packet:   pkt_ov118_021D6AD4
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D34C  0x0203D34C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02041300  0x02041300  arm
 *   func_021E0FF4  0x021E0FF4  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_0203D34C(u32 a, u16 heap);
extern void func_02045CAC(u32 h, u32 id, u32 arg);
extern int func_021D8AA8(void *);
extern u32 func_021D8FA4(void *, int);
extern void func_0201EEF4(u32 h, u32 a, u32 mon);
extern void func_0201F02C(u32 h, u32 a, u32 b);
extern void func_0201F250(u32 h, u32 a, u32 b);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021E0FF4(void *p, int a, int b);
extern void func_021E7208(void *p, int a);

void func_021D6AD4(u8 *p)
{
    func_0203D34C(0, *(u16 *)(p + 0x5F4));
    if (*(u32 *)(p + 0x118C) == 6) {
        func_02045CAC(*(u32 *)(p + 0x720), 0x98, *(u32 *)(p + 0x73C));
    } else if (*(u32 *)(p + 0x118C) == 8) {
        func_02045CAC(*(u32 *)(p + 0x720), 0x9B, *(u32 *)(p + 0x73C));
    } else if (*(u8 *)(p + 0x11ED) != 0) {
        func_02045CAC(*(u32 *)(p + 0x720), 0x82, *(u32 *)(p + 0x73C));
    } else {
        func_02045CAC(*(u32 *)(p + 0x720), 0x81, *(u32 *)(p + 0x73C));
    }
    func_0201EEF4(*(u32 *)(p + 0x724), 0, func_021D8FA4(p, func_021D8AA8(p)));
    func_0201F02C(*(u32 *)(p + 0x724), 1, *(u32 *)(p + 0x834));
    func_0201F250(*(u32 *)(p + 0x724), *(u32 *)(p + 0x738), *(u32 *)(p + 0x73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    func_021E0FF4(p, 1, 0);
    func_021E7208(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}

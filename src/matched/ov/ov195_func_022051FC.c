/*
 * function: func_022051FC
 * address:  0x022051FC
 * packet:   pkt_022051FC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02040588 0x02040588 arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(u32, int);
extern void func_02045334(u32);
extern void func_02045374(u32);
extern unsigned char func_02045730(u32);
extern void func_02041B6C(u32);
extern u32 func_0201F5DC(int, int, int, u16);
extern u32 func_02045B38(int, int, int, u16);
extern u32 func_0203101C(u16, u16, int, int);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_02028590(int, int, int, u16);
extern void func_02040588(u32 which, u32 enable);

void func_022051FC(int a, char *b)
{
    u32 p;

    func_02049B40(0x17, 5, 0, 0x20, 0x20, *(u16 *)(b + 2));
    *(u32 *)(b + 0x70) = func_020450F0(1, 0, 0, 1, 1, 1, 0);
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(b + 0x70)), 0);
    func_02045334(*(u32 *)(b + 0x70));
    *(u32 *)(b + 0x6c) = func_020450F0(1, 1, 0x13, 0x1e, 4, 1, 1);
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(b + 0x6c)), 0);
    p = *(u32 *)(b + 0x6c);
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
    *(u32 *)(b + 0x74) = func_0201F5DC(1, 2, 0, *(u16 *)(b + 2));
    *(u32 *)(b + 0x78) = func_02045B38(0, 2, 0xac, *(u16 *)(b + 2));
    *(u32 *)(b + 0x7c) = func_02045B38(0, 2, 0xcc, *(u16 *)(b + 2));
    *(u32 *)(b + 0x68) = func_0203101C(*(u16 *)(b + 2), *(u16 *)(b + 2), 1, 0);
    func_0201DD78(1, 2, 0xf);
    *(u32 *)(b + 0x80) = 0;
    *(u32 *)(b + 0x64) = 0;
    *(u32 *)(b + 0x84) = func_02028590(0xf, 1, 1, *(u16 *)(b + 2));
    *(u32 *)(b + 0x88) = 0;
    func_02040588(1, 0);
    *(u32 *)(b + 0x8c) = 0;
}

/*
 * function: func_021C6EA4
 * address:  0x021C6EA4
 * packet:   pkt_ov136_021C6EA4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008FA4 0x02008FA4 thumb
 *   func_020213AC 0x020213AC thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_0202CC70  0x0202CC70  thumb
 *   func_021C5B30 0x021C5B30 thumb
 *   func_021C61CC 0x021C61CC thumb
 *   func_021C62F4 0x021C62F4 thumb
 *   func_021C630C 0x021C630C thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C6884 0x021C6884 thumb
 *   func_021C7178 0x021C7178 thumb
 *   func_021C71A8 0x021C71A8 thumb
 *   func_021C7298 0x021C7298 thumb
 *   func_021C730C 0x021C730C thumb
 *   func_021C7350 0x021C7350 thumb
 *   func_021C7430 0x021C7430 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02027974(void *);
extern int func_020279E8(void *);
extern int func_02027A04(void *);
extern void func_021C5B30(u8 *);
extern void func_021C62F4(u8 *);
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C61CC(u8 *);
extern void func_021C6884(u8 *);
extern void func_021C7350(u8 *);
extern void func_021C66A0(u8 *, int, int);
extern void func_021C730C(u8 *);
extern void func_021C630C(u8 *, int);
extern int func_021C71A8(u8 *, int, int);
extern u32 func_02008FA4(void *);
extern u16 func_020213AC(u32);
extern void func_021C7430(u8 *, int, u16, u16);
extern int func_021C7178(u8 *, u32);
extern void func_0202CC70(void *, int);
extern void func_021C7298(u8 *, int);
int func_021C6EA4(u8 *p)
{
    func_02027974(*(void **)(*(u8 **)(p + 8) + 0x310));
    if (func_020279E8(*(void **)(*(u8 **)(p + 8) + 0x310)) == 0) {
        return 0xE;
    }
    switch (func_02027A04(*(void **)(*(u8 **)(p + 8) + 0x310))) {
    case 0:
        func_021C5B30(p);
        func_021C62F4(p);
        func_021C66B8(*(u8 **)(p + 8), 2, 0);
        func_021C61CC(*(u8 **)(p + 8));
        func_021C6884(*(u8 **)(p + 8));
        func_021C7350(p);
        func_021C66A0(*(u8 **)(p + 8), 7, 0xE);
        func_021C730C(*(u8 **)(p + 8));
        return 0xF;
    case 1:
        func_021C5B30(p);
        func_021C630C(p, 0);
        return func_021C71A8(p, 0, 0x11);
    case 2: {
        u8 k;
        func_021C5B30(p);
        k = p[0x1F];
        func_021C7430(p, 0xE, func_020213AC(func_02008FA4(*(void **)(*(u8 **)(p + 8) + k * 4 + 0x298))), k);
        *(u32 *)(p + 0x14) = 0;
        *(u32 *)(p + 0x28) = 6;
        return func_021C7178(p, 1);
    }
    case -2:
    case 3:
        func_021C5B30(p);
        func_021C62F4(p);
        func_0202CC70(**(void ***)(p + 8), 10);
        func_021C7298(*(u8 **)(p + 8), 0);
        func_021C66B8(*(u8 **)(p + 8), 2, 1);
        return 9;
    default:
        return 0xE;
    }
}

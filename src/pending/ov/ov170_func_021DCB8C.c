/*
 * function: func_021DCB8C
 * address:  0x021DCB8C
 * packet:   pkt_ov170_021DCB8C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Graphics setup in the shape of src/matched/func_021DCA7C.c (ov171).
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F34 0x02049F34 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204162C 0x0204162C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_0201F5DC 0x0201F5DC thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_020490F4(int a, int b);
extern void func_02049B68(u8 *p, int a, int b, int c, int d, int e);
extern void func_02049658(u8 *p, int a, int b, int c, int d, int e, int f);
extern u32 func_02049740(u8 *p, int a, int b, int c, int d, int e);
extern void func_020498F4(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_02049238(u8 *p);
extern void *func_02049F34(u32 arc, u32 file, void **out, u32 heap);
extern void func_02040E78(u32 a, void *src, u32 b, u32 ofs);
extern void func_020307B0(void *p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(int bg);
extern u8 *func_0204162C(int a);
extern void func_02049B40(int a, int b, int c, int d, int e, int f);
extern u32 func_020275E4(void);
extern int func_02027624(void);
extern int func_02027628(void);
extern int func_0202762C(void);
extern int func_0201F5DC(int a, int b, int c, int d);

void func_021DCB8C(unsigned char *p)
{
    u8 *h = func_020490F4(0x74, 0x4C);
    u32 base;
    u8 *src;
    u8 *dst;
    u32 i;
    func_02049658(h, 0xC, 1, 0, 0, 1, 0x4C);
    func_02049740(h, 3, 2, 0, 1, 0x4C);
    func_020498F4(h, 2, 2, 0, 0, 1, 0x4C);
    func_02049658(h, 1, 3, 0, 0, 1, 0x4C);
    func_020498F4(h, 0, 3, 0, 0, 1, 0x4C);
    func_02049B68(h, 4, 0, 0, 0x80, 0x4C);
    func_02049658(h, 0x3E, 1, 0x3E8, 0x300, 1, 0x4C);
    func_02049B68(h, 0x3F, 0, 0x180, 0x40, 0x4C);
    {
        void *pal;
        void *res = func_02049F34(func_020275E4(), 0x1F, &pal, 0x804C);
        u8 *d = ((u8 **)pal)[3];
        u32 ofs = 0x194;
        func_02040E78(0, d + 0x34, 4, ofs);
        d += 0x14;
        ofs += 0x20;
        func_02040E78(0, d, 4, ofs);
        func_020307B0(res);
    }
    func_02049658(h, 6, 5, 0, 0, 1, 0x4C);
    func_020498F4(h, 5, 5, 0, 0, 1, 0x4C);
    func_02049658(h, 6, 6, 0, 0, 1, 0x4C);
    func_02049B68(h, 7, 4, 0, 0, 0x4C);
    func_02049238(h);
    h = func_020490F4(func_020275E4(), 0x4C);
    func_02049740(h, func_02027628(), 0, 0, 0, 0x4C);
    func_02049B68(h, func_02027624(), 0, 0xE0, 0x20, 0x4C);
    func_020498F4(h, func_0202762C(), 0, 0, 0, 0, 0x4C);
    func_020413B0(0, 0, 0x15, 0x20, 3, 7);
    func_02041B6C(0);
    base = func_02049740(h, func_02027628(), 2, 0, 0, 0x4C);
    func_02049238(h);
    src = func_0204162C(0);
    dst = func_0204162C(2);
    for (i = 0; i < 0x60; i++)
        ((u16 *)(dst + 0x540))[i] = base + ((u16 *)(src + 0x540))[i];
    func_02041B6C(2);
    *(int *)(*(char **)(p + 0x2C) + 0x178) = func_0201F5DC(0, 0xA, 0, 0x4C);
    func_02049B40(0x17, 5, 0, 0x160, 0x20, 0x4C);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x4C);
}

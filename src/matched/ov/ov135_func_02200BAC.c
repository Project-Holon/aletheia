/*
 * function: func_02200BAC
 * address:  0x02200BAC
 * packet:   pkt_02200BAC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F9218  0x021F9218  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020450F0(int a, int b, int c, int d, int e, int f, int g);
extern u32 func_02045770(u32 v);
extern void func_02043B5C(u32 v, u32 k);
extern void func_021F9218(u32 win, u32 bank, u32 idx, u8 *g);
extern void func_02045334(u32 v);
extern void func_02045374(u32 v);
extern u32 func_02045730(u32 v);
extern void func_02041B6C(u32 v);

void func_02200BAC(u8 *p, u32 k)
{
    u32 v;

    *(u32 *)(p + 0xde0) = func_020450F0(4, 0xc, 0x13, 0x12, 4, 1, 1);
    func_02043B5C(func_02045770(*(u32 *)(p + 0xde0)), 0);
    func_021F9218(*(u32 *)(p + 0xde0), *(u32 *)(p + 0xb6c), k, p + 0xfa0);
    v = *(u32 *)(p + 0xde0);
    func_02045334(v);
    func_02045374(v);
    func_02041B6C(func_02045730(v));
}

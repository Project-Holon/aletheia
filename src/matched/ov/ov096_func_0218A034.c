/*
 * function: func_0218A034
 * address:  0x0218A034
 * packet:   pkt_ov096_0218A034
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_021C82F4  0x021C82F4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(u8 *);
extern void func_020113B0(u8 *, u8 *);
extern u8 func_0218A160(u8 *, int);
extern int func_021C82F4(int, int, int);

int func_0218A034(u8 *a, u8 *b)
{
    int t;
    int n;
    t = func_0201134C(a);
    n = func_0201134C(a);
    if (func_021C82F4(*(int *)(b + 0xb4), func_0218A160(b, t), 3) != 0)
        func_020113B0(a, *(u8 **)(a + 0x14) + n);
    return *(int *)(b + 0xc4);
}

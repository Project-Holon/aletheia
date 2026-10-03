/*
 * function: func_021ECE60
 * address:  0x021ECE60
 * packet:   pkt_ov093_021ECE60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern void func_02043B5C(int, int);
typedef unsigned int   u32;
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(int, s16, s16, int, int);
extern void func_02045334(int);

void func_021ECE60(u8 *a, int b)
{
    func_02043B5C(*(int *)(a + 4), 0xc);
    func_0201DD78(1, 9, 0xc);
    func_0201C7A4(*(int *)(a + 4), 0, 0, b, *(int *)(a + 0x24));
    func_02045334(*(int *)a);
    a[0x13f] = 0;
    *(u16 *)(a + 0x148) = 0;
    *(u16 *)(a + 0x14a) = 0;
    *(u16 *)(a + 0x14c) = 0;
    a[0x13e] = 1;
    a[0x141] = 0;
}

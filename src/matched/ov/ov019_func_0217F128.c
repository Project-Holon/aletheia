/*
 * function: func_0217F128
 * address:  0x0217F128
 * packet:   pkt_ov019_0217F128
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219160C  0x0219160C  thumb  ov021
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0217F044  0x0217F044  thumb  ov019
 *   func_021904C8  0x021904C8  thumb  ov021
 */

extern void func_0219160C(int a);
typedef unsigned int   u32;
extern int func_021915B4(u32 a);
extern void func_02045808(int a);
extern void func_0217F044(unsigned char *p);
extern void func_021904C8(int a);

void func_0217F128(unsigned char *base)
{
    if (*(int *)(base + 0x280C) != 0) {
        func_0219160C(*(int *)(base + 0x280C));
        func_021915B4(*(int *)(base + 0x280C));
        *(int *)(base + 0x280C) = 0;
        *(base + 0x2828) = 0;
        func_02045808(*(int *)(base + 0x2820));
        func_02045808(*(int *)(base + 0x2824));
        *(int *)(base + 0x2820) = 0;
        *(int *)(base + 0x2824) = 0;
    }
    if (*(int *)(base + 0x2808) != 0) {
        func_0217F044(base);
        func_021904C8(*(int *)(base + 0x2808));
        *(int *)(base + 0x2808) = 0;
    }
}

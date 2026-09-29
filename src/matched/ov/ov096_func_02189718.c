/*
 * function: func_02189718
 * address:  0x02189718
 * packet:   pkt_ov096_02189718
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern void func_020113B0(int, int);
extern int func_0218A160(int, int);
extern int func_0218A2FC(int, int);
extern int func_021D5BDC(int, int);

int func_02189718(int a, int b) {
    int r7;
    int r6;
    int t;
    r7 = func_0201134C(a);
    r6 = func_0201134C(a);
    t = func_0218A160(b, r7);
    t = func_0218A2FC(b, t);
    if (func_021D5BDC(t, 13)) {
        func_020113B0(a, *(int *)(a + 0x14) + r6);
    }
    return *(int *)(b + 0xc4);
}

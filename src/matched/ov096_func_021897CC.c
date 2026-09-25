/*
 * function: func_021897CC
 * address:  0x021897CC
 * packet:   pkt_ov096_021897CC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_021C82D0  0x021C82D0  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern int func_0218A160(int, int);
extern int func_021C82D0(int, int, int);

int func_021897CC(int a, int b) {
    int r6;
    int r4;
    int t;
    r6 = func_0201134C(a);
    r4 = func_0201134C(a);
    t = func_0218A160(b, r6);
    t = func_021C82D0(*(int *)(b + 0xb4), t, r4);
    *(int *)(b + 0x38) = t;
    return *(int *)(b + 0xc4);
}

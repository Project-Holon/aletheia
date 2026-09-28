/*
 * function: func_0218945C
 * address:  0x0218945C
 * packet:   pkt_ov096_0218945C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
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
extern int func_0218A2FC(int, int);
extern int func_021D5BDC(int, int);

int func_0218945C(int a, int b) {
    int t;
    int r;
    t = func_0201134C(a);
    t = func_0218A160(b, t);
    t = func_0218A2FC(b, t);
    r = 0;
    if (func_021D5BDC(t, 0) == 0) {
        r = 1;
    }
    *(int *)(b + 0x38) = r;
    return *(int *)(b + 0xc4);
}

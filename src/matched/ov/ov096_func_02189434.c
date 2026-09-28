/*
 * function: func_02189434
 * address:  0x02189434
 * packet:   pkt_ov096_02189434
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
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
extern int func_021D59B4(int, int);

int func_02189434(int a, int b) {
    int t;
    t = func_0201134C(a);
    t = func_0218A160(b, t);
    t = func_0218A2FC(b, t);
    t = func_021D59B4(t, 0x12);
    *(int *)(b + 0x38) = t;
    return *(int *)(b + 0xc4);
}

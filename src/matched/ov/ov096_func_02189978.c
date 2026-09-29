/*
 * function: func_02189978
 * address:  0x02189978
 * packet:   pkt_ov096_02189978
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A3F4  0x0218A3F4  thumb  ov096
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
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
extern int func_0218A3F4(int, u16, int);
extern int func_021D62C4(int, int);
extern int func_021D5B40(int);

int func_02189978(int a, int b) {
    int r;
    int t;
    int s;
    r = func_0201134C(a);
    t = func_0218A160(b, r);
    *(int *)(b + 0x38) = 0;
    s = func_0218A2FC(b, t);
    if (func_021D62C4(s, 0x13) == 0) {
        s = func_0218A2FC(b, t);
        s = func_021D5B40(s);
        *(int *)(b + 0x38) = func_0218A3F4(b, s, 10);
    }
    return *(int *)(b + 0xc4);
}

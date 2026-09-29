/*
 * function: func_02189800
 * address:  0x02189800
 * packet:   pkt_ov096_02189800
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
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
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
extern int func_0218A308(int, int);
extern int func_0218A0F4(int, int, int, int, int);
extern int func_021B8DE4(int, int);
extern int func_021B9AF8(int, int);
extern int func_021B99B8(int, int);
extern int func_021B9B94(int);
extern int func_021D5B68(int);
extern int func_021D5C44(int);

int func_02189800(int a, int b) {
    int r4;
    int x;
    int y;
    int r5;
    int t;
    r4 = func_0201134C(a);
    x = func_0201134C(a);
    y = func_0218A160(b, r4);
    r5 = func_021B8DE4(*(int *)(b + 0xb0), y);
    r4 = func_021B9AF8(*(int *)(b + 0xb8), r5);
    r5 = func_021B99B8(*(int *)(b + 0xb0), r5);
    for (; r5 < func_021B9B94(r4); r5++) {
        t = func_0218A308(r4, (u8)r5);
        if (func_021D5B68(t) == 0) {
            t = func_0218A2FC(b, y);
            t = func_021D5C44(t);
            if (func_0218A0F4(a, 0, t, 100, x) != 0) {
                break;
            }
        }
    }
    return *(int *)(b + 0xc4);
}

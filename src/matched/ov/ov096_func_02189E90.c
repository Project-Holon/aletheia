/*
 * function: func_02189E90
 * address:  0x02189E90
 * packet:   pkt_ov096_02189E90
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5B68  0x021D5B68  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(u8 *);
extern int func_0218A0F4(u8 *, int, int, int, int);
extern u8 func_0218A160(u8 *, int);
extern int func_0218A2FC(u8 *, int);
extern int func_021D5B68(int);

int func_02189E90(u8 *a, u8 *b, int c)
{
    int t;
    int n;
    t = func_0201134C(a);
    n = func_0201134C(a);
    return func_0218A0F4(a, c, func_021D5B68(func_0218A2FC(b, func_0218A160(b, t))), 1, n);
}

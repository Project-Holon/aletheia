/*
 * function: func_0218979C
 * address:  0x0218979C
 * packet:   pkt_ov096_0218979C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern int func_021EF948(int);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);

int func_0218979C(int a, int b) {
    int r;
    int r2;
    int t;
    r = func_0201134C(a);
    r2 = func_0201134C(a);
    t = func_021EF948(r);
    func_0218A0F4((u8 *)a, 2, t, 1, r2);
    return *(int *)(b + 0xc4);
}

/*
 * function: func_02189668
 * address:  0x02189668
 * packet:   pkt_ov096_02189668
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_0201134C  0x0201134C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);

int func_02189668(int a, int b) {
    int r;
    r = func_0201134C(a);
    func_0218A0F4((u8 *)a, 2, ((u8 *)b)[0x94] & 1, ((u8 *)b)[0x95] & 1, r);
    return *(int *)(b + 0xc4);
}

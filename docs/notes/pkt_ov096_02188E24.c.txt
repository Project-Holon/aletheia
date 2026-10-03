/*
 * function: func_02188E24
 * address:  0x02188E24
 * packet:   pkt_ov096_02188E24
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Lever: x is a u16 local from the evidenced u16 callee return. Its word
 * spill reload stays after the outgoing fifth-argument store. All 5
 * relocation sites resolve; trailing two-byte padding is EXACT*.
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021C81C8  0x021C81C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0201134C(u8 *);
extern int func_0218A0F4(u8 *, int, int, int, int);
extern u16 func_021C81C8(u8 *, u8 *, int);

int func_02188E24(u8 *a, u8 *b)
{
    int k;
    int m;
    u16 x;
    int y;

    k = func_0201134C(a);
    m = func_0201134C(a);
    x = func_021C81C8(*(u8 **)(b + 0xb4), *(u8 **)(b + 0xbc), 1);
    y = func_021C81C8(*(u8 **)(b + 0xb4), *(u8 **)(b + 0xc0), 1);
    switch (k) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    }
    func_0218A0F4(a, k, x, y, m);
    return *(int *)(b + 0xc4);
}

/*
 * function: func_021C11A4
 * address:  0x021C11A4
 * packet:   pkt_ov217_021C11A4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C1194  0x021C1194  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;

struct Pos {
    s16 a;
    s16 b;
    s16 c;
};

extern void func_021C1194(u8 *p, struct Pos *v);

void func_021C11A4(u8 *p, int a1)
{
    struct Pos v;
    s16 y = *(s16 *)(p + 0x1B6);
    s16 x = *(s16 *)(p + 0x1B4);
    v.a = x;
    v.b = y;
    v.c = a1;
    func_021C1194(p, &v);
}

/*
 * function: func_021736A0
 * address:  0x021736A0
 * packet:   pkt_ov012_021736A0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save), called from ov019 func_0217BD9C. The two
 * trailing halfwords are both loaded before either is stored, in source
 * order; only a volatile source pointer keeps the scheduler from hoisting
 * s[3]'s load above s[2]'s (plain temporaries swap r1/r2).
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021736A0(u8 *a, volatile u16 *s)
{
    u8 *p = a + 0x2830;
    u16 x, y;
    *(u16 *)(p + 4) = s[0];
    *(u16 *)(p + 6) = s[1];
    x = s[2];
    y = s[3];
    *(u16 *)(p + 8) = x;
    *(u16 *)(p + 10) = y;
    p[0xf] = 0;
    (*(u16 *)(p + 0xc))++;
    p[0xe] = 1;
}

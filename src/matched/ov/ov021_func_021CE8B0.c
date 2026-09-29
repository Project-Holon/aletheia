/*
 * function: func_021CE8B0
 * address:  0x021CE8B0
 * packet:   pkt_ov021_021CE8B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021CE934  0x021CE934  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int func_0203EFC8(const void *a, const void *b, int n);
extern void func_021CE934(u8 *p, u8 *e, u8 i);
extern void func_02082D44(void *src, void *dst, int n);

void func_021CE8B0(u8 *p, u8 *e, int i)
{
    u8 *t;

    t = p + 0x55a;
    if (func_0203EFC8(e + 0x23, t + i * 6, 6)) {
        func_021CE934(p, e, i);
        func_02082D44(e + 0x23, t + i * 6, 6);
    }
}

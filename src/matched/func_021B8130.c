/*
 * function: func_021B8130
 * address:  0x021B8130
 * packet:   pkt_021C2AD0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When bit 1 of a1[0x2d] is set, hands the two sub-objects (a1+0xc and
 * a0+0xa) to func_021B85D0; otherwise there is nothing to do and it returns 1.
 * The test is the shift pair (v << 30) >> 31, not an AND against 2, and the
 * shifted value has to be unsigned or the image's `lsrs` comes out `asrs`.
 *
 * symbols:
 *   func_021B85D0  0x021B85D0  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021B85D0(void *a, void *b);

int func_021B8130(void *a0, u8 *a1)
{
    if ((((u32)a1[0x2d] << 30) >> 31) == 0)
        return 1;
    return func_021B85D0(a1 + 0xc, (u8 *)a0 + 0xa);
}

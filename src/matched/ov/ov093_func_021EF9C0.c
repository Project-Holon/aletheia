/*
 * function: BTL_FIELD_StoreCountdown
 * address:  0x021EF9C0
 * packet:   pkt_021EF9C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 */

int *BTL_FIELD_StoreCountdown(int *p, int a, int b)
{
    p[0] = a;
    p[1] = b;
    return p;
}

/*
 * function: BTL_FIELD_ClearCountdown
 * address:  0x021EF9C8
 * packet:   pkt_ov093_021EF9C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 */

void BTL_FIELD_ClearCountdown(int *p)
{
    p[0] = 0;
    p[1] = 0;
}

/*
 * function: BTL_CLIENT_DisableCounter
 * address:  0x021D3FD0
 * packet:   pkt_ov093_021D3FD0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 */

void BTL_CLIENT_DisableCounter(unsigned char *p)
{
    p[2] |= 0x20;
}

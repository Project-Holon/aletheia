/*
 * function: BTL_EVENT_GetFactorPokeId
 * address:  0x021D70AC
 * packet:   pkt_021D70AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 */

unsigned char BTL_EVENT_GetFactorPokeId(unsigned char *p)
{
    return p[0x3b];
}

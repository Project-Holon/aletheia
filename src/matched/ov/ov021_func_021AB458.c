/*
 * function: MAP_ATTR_IsSlopeYA
 * address:  0x021AB458
 * packet:   pkt_ov021_021AB458
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

int MAP_ATTR_IsSlopeYA(int id)
{
    if (id == 0x53 || (unsigned short)(id + 0xFFAB) <= 1)
        return 1;
    return 0;
}

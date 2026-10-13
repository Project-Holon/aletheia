/*
 * function: BTL_EVENT_GetClientPartyCount
 * address:  0x021D6E04
 * packet:   pkt_021D6E04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 */

unsigned char BTL_EVENT_GetClientPartyCount(unsigned char *p)
{
    return p[0xd0];
}

/*
 * function: INTRUDE_COMM_GetPartnerTallyValid
 * address:  0x021756A4
 * packet:   pkt_021756A4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

u8 INTRUDE_COMM_GetPartnerTallyValid(char *p)
{
    return p[0x35a];
}

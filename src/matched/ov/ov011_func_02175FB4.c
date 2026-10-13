/*
 * function: INTRUDE_COMM_GetMemberNameNetId
 * address:  0x02175FB4
 * packet:   pkt_ov011_02175FB4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

int INTRUDE_COMM_GetMemberNameNetId(u8 *p)
{
    return p[0x10];
}

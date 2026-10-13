/*
 * function: INTRUDE_COMM_ClearJoinReply
 * address:  0x02176200
 * packet:   pkt_02176200
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void INTRUDE_COMM_ClearJoinReply(char *p)
{
    p[0x1a3] = 0;
}

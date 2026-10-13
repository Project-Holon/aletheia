/*
 * function: UNION_COMM_ClearPartnerSelects
 * address:  0x02173518
 * packet:   pkt_02173518
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

void UNION_COMM_ClearPartnerSelects(unsigned char *p)
{
    p[0x19] = 0xff;
    p[0x1b] = 0xff;
    p[0x1a] = 0xff;
}

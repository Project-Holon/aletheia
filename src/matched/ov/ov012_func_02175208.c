/*
 * function: COLOSSEUM_ClearConfirmCount
 * address:  0x02175208
 * packet:   pkt_ov012_02175208
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled leaf (prints as .word in ov012.s); called from
 *           ov019 UNION_ONESELF_ColosseumPartyExchangeMain.
 */

typedef unsigned char u8;

void COLOSSEUM_ClearConfirmCount(u8 *p)
{
    p[0x161] = 0;
}

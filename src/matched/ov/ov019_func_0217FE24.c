/*
 * function: COLOSSEUM_IsPositionsReceived
 * address:  0x0217FE24
 * packet:   pkt_ov019_0217FE24
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     unlabelled leaf (prints as .word in ov019.s); called from
 *           UNION_ONESELF_ColosseumPartyExchangeMain.
 */

typedef unsigned char u8;

int COLOSSEUM_IsPositionsReceived(u8 *p)
{
    if (p[0x160] == 1)
        return 1;
    return 0;
}

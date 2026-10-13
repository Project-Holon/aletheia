/*
 * function: COLOSSEUM_ClearPositionsReceived
 * address:  0x0217FE38
 * packet:   pkt_ov019_0217FE38
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     unlabelled leaf (prints as .word in ov019.s; ov018 labels a
 *           different function at the same address); called from
 *           UNION_ONESELF_ColosseumPartyExchangeMain.
 */

typedef unsigned char u8;

void COLOSSEUM_ClearPositionsReceived(u8 *p)
{
    p[0x160] = 0;
}

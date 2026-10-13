/*
 * function: COLOSSEUM_GetMyChoiceReply
 * address:  0x021750D0
 * packet:   pkt_ov012_021750D0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

u8 COLOSSEUM_GetMyChoiceReply(u8 *p)
{
    return p[0xdd];
}

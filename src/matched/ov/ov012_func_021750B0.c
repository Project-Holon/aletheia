/*
 * function: COLOSSEUM_SetMyChoice
 * address:  0x021750B0
 * packet:   pkt_ov012_021750B0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

void COLOSSEUM_SetMyChoice(u8 *p, int v)
{
    p[0xdc] = v;
    p[0xdd] = 0xff;
}

/*
 * function: PSEL_GRAPHIC_SplitColor
 * address:  0x021BB520
 * packet:   pkt_021BB520
 * region:   ov223
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

void PSEL_GRAPHIC_SplitColor(int v, unsigned short *a, unsigned short *b, unsigned short *c)
{
    *a = v & 0x1f;
    *b = (v & 0x3e0) >> 5;
    *c = (v & 0x7c00) >> 10;
}

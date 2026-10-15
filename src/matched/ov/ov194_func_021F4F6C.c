/*
 * function: NAMEIN_GRAPHIC_GetPairEntry
 * address:  0x021F4F6C
 * packet:   pkt_021F4F6C
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

unsigned short NAMEIN_GRAPHIC_GetPairEntry(char *base, int i, int j)
{
    return *(unsigned short *)(base + i * 6 + 2 + j * 2);
}

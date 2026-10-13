/*
 * function: TOWNMAP_GRH_GetSpriteResourceId
 * address:  0x021BBB1C
 * packet:   pkt_021BBB1C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int TOWNMAP_GRH_GetSpriteResourceId(char *p, int i)
{
    return *(int *)(p + i * 4 + 0x18);
}

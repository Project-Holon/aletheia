/*
 * function: ZKNSEARCH_MAIN_ShowActorsPage1
 * address:  0x021BF480
 * packet:   pkt_ov210_021BF480
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);

void ZKNSEARCH_MAIN_ShowActorsPage1(int p)
{
    ZKNSEARCH_MAIN_SetActorVisible(p, 3, 0);
    ZKNSEARCH_MAIN_SetActorVisible(p, 4, 0);
    ZKNSEARCH_MAIN_SetActorVisible(p, 2, 1);
}

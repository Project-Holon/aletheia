/*
 * function: ZKNSEARCH_MAIN_PlaceProgressActor
 * address:  0x021BFE84
 * packet:   pkt_ov210_021BFE84
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);

void ZKNSEARCH_MAIN_PlaceProgressActor(int p, int n)
{
    ZKNSEARCH_MAIN_SetActorVisible(p, 8, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos((char *)p, 8, (short)(n * 2 + 8), 0xa8, (int)0);
}

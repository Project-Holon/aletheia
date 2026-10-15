/*
 * function: ZKNSEARCH_MAIN_HideAllActors
 * address:  0x021BF38C
 * packet:   pkt_021BF38C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible  0x021BEDF0  thumb ov210
 */

typedef unsigned char u8;

extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);

void ZKNSEARCH_MAIN_HideAllActors(u8 *p)
{
    unsigned int i;

    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 1, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xA, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xB, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xC, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xD, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xE, 0);
    for (i = 0; i < 0xE; i++) {
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 0xF, 0);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 0x1D, 0);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 0x2B, 0);
    }
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 7, 0);
}

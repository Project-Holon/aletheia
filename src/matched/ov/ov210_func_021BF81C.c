/*
 * function: ZKNSEARCH_MAIN_HideColumnActors
 * address: 0x021BF81C
 * packet: pkt_ov210_021BF81C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 */
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
void ZKNSEARCH_MAIN_HideColumnActors(char *p)
{
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 10, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 11, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 12, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 13, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 14, 0);
}

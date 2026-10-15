/*
 * function: ZKNSEARCH_MAIN_ShowActorsPage2
 * address: 0x021BF4A4
 * packet: pkt_ov210_021BF4A4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 */
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
void ZKNSEARCH_MAIN_ShowActorsPage2(char *p)
{
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 3, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 4, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 2, 1);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 5, 1);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 6, 1);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0, 1);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 1, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0, 0xfc, 12, 0);
}

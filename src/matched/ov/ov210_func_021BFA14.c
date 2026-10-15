/*
 * function: ZKNSEARCH_MAIN_PlaceColumnActor3
 * address: 0x021BFA14
 * packet: pkt_ov210_021BFA14
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
void ZKNSEARCH_MAIN_PlaceColumnActor3(char *p, int y, int flag)
{
    int coord;
    if (flag == 1) {
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, 1);
        coord = y + 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, 9, 0x8c, coord, 0);
    } else {
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 11, 1);
        coord = y + 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, 11, 0x8c, coord, 1);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 13, 1);
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, 13, 0x8c, coord, 1);
    }
}

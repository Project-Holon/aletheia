/*
 * function: ZKNSEARCH_MAIN_PlaceColumnActor
 * address: 0x021BF7B0
 * packet: pkt_ov210_021BF7B0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 */
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
void ZKNSEARCH_MAIN_PlaceColumnActor(char *p, int idx, int y, int flag)
{
    int index;
    int coord;
    if (flag == 1) {
        index = idx + 9;
        ZKNSEARCH_MAIN_SetActorVisible((int)p, index, 1);
        coord = y + 12;
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, index, 0x8c, coord, 0);
    } else {
        int other = idx + 11;
        ZKNSEARCH_MAIN_SetActorVisible((int)p, other, 1);
        coord = y + 12;
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, other, 0x8c, coord, 1);
        index = idx + 13;
        ZKNSEARCH_MAIN_SetActorVisible((int)p, index, 1);
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, index, 0x8c, coord, 1);
    }
}

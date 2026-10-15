/*
 * function: ZKNSEARCH_MAIN_PlaceColumnActor1
 * address: 0x021BF85C
 * packet: pkt_ov210_021BF85C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 * Caller sign-extends r3 to 16 bits before EE38; existing callee uses u16.
 */
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
void ZKNSEARCH_MAIN_PlaceColumnActor1(char *p, int i, int flag)
{
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, flag);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 11, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 13, 0);
    if (flag == 1)
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, 9, 0x8c, (short)(i * 24 + 12), 0);
}

/*
 * function: ZKNSEARCH_MAIN_MoveScrollActors
 * address: 0x021BFCE4
 * packet: pkt_ov210_021BFCE4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZKNSEARCH_MAIN_GetActorVisible 0x021BEE04 thumb
 *   ZKNSEARCH_MAIN_GetActorSurfacePos 0x021BEE58 thumb
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb
 */
typedef unsigned int u32;
extern int ZKNSEARCH_MAIN_GetActorVisible(int p, int i);
extern void ZKNSEARCH_MAIN_GetActorSurfacePos(char *, int, short *, short *, unsigned short);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);

void ZKNSEARCH_MAIN_MoveScrollActors(char *p, int dx)
{
    u32 i;
    struct { short x; short y; } pos;

    for (i = 0xF; i < 0x1D; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible((int)p, i)) {
            ZKNSEARCH_MAIN_GetActorSurfacePos(p, i, &pos.y, &pos.x, 0);
            ZKNSEARCH_MAIN_SetActorSurfacePos(p, i, pos.y, (short)(pos.x + dx), 0);
            if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
                ZKNSEARCH_MAIN_SetActorVisible((int)p, i, 0);
            }
        }
    }
    ZKNSEARCH_MAIN_GetActorSurfacePos(p, 9, &pos.y, &pos.x, 0);
    ZKNSEARCH_MAIN_SetActorSurfacePos(p, 9, pos.y, (short)(pos.x + dx), 0);
    if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, 0);
    }
    for (i = 0x1D; i < 0x2B; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible((int)p, i)) {
            ZKNSEARCH_MAIN_GetActorSurfacePos(p, i, &pos.y, &pos.x, 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(p, i, pos.y, (short)(pos.x + dx), 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(p, i + 0xE, pos.y, (short)(pos.x + dx), 1);
            if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
                ZKNSEARCH_MAIN_SetActorVisible((int)p, i, 0);
                ZKNSEARCH_MAIN_SetActorVisible((int)p, (int)i + 0xE, 0);
            }
        }
    }
    ZKNSEARCH_MAIN_GetActorSurfacePos(p, 0xB, &pos.y, &pos.x, 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0xB, pos.y, (short)(pos.x + dx), 1);
    ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0xD, pos.y, (short)(pos.x + dx), 1);
    if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xB, 0);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xD, 0);
    }
}

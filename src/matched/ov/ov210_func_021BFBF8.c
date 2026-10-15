/*
 * function: ZKNSEARCH_MAIN_MoveColumnActors
 * address:  0x021BFBF8
 * packet:   pkt_ov210_021BFBF8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_GetActorVisible 0x021BEE04 thumb ov210
 *   ZKNSEARCH_MAIN_GetActorSurfacePos 0x021BEE58 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 * Addresses are Black-image addresses.
 */

extern int ZKNSEARCH_MAIN_GetActorVisible(int p, int i);
extern void ZKNSEARCH_MAIN_GetActorSurfacePos(char *p, int idx, short *outA, short *outB, unsigned short in);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);

void ZKNSEARCH_MAIN_MoveColumnActors(int p, int v)
{
    unsigned i;
    short pos[2];

    for (i = 9; i <= 10; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible(p, i) != 0) {
            int t;

            ZKNSEARCH_MAIN_GetActorSurfacePos((char *)p, i, &pos[1], &pos[0], 0);
            ZKNSEARCH_MAIN_SetActorSurfacePos((char *)p, i, (short)pos[1], (short)(pos[0] + v), (int)0);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc)
                ZKNSEARCH_MAIN_SetActorVisible(p, i, 0);
        }
    }
    for (i = 11; i <= 12; i++) {
        if (ZKNSEARCH_MAIN_GetActorVisible(p, i) != 0) {
            int t;

            ZKNSEARCH_MAIN_GetActorSurfacePos((char *)p, i, &pos[1], &pos[0], 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos((char *)p, i, (short)pos[1], (short)(pos[0] + v), (int)1);
            ZKNSEARCH_MAIN_SetActorSurfacePos((char *)p, i + 2, (short)pos[1], (short)(pos[0] + v), (int)1);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc) {
                ZKNSEARCH_MAIN_SetActorVisible(p, i, 0);
                ZKNSEARCH_MAIN_SetActorVisible(p, i + 2, 0);
            }
        }
    }
}

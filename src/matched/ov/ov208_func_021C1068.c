/*
 * function: ZUKAN_DETAIL_AREA_FindNearestTown
 * address: 0x021C1068
 * packet: pkt_ov208_021C1068
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_DETAIL_AREA_GetTownPointDistance 0x021C100C thumb ov208
 */
typedef unsigned char u8;
extern int ZUKAN_DETAIL_AREA_GetTownPointDistance(void *, char *, int, u8, u8, u8, unsigned *);
u8 ZUKAN_DETAIL_AREA_FindNearestTown(void *heap, char *p, int key, u8 x, u8 y)
{
    unsigned distance, bestDistance;
    u8 best = 255, i;
    for (i = 0; i < 61; i++) {
        if (ZUKAN_DETAIL_AREA_GetTownPointDistance(heap, p, key, i, x, y, &distance)) {
            if (best == 255) {
                best = i;
                bestDistance = distance;
            } else if (bestDistance > distance) {
                best = i;
                bestDistance = distance;
            }
        }
    }
    return best;
}

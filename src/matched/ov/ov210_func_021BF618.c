/*
 * function: ZKNSEARCH_MAIN_ShowEntry6Actor
 * address: 0x021BF618
 * packet: pkt_ov210_021BF618
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorAnim 0x021BED98 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 */
#include "../include/Obj14678.h"
extern void ZKNSEARCH_MAIN_SetActorAnim(char *, int, int);
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
void ZKNSEARCH_MAIN_ShowEntry6Actor(char *p)
{
    unsigned char v = (*(unsigned char **)(*(char * *)&((struct Obj14678 *)p)->f0 + 8))[6];
    if (v != 0xff) {
        ZKNSEARCH_MAIN_SetActorAnim(p, 7, v);
        ZKNSEARCH_MAIN_SetActorSurfacePos(p, 7, 0x40, 0x68, 0);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 7, 1);
    } else {
        ZKNSEARCH_MAIN_SetActorVisible((int)p, 7, 0);
    }
}

/*
 * function: ZKNSEARCH_MAIN_LayoutScrollActors
 * address: 0x021BF658
 * packet: pkt_ov210_021BF658
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_PlacePageActor 0x021BFB8C thumb ov210
 */
#include "../include/Obj25628.h"
extern int FRAME_LIST_GetScrollPos(char *);
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_PlacePageActor(char *ctx, unsigned long slot, int y, int flag);
void ZKNSEARCH_MAIN_LayoutScrollActors(char *p)
{
    short base = FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj25628 *)p)->f1E0);
    short i;
    for (i = 0; i < 14; i++) {
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 15, 0);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 29, 0);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 43, 0);
    }
    for (i = 0; i < 5; i++) {
        ZKNSEARCH_MAIN_PlacePageActor(p, (unsigned short)(base + i), (short)(i * 40), 1);
        if (base - (i + 1) >= 0)
            ZKNSEARCH_MAIN_PlacePageActor(p, (unsigned short)(base - (i + 1)), (short)(192 - (i + 1) * 40), 0);
    }
}

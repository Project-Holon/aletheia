/*
 * function: GURU2_MAIN_ShowResultNames
 * address: 0x021DF3E8
 * packet: pkt_ov137_021DF3E8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021DF432..021DF434 is two zero alignment bytes.
 * symbols:
 *   GURU2_MAIN_PrintPlayerName 0x021E0450 thumb ov137
 */
#include "../include/Obj06540.h"
typedef unsigned char u8;
extern void GURU2_MAIN_PrintPlayerName(u8 *p, void *text, int index, int a);
int GURU2_MAIN_ShowResultNames(u8 *p)
{
    int index, i, count, selected;
    index = (*(int **)(p + 40))[4];
    ((struct Obj06540 *)p)->f5C = 0;
    for (i = 0; i < ((struct Obj06540 *)p)->f30; i++) {
        selected = *(int *)(p + 748 + index * 180);
        GURU2_MAIN_PrintPlayerName(p, (void *)(*(int *)(p + 164 + selected * 4)), i, selected);
        count = ((struct Obj06540 *)p)->f30;
        index = (index + 1) % count;
    }
    ((struct Obj06540 *)p)->fC = 0;
    ((struct Obj06540 *)p)->f0 = 36;
    return 0;
}

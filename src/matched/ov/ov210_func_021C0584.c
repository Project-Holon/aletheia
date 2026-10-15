/*
 * function: ZKNSEARCH_RESULT_SetRow1
 * address:  0x021C0584
 * packet:   pkt_ov210_021C0584
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_PrintListRow 0x021BEC60 thumb ov210
 *   ZKNSEARCH_MAIN_PlaceColumnActor 0x021BF7B0 thumb ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04620.h"

typedef unsigned char u8;

typedef unsigned int   u32;
extern void ZKNSEARCH_MAIN_PrintListRow(int p, int *a, u32 b);
extern void ZKNSEARCH_MAIN_PlaceColumnActor(char *p, int idx, int y, int flag);

void ZKNSEARCH_RESULT_SetRow1(int p, unsigned a, int b, int c, int d)
{
    ZKNSEARCH_MAIN_PrintListRow(p, (int *)b, *(int *)(p + a * 4 + 0x1e4));
    if ((*(u8 **)(*(int * *)&((struct Obj04620 *)p)->f0 + 2))[1] == a)
        ZKNSEARCH_MAIN_PlaceColumnActor((char *)p, 0, c, d);
}

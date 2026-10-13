/*
 * function: func_021BCBB4
 * address:  0x021BCBB4
 * packet:   pkt_ov016_021BCBB4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      disp (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   DWCi_CELLlSetPosition  0x021d5118  arm  ov016
 *   gButtonWork  0x021de508  data
 *   sButtonCountByKind  0x021da008  data
 *   sButtonPositionIndex  0x021da026  data
 *   sButtonPositions  0x021da010  data
 */

#include "../include/G_tagMEMBTN.h"

typedef _Bool bool;

extern struct tagMEMBTN *gButtonWork;

typedef struct tagCOORD { unsigned short x, y; } COORD;

extern const unsigned char sButtonCountByKind[];
extern const unsigned char sButtonPositionIndex[][2];
extern const COORD sButtonPositions[];
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);

void func_021BCBB4(int y)
{
    int btnNum;
    int cy;
    int i;

    btnNum = sButtonCountByKind[gButtonWork->kind];
    DWCi_CELLlSetPosition(gButtonWork->cellBack, -1, 0, y);
    for (i = 0; i < btnNum; i++) {
        DWCi_CELLlSetPosition(gButtonWork->cellButton[i], -1, sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]].x, y + 4);
    }
}

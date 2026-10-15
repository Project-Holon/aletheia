/*
 * function: COMM_BTL_DEMO_MAIN_RefreshRowText
 * address:  0x021BA2E0
 * packet:   pkt_021BA2E0
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_BTL_DEMO_MAIN_DrawRowText 0x021BA330 thumb
 */
#include "../include/Obj08419.h"

extern void COMM_BTL_DEMO_MAIN_DrawRowText(void *, int);

void COMM_BTL_DEMO_MAIN_RefreshRowText(char *a)
{
    if (*(int *)&((struct Obj08419 *)a)->f50 == 0x2d)
        COMM_BTL_DEMO_MAIN_DrawRowText(a, ((struct Obj08419 *)a)->fC);
}
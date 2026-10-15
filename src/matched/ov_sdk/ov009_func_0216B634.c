/*
 * function: DWC_SetConnectionClosedCallback
 * address:  0x0216B634
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a at +0x88 and b at +0x8c of the current object; 0 when the block
 * is absent, 1 when it was written.
 *
 * symbols:
 *   gDwcGlobalState  0x021AA878  data

 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal gDwcGlobalState;

int DWC_SetConnectionClosedCallback(int a, int b)
{
    char *p = *(char **)(((char *)&gDwcGlobalState) + 4);

    if (p == 0) return 0;
    *(int *)(p + 0x88) = a;
    p = *(char **)(((char *)&gDwcGlobalState) + 4);
    *(int *)(p + 0x8c) = b;
    return 1;
}



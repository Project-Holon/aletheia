/*
 * function: DWCi_SetState
 * address:  0x0216BC84
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies the +0x24 link of the current object to +0x28 and then sets the
 * +0x24 link to v.
 *
 * symbols:
 *   gDwcGlobalState  0x021AA878  data

 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal gDwcGlobalState;

void DWCi_SetState(int v)
{
    char *p = *(char **)(((char *)&gDwcGlobalState) + 4);

    *(int *)(p + 0x28) = *(int *)(p + 0x24);
    p = *(char **)(((char *)&gDwcGlobalState) + 4);
    *(int *)(p + 0x24) = v;
}



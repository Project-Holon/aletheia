/*
 * function: func_0216B994
 * address:  0x0216B994
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word at +0x24 of the block held at +0x4 of the module state object, zero when the block is unset.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;

int func_0216B994(void)
{
    int *p = *(int **)(((char *)&g_021AA878) + 4);

    return p != 0 ? *(int *)((char *)p + 0x24) : 0;
}

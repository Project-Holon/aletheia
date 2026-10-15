/*
 * function: FADE_IsActive
 * address:  0x0204E804
 * packet:   pkt_0204E804
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Direct non-SDK callee of the ov195 dependency tree rooted at
 * SHINKA_DEMO_Main: an ARM9 boolean accessor, `g->f0 != 0`, reached by
 * `blx 0x0204E804` from the root's state 23 case.
 *
 * symbols:
 *   g_02146A7C  0x02146A7C  data
 */

#include "../include/G_Run0204E720.h"

extern struct Run0204E720 *g_02146A7C;

int FADE_IsActive(void)
{
    return g_02146A7C->unk00 != 0;
}

/*
 * function: STARTMENU_BeginFadeIn
 * address:  0x021BC080
 * packet:   pkt_ov088_021BC080
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EXACT*: extent runs long; the follower at 0x021BC0AC is an unlabelled leaf
 * (function_starts seed).
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 */
#include "../include/Obj20825.h"

extern void WIPE_SYS_Start(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);

int STARTMENU_BeginFadeIn(char *p, int v)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0xb);
    ((struct Obj20825 *)p)->f144 = v;
    return 2;
}

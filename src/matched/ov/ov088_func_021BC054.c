/*
 * function: STARTMENU_BeginFadeOut
 * address:  0x021BC054
 * packet:   pkt_ov088_021BC054
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent runs 2 bytes past the compiled function;
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 */
#include "../include/Obj20824.h"

extern void WIPE_SYS_Start(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);

int STARTMENU_BeginFadeOut(char *p, int v)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0xb);
    ((struct Obj20824 *)p)->f144 = v;
    return 2;
}

/*
 * function: func_021C3480
 * address:  0x021C3480
 * packet:   pkt_021C3480
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PM_VOICE_IsAnyActive  0x02006650  thumb
 *   PM_VOICE_StopAll  0x020065D8  thumb

 * BLOCKED.  Unverifiable: PM_VOICE_StopAll resolves only through the `matched` class and layout/matched/ov093 holds BTL_MAIN_ReturnZero in two shards, which aborts every manifest load.
 */
#include "../include/Obj00146.h"


extern int PM_VOICE_IsAnyActive(void);
extern void PM_VOICE_StopAll(void);

void func_021C3480(int unused, char *p, int key)
{
    int v;

    if (((struct Obj00146 *)p)->f68 != 0) {
        v = PM_VOICE_IsAnyActive();
        if (v != 0)
            PM_VOICE_StopAll();
        ((struct Obj00146 *)p)->f68 = 0;
    }
    ((struct Obj00146 *)p)->f74 = 0;
}


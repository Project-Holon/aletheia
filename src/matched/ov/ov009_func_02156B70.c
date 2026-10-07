/*
 * function: func_02156B70
 * address:  0x02156B70
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *
 * Reads the signed halfword at +0x782 of the ov009 work block held in the
 * bss pointer at 0x021A8264, or 0 when no block is allocated.  A leaf with
 * no lr-saving prologue whose only caller is in arm9 (sub_0200F698), so
 * the listing emits it as data words.
 */

#include "../include/G__anon_Work.h"

typedef signed short s16;

extern struct _anon_Work *g_021A8264;

s16 func_02156B70(void)
{
    if (g_021A8264 != 0)
        return g_021A8264->val;
    return 0;
}

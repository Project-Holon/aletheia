/*
 * function: DWC_RAP_IsUserDataChanged
 * address:  0x02156C84
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte at +0x7a2 of the block the module pointer holds.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 */

#include "../include/G__anon_Work.h"

extern struct _anon_Work *g_021A8264;

unsigned char DWC_RAP_IsUserDataChanged(void)
{
    return *(unsigned char *)(((char *)g_021A8264) + 0x7a2);
}


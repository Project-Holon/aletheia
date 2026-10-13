/*
 * function: DWC_RAP_SetRecvCallbacks
 * address:  0x02155648
 * packet:   pkt_ov009_02155648
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores two words at +0x27C and +0x280 of the block the module pointer holds.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 */

typedef int s32;

extern char *g_021A8264;

void DWC_RAP_SetRecvCallbacks(s32 a, s32 b)
{
    *(s32 *)(g_021A8264 + 0x27C) = a;
    *(s32 *)(g_021A8264 + 0x280) = b;
}

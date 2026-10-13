/*
 * function: SCRCMD_WORK_SetFadeParam
 * address:  0x0215A6B8
 * packet:   pkt_ov010_0215A6B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: stores b at offset 0x108 of the block a[0x20] points to.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void SCRCMD_WORK_SetFadeParam(u32 *a, u32 b)
{
    *(u32 *)(a[8] + 0x108) = b;
}

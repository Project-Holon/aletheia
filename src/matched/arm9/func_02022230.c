/*
 * function: WIPE_ResetBrightness
 * address:  0x02022230
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The companion forwarder to WIPE_ResetWndMask: it passes the caller's engine
 * selector straight through to WIPE_SetBrightness and supplies the unused second
 * argument as zero.  Same pool-word-and-`bx` tail call shape.
 *
 * symbols:
 *   WIPE_SetBrightness  0x020222CC  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_ResetBrightness.c \
 *       --func WIPE_ResetBrightness --addr 0x02022230 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

extern void WIPE_SetBrightness(u32 which, int brightness);

void WIPE_ResetBrightness(u32 which)
{
    WIPE_SetBrightness(which, 0);
}

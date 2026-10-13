/*
 * function: GFL_NET_DEVWIFI_GetSignalLevel
 * address:  0x021552DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns.
 *
 * symbols:
 *   DWC_GetLinkLevel  0x0205CCD8  arm
 */

extern int DWC_GetLinkLevel(void);

int GFL_NET_DEVWIFI_GetSignalLevel(void)
{
    return 3 - DWC_GetLinkLevel();
}

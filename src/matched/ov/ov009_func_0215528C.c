/*
 * function: GFL_NET_DEVWIFI_IsActive
 * address: 0x0215528C
 * packet: pkt_ov009_0215528C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov009/dwc_rap_p01.c and filed here.
 *
 * symbols:
 *   DWC_RAP_IsWorkAllocated 0x02155388 thumb
 */

int GFL_NET_DEVWIFI_IsActive(void);
int DWC_RAP_IsWorkAllocated(void);

int GFL_NET_DEVWIFI_IsActive(void)
{
    return DWC_RAP_IsWorkAllocated();
}

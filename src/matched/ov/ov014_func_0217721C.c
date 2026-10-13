/*
 * function: GFL_NET_DEVWIRELESS_GetSignalLevel
 * address: 0x0217721C
 * packet: pkt_ov014_0217721C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217723A; existing code starts 0217723C.
 * symbols:
 *   GFL_NET_GetGameKind 0x0203D5D4 arm
 *   WIH_DWC_GetAlertLevel 0x02010848 thumb
 *   WM_GetLinkLevel 0x0208EE9C arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 GFL_NET_GetGameKind(void);
extern u16 WIH_DWC_GetAlertLevel(void);
extern int WM_GetLinkLevel(void);
int GFL_NET_DEVWIRELESS_GetSignalLevel(void)
{
    if (GFL_NET_GetGameKind() == 3) return 3 - WIH_DWC_GetAlertLevel();
    return 3 - WM_GetLinkLevel();
}

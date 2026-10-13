/*
 * function: GFL_NET_DEVWIFI_SetErrorOnDisconnect
 * address: 0x02155330
 * packet: pkt_ov009_02155330
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
 *   DWC_RAP_StoreErrorOnDisconnect 0x02156DB0 thumb ov009
 */

typedef unsigned int   u32;
extern void DWC_RAP_StoreErrorOnDisconnect(u32 v);
void GFL_NET_DEVWIFI_SetErrorOnDisconnect(u32 v);

void GFL_NET_DEVWIFI_SetErrorOnDisconnect(u32 v)
{
    DWC_RAP_StoreErrorOnDisconnect(v);
}

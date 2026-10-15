/*
 * function: WIH_HasBeaconBeenSent
 * address:  0x02177C08
 * packet:   pkt_ov014_02177C08
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      WIH_HasBeaconBeenSent (libdwcaccount.TWL.HYB.thumb.a(dwc_account.o))
 *
 * symbols:
 *   WIH_GetBeaconSendCount  0x02179614  thumb  ov014
 */

extern unsigned short WIH_GetBeaconSendCount(void);

int WIH_HasBeaconBeenSent(void *frienddata)
{
    if (WIH_GetBeaconSendCount())
        return 1;
    return 0;
}

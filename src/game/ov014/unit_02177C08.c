/*
 * file:     unit_02177C08.c
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
 * symbols:
 *   WIH_GetBeaconSendCount  0x02179614  thumb  ov014
 */

/* wih.c: the WH work's beaconSendCount. */
extern unsigned long WIH_GetBeaconSendCount(void *unused);

/*
 * True once the WH layer has counted a sent beacon (beaconSendCount != 0).
 * Earlier tables named this DWC_IsValidFriendData; that match is by byte
 * shape only, the body reads the WH work, not a friend entry.
 */
int WIH_HasBeaconBeenSent(void *unused)
{
    if (WIH_GetBeaconSendCount(unused))
        return 1;
    return 0;
}

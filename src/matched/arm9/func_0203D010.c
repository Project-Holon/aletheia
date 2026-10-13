/*
 * function: GFL_NET_BeaconScanStart
 * address:  0x0203D010
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper (`ldr ip, [pc]; bx ip`, docs/idioms tail-call-is-a-
 * pool-word-and-bx), called by state 10 of GFL_NET_IRC_WIRELESS_Main.  An unlabelled
 * ARM leaf inside GFL_NET_RequestDisconnect's EXACT* extent; filed as a witness.
 *
 * symbols:
 *   GFL_NET_STATE_BeaconScan  0x0203B1B0  arm
 */

extern void GFL_NET_STATE_BeaconScan(void);

void GFL_NET_BeaconScanStart(void)
{
    GFL_NET_STATE_BeaconScan();
}

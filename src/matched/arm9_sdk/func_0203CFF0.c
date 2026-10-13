/*
 * function: GFL_NET_ConnectMacAddressParent
 * address:  0x0203CFF0
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: GFL_NET_STATE_ConnectMacAddress(p, 1).  Called by state 10 of
 * GFL_NET_IRC_WIRELESS_Main with ctx + 0x94.  NOTE: layout/symbols_sdk.txt lists this
 * address as DWC_IsSendableReliable (thumb), a false signature match: the
 * bytes are ARM (`ldr ip, [pc, #4]; mov r1, #1; bx ip`) and the caller
 * reaches it with an ARM `bl`.
 *
 * symbols:
 *   GFL_NET_STATE_ConnectMacAddress  0x0203B0C4  arm
 */

extern void GFL_NET_STATE_ConnectMacAddress(int a0, int a1);

void GFL_NET_ConnectMacAddressParent(void *p)
{
    GFL_NET_STATE_ConnectMacAddress((int)p, 1);
}

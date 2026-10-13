/*
 * function: func_0203D000
 * address:  0x0203D000
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: GFL_NET_STATE_ConnectMacAddress(p, 0), the twin of GFL_NET_ConnectMacAddressParent.
 * NOTE: layout/symbols_sdk.txt lists this address as FATFS_FormatDrive
 * (thumb), a false signature match: the bytes are ARM.
 *
 * symbols:
 *   GFL_NET_STATE_ConnectMacAddress  0x0203B0C4  arm
 */

extern void GFL_NET_STATE_ConnectMacAddress(int a0, int a1);

void func_0203D000(void *p)
{
    GFL_NET_STATE_ConnectMacAddress((int)p, 0);
}

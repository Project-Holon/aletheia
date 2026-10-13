/*
 * function: BTL_NET_IsRelayedPlayerInfoReceived
 * address: 0x021D49B0
 * packet: pkt_ov093_021D49B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled leaf called by BTL_MAIN_SeqExchangePlayers (+0x1E4): reports whether the
 * pending object word at +0x3b18 of the gBtlNet block is set; the
 * block layout follows ov093_func_021D49E0.c.
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 */
typedef unsigned char u8;
extern u8 *gBtlNet;
int BTL_NET_IsRelayedPlayerInfoReceived(void)
{
    if (*(void **)(gBtlNet + 0x3b18))
        return 1;
    return 0;
}

/*
 * function: BTL_NET_GetRelayedPlayerInfo
 * address: 0x021D49CC
 * packet: pkt_ov093_021D49CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled leaf called by BTL_MAIN_SeqExchangePlayers (+0x1EC): returns the object
 * word at +0x3b14 of the gBtlNet block (the word BTL_NET_FreeRelayedPlayerInfo frees).
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 */
typedef unsigned char u8;
extern u8 *gBtlNet;
void *BTL_NET_GetRelayedPlayerInfo(void)
{
    return *(void **)(gBtlNet + 0x3b14);
}

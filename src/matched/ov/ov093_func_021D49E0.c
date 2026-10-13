/*
 * unit: yes
 * function: BTL_NET_FreeRelayedPlayerInfo, BTL_NET_FreeAfterPlayerInfoUse
 * address: 0x021D49E0
 * packet: pkt_ov093_021D49E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Extent follower 021D4A04 is a tail-call stub; function_start seed.
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   func_020307B0 0x020307B0 arm
 *   BTL_NET_FreeRecvBuffers 0x021D4A6C thumb ov093
 */
typedef unsigned char u8;
extern u8 *gBtlNet;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BTL_NET_FreeRecvBuffers(void);
void BTL_NET_FreeRelayedPlayerInfo(void)
{
    func_020307B0(*(void **)(gBtlNet + 0x3b14));
    *(void **)(gBtlNet + 0x3b14) = 0;
    *(void **)(gBtlNet + 0x3b18) = 0;
}
void BTL_NET_FreeAfterPlayerInfoUse(void)
{
    BTL_NET_FreeRecvBuffers();
}

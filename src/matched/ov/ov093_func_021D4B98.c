/*
 * function: BTL_NET_AreAllRepliesReceived
 * address: 0x021D4B98
 * packet: pkt_ov093_021D4B98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   BTL_NET_HasEntry 0x021D4330 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *gBtlNet;
extern u8 BTL_NET_HasEntry(int);
int BTL_NET_AreAllRepliesReceived(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (BTL_NET_HasEntry(i) != 0 && *(u16 *)(gBtlNet + i * 0xbbc + 0x17ae) != 0)
            return 0;
    }
    return 1;
}

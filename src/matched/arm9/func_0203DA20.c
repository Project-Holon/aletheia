/*
 * function: GFL_NET_IRC_WIRELESS_DestroyIfIdle
 * address:  0x0203DA20
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gNetIrcWirelessLink  0x021469F0  data
 *   GFL_NET_IRC_WIRELESS_Destroy  0x0203D9EC  arm
 *
 * Calls GFL_NET_IRC_WIRELESS_Destroy when the net_irc_wireless singleton exists and its
 * +0x101 byte is clear.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IRC_WIRELESS_DestroyIfIdle.c \
 *       --func GFL_NET_IRC_WIRELESS_DestroyIfIdle --addr 0x0203DA20 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 gNetIrcWirelessLink[];

extern void GFL_NET_IRC_WIRELESS_Destroy(void);

void GFL_NET_IRC_WIRELESS_DestroyIfIdle(void)
{
    u8 *p = *(u8 **)gNetIrcWirelessLink;

    if (p == 0) {
        return;
    }
    if (p[0x101] != 0) {
        return;
    }
    GFL_NET_IRC_WIRELESS_Destroy();
}

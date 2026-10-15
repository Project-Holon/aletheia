/*
 * function: GFL_NET_IRC_WIRELESS_Destroy
 * address:  0x0203D9EC
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
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *
 * Tears down the net_irc_wireless singleton at 0x021469F0: releases it
 * through UI_ClearKeepAwakeFlagsGlobal(0x20) and the heap release, then clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IRC_WIRELESS_Destroy.c \
 *       --func GFL_NET_IRC_WIRELESS_Destroy --addr 0x0203D9EC --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 gNetIrcWirelessLink[];

extern void UI_ClearKeepAwakeFlagsGlobal(u32 v);
extern u32 func_020307B0(void *p);

void GFL_NET_IRC_WIRELESS_Destroy(void)
{
    if (*(u32 *)gNetIrcWirelessLink == 0) {
        return;
    }
    UI_ClearKeepAwakeFlagsGlobal(0x20);
    func_020307B0(*(void **)gNetIrcWirelessLink);
    *(u32 *)gNetIrcWirelessLink = 0;
}

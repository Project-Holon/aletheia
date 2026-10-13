/*
 * function: WIFICLUB_StatePollRetryYesNo
 * address: 0x021C1768
 * packet: pkt_ov099_021C1768
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero alignment bytes at 0x021C17D2.
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_ResetTimeIcon 0x021BC090 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 */
#include "../include/Obj00008.h"
extern int WIFICLUB_UpdateTalkStream(char *, int);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_ResetTimeIcon(char *);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
int WIFICLUB_StatePollRetryYesNo(char *p, int ret)
{
    int choice;
    if (WIFICLUB_UpdateTalkStream(p, ret) == 0) return ret;
    choice = WIFICLUB_PollYesNoMenu(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        WIFICLUB_ShowStreamedMessage(p, 76, 0);
        WIFICLUB_ResetTimeIcon(p);
        ((struct Obj00008 *)p)->f244 = 1;
        ((struct Obj00008 *)p)->f1CC = 41;
        ((struct Obj00008 *)p)->f1E0 = 30;
    } else {
        WIFICLUB_ClearTalkWindow(p);
        GFL_NET_STATE_WifiDisconnect(1);
        ((struct Obj00008 *)p)->f1E0 = 20;
        ((struct Obj00008 *)p)->f1CC = 57;
    }
    return ret;
}

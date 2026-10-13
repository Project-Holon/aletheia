/*
 * function: WIFICLUB_StatePollExitPrompt
 * address: 0x021BE96C
 * packet: pkt_ov099_021BE96C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021BE9C6.
 * symbols:
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   GFL_NET_Exit 0x0203CEAC arm
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj10208.h"
typedef unsigned int u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern int GFL_NET_Exit(int a0);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StatePollExitPrompt(char *p, int v)
{
    int t;
    int zero;
    t = WIFICLUB_PollYesNoMenu(p);
    if (t == -1) return v;
    if (t == 0) {
        GFL_NET_Exit(0);
        WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
        ((struct Obj10208 *)p)->f1CC = 4;
    } else {
        WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
        zero = 0;
        GFL_NET_Exit(0);
        ((struct Obj10208 *)p)->f1D0 = zero;
        ((struct Obj10208 *)p)->f1CC = 0x1a;
    }
    WIFICLUB_ClearTalkWindow(p);
    return v;
}

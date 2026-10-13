/*
 * function: WIFICLUB_StatePollQuitYesNo
 * address: 0x021C1634
 * packet: pkt_ov099_021C1634
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 */
#include "../include/Obj00008.h"
extern int WIFICLUB_UpdateTalkStream(char *, int);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_DisableTouchBar(char *);
int WIFICLUB_StatePollQuitYesNo(char *p, int ret)
{
    int choice;
    if (WIFICLUB_UpdateTalkStream(p, ret) == 0) return ret;
    choice = WIFICLUB_PollYesNoMenu(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        *(int *)&((struct Obj00008 *)p)->f108 = 0;
        WIFICLUB_ShowStreamedMessage(p, 26, 1);
        ((struct Obj00008 *)p)->f1CC = 51;
        ((struct Obj00008 *)p)->f1E0 = 1;
    } else {
        *(int *)&((struct Obj00008 *)p)->f108 = 0;
        WIFICLUB_ClearTalkWindow(p);
        ((struct Obj00008 *)p)->f1CC = 11;
        WIFICLUB_DisableTouchBar(p);
    }
    return ret;
}

/*
 * function: WIFICLUB_StatePollCancelRequestPrompt
 * address: 0x021C0A94
 * packet: pkt_ov099_021C0A94
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
 *   WIFICLUB_ResetTimeIcon 0x021BC090 thumb ov099
 */
#include "../include/Obj00008.h"
extern int WIFICLUB_UpdateTalkStream(char *,int);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ShowStreamedMessage(char *,int,int);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_ResetTimeIcon(char *);
int WIFICLUB_StatePollCancelRequestPrompt(char *p,int ret) {
    int r;
    if(!WIFICLUB_UpdateTalkStream(p,ret))return ret;
    r=WIFICLUB_PollYesNoMenu(p);
    if(r==-1)return ret;
    if(r==0){
        WIFICLUB_ShowStreamedMessage(p,74,0);
        ((struct Obj00008 *)p)->f1CC=21;
    }else {
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUB_ShowStreamedMessage(p,14,0);
        WIFICLUB_ResetTimeIcon(p);
        ((struct Obj00008 *)p)->f1CC=136;
    }
    return ret;
}

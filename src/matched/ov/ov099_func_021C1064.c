/*
 * function: WIFICLUB_StateLeaveLinkToLobby, WIFICLUB_StateUnusedD, WIFICLUB_StateUnusedE
 * address: 0x021C1064
 * packet: pkt_ov099_021C1064
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   WIFICLUB_ResetOwnSeatStatus 0x021C19A8 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj00008.h"
extern void WIFICLUB_ResetOwnSeatStatus(char *);
typedef unsigned int   u32;
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void WIFICLUB_DisableTouchBar(char *);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StateLeaveLinkToLobby(char *p,int ret) {
    WIFICLUB_ResetOwnSeatStatus(p);
    WIFICLUB_SetOwnStatusAndPublish(p,1,2);
    GFL_NET_STATE_WifiDisconnect(1);
    ((struct Obj00008 *)p)->f1F0=-1;
    ((struct Obj00008 *)p)->f1CC=11;
    WIFICLUB_DisableTouchBar(p);
    WIFICLUB_ClearTalkWindow(p);
    return ret;
}
int WIFICLUB_StateUnusedD(char *p,int ret){return ret;}
int WIFICLUB_StateUnusedE(char *p,int ret){return ret;}

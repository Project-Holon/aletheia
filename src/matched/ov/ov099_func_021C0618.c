/*
 * function: WIFICLUB_StateWaitKeyDisconnectToLobby
 * address: 0x021C0618
 * packet: pkt_ov099_021C0618
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 */
#include "../include/Obj00008.h"

typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(char *,int);
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void WIFICLUB_DisableTouchBar(char *);
int WIFICLUB_StateWaitKeyDisconnectToLobby(char *p,int ret) {
    if (!WIFICLUB_UpdateTalkStream(p,ret)) return ret;
    if(KEY_GetTrg()) {
        WIFICLUB_ClearTalkWindow(p);
        GFL_NET_STATE_WifiDisconnect(1);
        WIFICLUB_SetOwnStatusAndPublish(p,1,2);
        ((struct Obj00008 *)p)->f1F0=-1;
        WIFICLUB_DisableTouchBar(p);
        ((struct Obj00008 *)p)->f1CC=11;
    }
    return ret;
}

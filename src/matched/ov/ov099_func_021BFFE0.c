/*
 * function: WIFICLUB_StateLeaveTimeout
 * address: 0x021BFFE0
 * packet: pkt_ov099_021BFFE0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   WIFICLUB_StartNetSession 0x021BDD0C thumb ov099
 *   WIFICLUBACTOR_IsReady 0x021B96CC thumb ov099
 *   WIFICLUB_BeginIdle 0x021BE4F0 thumb ov099
 *   WIFICLUB_ResetOwnSeatStatus 0x021C19A8 thumb ov099
 *   WIFICLUB_DrawPlayerInfoWindow 0x021BAEDC thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 */
#include "../include/Obj00008.h"
extern int WIFICLUBACTOR_GetPickResult(char *);
extern void *WIFICLUB_FindPeerActor(char *,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WIFICLUBACTOR_RestoreActorUpdate(void *w, u8 *s);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void WIFICLUB_StartNetSession(void *p, int on);
extern int WIFICLUBACTOR_IsReady(int *p);
extern int WIFICLUB_BeginIdle(char *,int);
extern void WIFICLUB_ResetOwnSeatStatus(char *);
extern void WIFICLUB_DrawPlayerInfoWindow(char *);
extern void WIFICLUB_DisableTouchBar(char *);
int WIFICLUB_StateLeaveTimeout(char *p,int ret) {
    if(++((struct Obj00008 *)p)->f1E0<=240)return ret;
    WIFICLUBACTOR_RestoreActorUpdate(p+0x274,WIFICLUB_FindPeerActor(p,WIFICLUBACTOR_GetPickResult(p+0x274)));
    WIFICLUB_ClearTalkWindow(p);
    WIFICLUB_SetOwnStatusAndPublish(p,1,2);
    GFL_NET_STATE_WifiDisconnect(1);
    WIFICLUB_StartNetSession(p,0);
    if(!WIFICLUBACTOR_IsReady((int *)(p+0x274))){
        ((struct Obj00008 *)p)->f1CC=WIFICLUB_BeginIdle(p,0);
    } else {
        WIFICLUB_ResetOwnSeatStatus(p);
        WIFICLUB_DrawPlayerInfoWindow(p);
        ((struct Obj00008 *)p)->f1F0=-1;
        ((struct Obj00008 *)p)->f1CC=11;
        WIFICLUB_DisableTouchBar(p);
    }
    return ret;
}

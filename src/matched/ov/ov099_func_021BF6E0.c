/*
 * function: WIFICLUB_StateLobbyConnected
 * address: 0x021BF6E0
 * packet: pkt_ov099_021BF6E0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unchanged concrete-correct caller resolves after the ov009 02156BA8 leaf is verified.
 * symbols:
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_UpdatePeerActors 0x021BF280 thumb ov099
 *   WIFICLUB_RedrawSlotPanelIfPending 0x021C1BEC thumb ov099
 *   WIFICLUBACTOR_RestartBlink 0x021B9B54 thumb ov099
 *   WIFICLUB_IsNetStateConnected 0x021BF03C thumb ov099
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   WIFICLUB_IsNetStateDisconnecting 0x021BF068 thumb ov099
 *   DWC_RAP_GetCanceledPeerIndex 0x02156BA8 thumb ov009
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   DWC_RAP_GetNewClientAid 0x02156B8C thumb ov009
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_IsKindActive 0x021BDDA8 thumb ov099
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIFICLUB_ClosePanelIfTouchActive 0x021C1A30 thumb ov099
 *   WIFICLUBACTOR_Update 0x021B96D0 thumb ov099
 *   WIFICLUBACTOR_TickBlink 0x021B9B64 thumb ov099
 *   WIFICLUBACTOR_StartBlinkOnTile 0x021B9B24 thumb ov099
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj00901.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern int WIFICLUB_UpdateTalkStream(char *);
extern void WIFICLUB_UpdatePeerActors(void *a, void *b);
extern void WIFICLUB_RedrawSlotPanelIfPending(u8 *p);
extern void WIFICLUBACTOR_RestartBlink(char *);
extern int WIFICLUB_IsNetStateConnected(char *);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern int WIFICLUB_IsNetStateDisconnecting(char *);
extern int DWC_RAP_GetCanceledPeerIndex(void);
extern void WIFICLUB_SetPartnerNameWord(char *,int);
extern void WIFICLUB_ShowStreamedMessage(char *,int,int);
extern int DWC_RAP_GetNewClientAid(void);
extern unsigned WIFICLUB_GetStatusKind(char *,void *);
extern u32 KEY_GetTrg(void);
extern int WIFICLUB_IsKindActive(int x);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void WIFICLUB_ClosePanelIfTouchActive(u8 *p, int v);
extern unsigned WIFICLUBACTOR_Update(char *);
extern void WIFICLUBACTOR_TickBlink(char *);
extern void WIFICLUBACTOR_StartBlinkOnTile(char *);
extern int WIFICLUBACTOR_GetPickResult(char *);
extern int WIFICLUB_GetFriendStatus(int i);
extern void MI_CpuCopy8(void *,void *,int);
int WIFICLUB_StateLobbyConnected(char *p,int ret)
{
    unsigned action=0,kind;
    int index;
    if(((struct Obj00901 *)p)->f1F0!=-1){
        if(++((struct Obj00901 *)p)->f1C8>0xe10){GFL_NET_STATE_SetError(0,0,0,0x3f1);return ret;}
    }
    WIFICLUB_UpdateTalkStream(p);
    ((struct Obj00901 *)p)->f1356=0;
    WIFICLUB_UpdatePeerActors(p,(void *)33);
    WIFICLUB_RedrawSlotPanelIfPending((u8 *)p);
    WIFICLUBACTOR_RestartBlink(p+0x274);
    if(WIFICLUB_IsNetStateConnected(p) && ((struct Obj00901 *)p)->f1F0!=-1){
        GFL_USE_PlaySeInSlot((void *)0x806,0);
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
        ((struct Obj00901 *)p)->f1CC=40;
        return ret;
    }
    if(WIFICLUB_IsNetStateDisconnecting(p) && ((struct Obj00901 *)p)->f1F0!=-1){
        WIFICLUB_SetPartnerNameWord(p,DWC_RAP_GetCanceledPeerIndex());
        WIFICLUB_ShowStreamedMessage(p,15,0);
        ((struct Obj00901 *)p)->f1CC=19;
        return ret;
    }
    if(((struct Obj00901 *)p)->f1F0==-1 && DWC_RAP_GetNewClientAid()!=-1){
        index=DWC_RAP_GetNewClientAid();
        ((struct Obj00901 *)p)->f1F0=index;
        WIFICLUB_SetPartnerNameWord(p,index);
        if(!((struct Obj00901 *)p)->f1351)WIFICLUB_ShowStreamedMessage(p,46,0);
        ((struct Obj00901 *)p)->f1C8=0;
    }else if(DWC_RAP_GetCanceledPeerIndex()!=-1){
        WIFICLUB_SetPartnerNameWord(p,DWC_RAP_GetCanceledPeerIndex());
        WIFICLUB_ShowStreamedMessage(p,15,0);
        ((struct Obj00901 *)p)->f1CC=19;
        return ret;
    }
    kind=WIFICLUB_GetStatusKind(p,((struct Obj00901 *)p)->f8);
    if(((struct Obj00901 *)p)->f1F0==-1){
        if((KEY_GetTrg()&2) && WIFICLUB_IsKindActive(kind)){
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ((struct Obj00901 *)p)->f1CC=31;
            WIFICLUB_ClosePanelIfTouchActive((u8 *)p,33);
            return ret;
        }
        action=WIFICLUBACTOR_Update(p+0x274);
        WIFICLUBACTOR_TickBlink(p+0x274);
    }
    switch(action){
    case 0:return ret;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if(WIFICLUB_IsKindActive(kind)){
            ((struct Obj00901 *)p)->f1CC=31;
        }else{
            ((struct Obj00901 *)p)->f1D0=0;
            ((struct Obj00901 *)p)->f1CC=49;
            WIFICLUB_ShowStreamedMessage(p,25,1);
        }
        WIFICLUB_ClosePanelIfTouchActive((u8 *)p,33);
        return ret;
    case 3:
        if(kind==1){
            ((struct Obj00901 *)p)->f135C=1;
            GFL_USE_PlaySeDefaultVolume(0x54c);
            WIFICLUBACTOR_StartBlinkOnTile(p+0x274);
            ((struct Obj00901 *)p)->f1CC=28;
            WIFICLUB_ClosePanelIfTouchActive((u8 *)p,33);
            return ret;
        }
        break;
    case 2:
        if(kind==1){
            index=WIFICLUBACTOR_GetPickResult(p+0x274);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            MI_CpuCopy8((void *)WIFICLUB_GetFriendStatus(index-1),p+0x24c,32);
            ((struct Obj00901 *)p)->f1CC=34;
            WIFICLUB_ClosePanelIfTouchActive((u8 *)p,33);
            return ret;
        }
        break;
    }
    return ret;
}

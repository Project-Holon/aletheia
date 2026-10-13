/*
 * function: WIFICLUB_StatePollPrompt
 * address: 0x021C01CC
 * packet: pkt_ov099_021C01CC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUBACTOR_TickBlink 0x021B9B64 thumb ov099
 *   DWC_RAP_GetNewClientAid 0x02156B8C thumb ov009
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   WIFICLUB_StartNetSession 0x021BDD0C thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUBACTOR_TickBlink(char *);
extern int DWC_RAP_GetNewClientAid(void);
typedef unsigned char  u8;
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void WIFICLUB_StartNetSession(void *p, int on);
extern void WIFICLUB_DisableTouchBar(char *);
extern void WIFICLUB_ShowMessage(char *,int,int);
int WIFICLUB_StatePollPrompt(char *p,int ret) {
    int r=WIFICLUB_PollYesNoMenu(p);
    WIFICLUBACTOR_TickBlink(p+0x274);
    if(((struct Obj00008 *)p)->f1F0==-1 && DWC_RAP_GetNewClientAid()!=-1){
        if(r==-1){BMP_MENU_DeleteYesNo((u8 *)(*(int *)&((struct Obj00008 *)p)->f108)); *(int *)&((struct Obj00008 *)p)->f108=0;}
        r=1;
    }
    if(r==-1)return ret;
    if(r==0){
        WIFICLUB_SetOwnStatusAndPublish(p,1,2);
        GFL_NET_STATE_WifiDisconnect(1);
        WIFICLUB_StartNetSession(p,0);
        WIFICLUB_DisableTouchBar(p);
        ((struct Obj00008 *)p)->f1CC=11;
    }else {
        WIFICLUB_ShowMessage(p,6,0);
        ((struct Obj00008 *)p)->f1CC=158;
    }
    return ret;
}

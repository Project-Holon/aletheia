/*
 * function: WIFICLUB_StateLeaveSyncWait
 * address: 0x021BFDD0
 * packet: pkt_ov099_021BFDD0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   DWC_RAP_StopVchat 0x021563D0 thumb ov009
 *   WIFICLUB_StartBgmFade 0x021C24A4 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj07958.h"
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned,unsigned);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern void DWC_RAP_StopVchat(void);
extern void WIFICLUB_StartBgmFade(char *,int);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
int WIFICLUB_StateLeaveSyncWait(char *p,int ret) {
    ((struct Obj07958 *)p)->f1355=0;
    if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,10) || GFL_NET_HANDLE_GetNegotiationNum()!=2) {
        if((unsigned)(((struct Obj07958 *)p)->f135C-3)<=1){
            DWC_RAP_StopVchat();
            WIFICLUB_StartBgmFade(p,127);
            WIFICLUB_ClearTalkWindow(p);
            WIFICLUB_SetOwnStatusAndPublish(p,3,3);
            ((struct Obj07958 *)p)->f1CC=154;
        } else {
            WIFICLUB_SetOwnStatusAndPublish(p,1,2);
            GFL_NET_SetAutoExit(0); GFL_NET_SetLoginOption(0);
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,10);
            ((struct Obj07958 *)p)->f1CC=159;
        }
    }
    return ret;
}

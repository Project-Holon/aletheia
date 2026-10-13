/*
 * function: WIFICLUB_StateWaitPeerReply
 * address: 0x021BFA28
 * packet: pkt_ov099_021BFA28
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_CopyZeroToDeviceAddr 0x021C282C thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_StartBgmFade 0x021C24A4 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 */
#include "../include/Obj03223.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WIFICLUB_GetFriendStatus(int i);
extern void WIFICLUB_GetStatusSeatFlag(void *);
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern int GFL_NET_STATE_GetWifiState(void);
extern void WIFICLUB_ClearTalkWindow(char *);
extern int WIFICLUB_CopyZeroToDeviceAddr(u8 *p);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void WIFICLUB_StartBgmFade(char *, int);
extern void WIFICLUB_ShowMessage(char *, int, int);
int WIFICLUB_StateWaitPeerReply(char *p, int ret)
{
    void *s;
    unsigned v;
    s = (void *)WIFICLUB_GetFriendStatus(((struct Obj03223 *)p)->f242 - 1);
    WIFICLUB_GetStatusSeatFlag(s);
    v = WIFICLUB_GetStatusKind(p, s);
    ((struct Obj03223 *)p)->f1C4 -= 1;
    if (((struct Obj03223 *)p)->f1C4 < 0) {
        ((struct Obj03223 *)p)->f1CC = 0x3d;
    } else if (v != 1 && v != 2) {
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(p, 0xd, 0);
        ((struct Obj03223 *)p)->f1CC = 0x13;
    } else if (GFL_NET_STATE_GetWifiState() == 1) {
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUB_CopyZeroToDeviceAddr(((struct Obj03223 *)p)->f8);
        ((struct Obj03223 *)p)->f1351 = 0;
        WIFICLUB_SetOwnStatusAndPublish(p, 4, 4);
        ((struct Obj03223 *)p)->f1355 = 0;
        ((struct Obj03223 *)p)->f1CC = 0x10;
        WIFICLUB_StartBgmFade(p, 0);
        WIFICLUB_ShowMessage(p, 0x7b, 0);
    }
    return ret;
}

/*
 * function: WIFICLUB_StateVchatInvite
 * address: 0x021BFC04
 * packet: pkt_ov099_021BFC04
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_UpdatePeerActors 0x021BF280 thumb ov099
 *   WIFICLUB_RedrawSlotPanelIfPending 0x021C1BEC thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_UpdateVchatIndicator 0x021BFBBC thumb ov099
 */
#include "../include/Obj07956.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int DWC_RAP_GetTargetFriendIndex(void);
extern int WIFICLUB_GetFriendStatus(int i);
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern void WIFICLUB_UpdatePeerActors(void *a, void *b);
extern void WIFICLUB_RedrawSlotPanelIfPending(u8 *p);
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_UpdateVchatIndicator(char *);
int WIFICLUB_StateVchatInvite(char *p, int ret)
{
    void *s = (void *)WIFICLUB_GetFriendStatus(DWC_RAP_GetTargetFriendIndex());
    WIFICLUB_GetStatusKind(p, s);
    WIFICLUB_GetStatusPhase(p, s);
    WIFICLUB_UpdatePeerActors(p, (void *)0x21);
    WIFICLUB_RedrawSlotPanelIfPending((u8 *)p);
    if (KEY_GetTrg() & 2) {
        WIFICLUB_ShowStreamedMessage(p, 0x11, 0);
        ((struct Obj07956 *)p)->f1CC = 0x11;
    } else if (((struct Obj07956 *)p)->f1355) {
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(p, 0x10, 0);
        ((struct Obj07956 *)p)->f1E0 = 0x3c;
        ((struct Obj07956 *)p)->f1CC = 0x94;
    } else {
        WIFICLUB_UpdateVchatIndicator(p);
    }
    return ret;
}

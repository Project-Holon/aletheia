/*
 * function: WIFICLUB_StateVchatAnswerWait
 * address: 0x021BFC94
 * packet: pkt_ov099_021BFC94
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateVchatIndicator 0x021BFBBC thumb ov099
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_OpenYesNoMenu 0x021BA828 thumb ov099
 */
#include "../include/Obj07957.h"
typedef unsigned char u8;
extern void WIFICLUB_UpdateVchatIndicator(char *);
extern int WIFICLUB_UpdateTalkStream(char *);
extern void WIFICLUB_ClearTalkWindow(char *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_OpenYesNoMenu(char *);
int WIFICLUB_StateVchatAnswerWait(char *p, int ret)
{
    WIFICLUB_UpdateVchatIndicator(p);
    if (WIFICLUB_UpdateTalkStream(p)) {
        if (((struct Obj07957 *)p)->f1355) {
            WIFICLUB_ClearTalkWindow(p);
            WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
            WIFICLUB_ShowStreamedMessage(p, 0x10, 0);
            ((struct Obj07957 *)p)->f1E0 = 0x3c;
            ((struct Obj07957 *)p)->f1CC = 0x94;
        } else {
            WIFICLUB_OpenYesNoMenu(p);
            ((struct Obj07957 *)p)->f1CC = 0x12;
        }
    }
    return ret;
}

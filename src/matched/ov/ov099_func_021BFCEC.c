/*
 * function: WIFICLUB_StateVchatYesNo
 * address: 0x021BFCEC
 * packet: pkt_ov099_021BFCEC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateVchatIndicator 0x021BFBBC thumb ov099
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 */
#include "../include/Obj04416.h"
typedef unsigned char u8;
extern void WIFICLUB_UpdateVchatIndicator(char *);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_ShowMessage(char *, int, int);
int WIFICLUB_StateVchatYesNo(char *p, int ret)
{
    int v;
    WIFICLUB_UpdateVchatIndicator(p);
    v = WIFICLUB_PollYesNoMenu(p);
    if (v == -1) {
        if (((struct Obj04416 *)p)->f1355) {
            WIFICLUB_ClearTalkWindow(p);
            BMP_MENU_DeleteYesNo(((struct Obj04416 *)p)->f108);
            ((struct Obj04416 *)p)->f108 = 0;
            WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
            WIFICLUB_ShowStreamedMessage(p, 0x10, 0);
            ((struct Obj04416 *)p)->f1E0 = 0x3c;
            ((struct Obj04416 *)p)->f1CC = 0x94;
        }
    } else if (v == 0) {
        ((struct Obj04416 *)p)->f1CC = 0x92;
    } else {
        WIFICLUB_ShowMessage(p, 0x7b, 0);
        ((struct Obj04416 *)p)->f1CC = 0x10;
    }
    return ret;
}

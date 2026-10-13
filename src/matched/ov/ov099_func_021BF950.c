/*
 * function: WIFICLUB_StateCheckPeerSelection
 * address: 0x021BF950
 * packet: pkt_ov099_021BF950
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pointer addition spells base + index + 0x24, avoiding indexed strb.
 * symbols:
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusChangeCount 0x021C2874 thumb ov099
 *   WIFICLUB_AddNetCommandsAndCheckFriend 0x021C23C8 thumb ov099
 *   WIFICLUB_ChangeNetMode 0x021BDE30 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_ClosePartnerPanel 0x021C19DC thumb ov099
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 *   WIFICLUB_ResetTimeIcon 0x021BC090 thumb ov099
 */
#include "../include/Obj03734.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern int WIFICLUB_GetFriendStatus(int i);
extern int WIFICLUB_GetStatusChangeCount(void *);
extern int WIFICLUB_AddNetCommandsAndCheckFriend(void *a, void *b);
extern void WIFICLUB_ChangeNetMode(void *p, int kind, int value);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void WIFICLUB_ClosePartnerPanel(char *, int);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowMessage(char *, int, int);
extern void WIFICLUB_ResetTimeIcon(char *);
int WIFICLUB_StateCheckPeerSelection(char *p, int ret)
{
    int i = ((struct Obj03734 *)p)->f242 - 1;
    if (GFL_USE_IsSeSlotBusy(0)) return ret;
    *(*(u8 * *)&((struct Obj03734 *)p)->f248 + i + 0x24) = WIFICLUB_GetStatusChangeCount((void *)WIFICLUB_GetFriendStatus(i));
    if (i >= 0 && i < 32 && WIFICLUB_AddNetCommandsAndCheckFriend(p, (void *)i)) {
        ((struct Obj03734 *)p)->f1C4 = 0xe10;
        WIFICLUB_ChangeNetMode(p, 4, 3);
        WIFICLUB_SetOwnStatusAndPublish(p, 4, 3);
        WIFICLUB_ClosePartnerPanel(p, 0x21);
        WIFICLUB_SetPartnerNameWord(p, i);
        ((struct Obj03734 *)p)->f1C4 = 0xe10;
        WIFICLUB_ShowMessage(p, 0x5e, 0);
        WIFICLUB_ResetTimeIcon(p);
        ((struct Obj03734 *)p)->f1CC = 0x25;
        ((struct Obj03734 *)p)->f1350 = ((struct Obj03734 *)p)->f242;
        return ret;
    }
    ((struct Obj03734 *)p)->f1CC = 0xb;
    return ret;
}

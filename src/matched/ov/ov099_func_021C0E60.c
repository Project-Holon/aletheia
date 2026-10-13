/*
 * function: WIFICLUB_StateRequestJoinPartner
 * address: 0x021C0E60
 * packet: pkt_ov099_021C0E60
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed int locals with the witnessed byte return prevent index-minus-one hoisting.
 * prototype: C23B8 forwards the visible index to 56860 and returns its pointer.
 * symbols:
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_GetFriendConnectionStatus 0x021C23C0 thumb ov099
 *   WIFICLUB_AddNetCommandsAndCheckFriend 0x021C23C8 thumb ov099
 *   WIFICLUB_ChangeNetMode 0x021BDE30 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 *   WIFICLUB_ResetTimeIcon 0x021BC090 thumb ov099
 */
#include "../include/Obj03224.h"
typedef unsigned short u16;
extern unsigned POKEPARTY_GetAliveNonEggCount(void *);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern int WIFICLUB_GetFriendStatus(int i);
extern unsigned char WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern unsigned char WIFICLUB_GetStatusSeatFlag(void *);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern unsigned char WIFICLUB_GetFriendConnectionStatus(void *a);
extern int WIFICLUB_AddNetCommandsAndCheckFriend(void *a, void *b);
extern void WIFICLUB_ChangeNetMode(void *, int, int);
extern void WIFICLUB_SetOwnStatusAndPublish(char *, int, int);
extern void WIFICLUB_ShowMessage(char *, int, int);
extern void WIFICLUB_ResetTimeIcon(void *);
int WIFICLUB_StateRequestJoinPartner(char *p, int ret)
{
    int index;
    void *state;
    int kind, value, flag;
    index = ((struct Obj03224 *)p)->f242;
    POKEPARTY_GetAliveNonEggCount(((struct Obj03224 *)p)->fC8);
    if (((struct Obj03224 *)p)->f242 == 0) {
        WIFICLUB_ShowStreamedMessage(p, 0x4a, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
    }
    state = (void *)WIFICLUB_GetFriendStatus(index - 1);
    kind = WIFICLUB_GetStatusKind(p, state);
    value = WIFICLUB_GetStatusPhase(p, state);
    flag = WIFICLUB_GetStatusSeatFlag(state);
    if (kind != WIFICLUB_GetStatusKind(p, p + 0x24c) ||
        value != WIFICLUB_GetStatusPhase(p, p + 0x24c) ||
        flag != WIFICLUB_GetStatusSeatFlag(p + 0x24c) || kind == 6) {
        WIFICLUB_SetPartnerNameWord(p, index - 1);
        WIFICLUB_ShowStreamedMessage(p, 13, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
        return ret;
    }
    WIFICLUB_GetFriendConnectionStatus((void *)(index - 1));
    if (WIFICLUB_AddNetCommandsAndCheckFriend(p, (void *)(index - 1))) {
        ((struct Obj03224 *)p)->f1C4 = 0xe10;
        WIFICLUB_ChangeNetMode(p, 3, value);
        WIFICLUB_SetOwnStatusAndPublish(p, 3, value);
        WIFICLUB_SetPartnerNameWord(p, index - 1);
        WIFICLUB_ShowMessage(p, 14, 0);
        WIFICLUB_ResetTimeIcon(p);
        ((struct Obj03224 *)p)->f242 = index;
        ((struct Obj03224 *)p)->f1CC = 37;
    } else {
        WIFICLUB_SetPartnerNameWord(p, index - 1);
        WIFICLUB_ShowStreamedMessage(p, 13, 0);
        ((struct Obj03224 *)p)->f1CC = 21;
    }
    return ret;
}

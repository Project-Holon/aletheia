/*
 * function: WIFICLUB_StatePartnerMenu
 * address: 0x021C02C8
 * packet: pkt_ov099_021C02C8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype-evidence: C23C8's forward target 0203C2B0 returns a boolean,
 *   unused here; BB954's complete body reads only r0/r1 before a six-input
 *   BAC24 call. 0290 reads r0 and explicitly sets each forwarding input.
 * symbols:
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 *   WIFICLUBACTOR_TickBlink 0x021B9B64 thumb ov099
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   WIFICLUB_ClosePartnerMenu 0x021C0290 thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 *   WIFICLUB_SetupRuleMenu 0x021BB954 thumb ov099
 *   WIFICLUB_AddNetCommandsAndCheckFriend 0x021C23C8 thumb ov099
 *   WIFICLUB_HasEnoughPartyMembers 0x021BDDD0 thumb ov099
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0202EB0C 0x0202EB0C thumb
 *   WIFICLUB_EnableTouchBar 0x021C23D8 thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct W; struct Obj;
extern u32 POKEPARTY_GetAliveNonEggCount(void *);
extern void WIFICLUBACTOR_TickBlink(char *);
extern int WIFICLUB_UpdateTalkStream(struct W *);
extern int BMP_MENULIST_Main(struct Obj *);
extern void WIFICLUB_ClosePartnerMenu(char *);
extern void WIFICLUB_DisableTouchBar(char *);
extern void WIFICLUB_SetupRuleMenu(char *, int);
extern int WIFICLUB_AddNetCommandsAndCheckFriend(void *a, void *b);
extern int WIFICLUB_HasEnoughPartyMembers(char *);
extern int WIFICLUB_DeleteWindow(void *);
extern void BMP_MENULIST_Delete(struct Obj *, u16 *, u16 *);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern int func_0202EB14(void);
extern u32 func_0202EB0C(void);
extern void WIFICLUB_EnableTouchBar(char *, int);
int WIFICLUB_StatePartnerMenu(char *p, int ret)
{
    u32 choice;
    u8 *q;
    POKEPARTY_GetAliveNonEggCount(((struct Obj00008 *)p)->fC8);
    WIFICLUBACTOR_TickBlink(p + 0x274);
    if (!WIFICLUB_UpdateTalkStream((struct W *)p)) return ret;
    choice = BMP_MENULIST_Main(*(struct Obj * *)&((struct Obj00008 *)p)->fBC);
    switch (choice) {
    case (u32)-1:
        return ret;
    case (u32)-2:
        ((struct Obj00008 *)p)->f1CC = 11;
        WIFICLUB_ClosePartnerMenu(p);
        WIFICLUB_DisableTouchBar(p);
        return ret;
    case 7:
        WIFICLUB_ClosePartnerMenu(p);
        q = *(u8 * *)&((struct Obj00008 *)p)->f248;
        ((struct Obj00008 *)p)->f134C = q[0x21];
        ((struct Obj00008 *)p)->f134E = q[0x22];
        q[0x48] = q[0x20];
        WIFICLUB_SetupRuleMenu(p, 1);
        ((struct Obj00008 *)p)->f1CC = 0x54;
        return ret;
    case 4:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        WIFICLUB_ClosePartnerMenu(p);
        WIFICLUB_AddNetCommandsAndCheckFriend(p, (void *)-1);
        ((struct Obj00008 *)p)->f1CC = 0x9e;
        break;
    case 6:
        if (WIFICLUB_HasEnoughPartyMembers(p) == 0) {
            *(int *)&((struct Obj00008 *)p)->f1A4 = WIFICLUB_DeleteWindow(((struct Obj00008 *)p)->f1A4);
            BMP_MENULIST_Delete(*(struct Obj * *)&((struct Obj00008 *)p)->fBC, 0, (u16 *)(p + 0x23c));
            BMP_MENUWORK_Delete(((struct Obj00008 *)p)->fB8);
            WIFICLUB_ClearTalkWindow(p);
            WIFICLUB_ShowStreamedMessage(p, 0x79, 0);
            ((struct Obj00008 *)p)->f1CC = 0x71;
            return ret;
        } else {
            WIFICLUB_ClosePartnerMenu(p);
            WIFICLUB_AddNetCommandsAndCheckFriend(p, (void *)-1);
            ((struct Obj00008 *)p)->f1CC = 0x9e;
        }
        break;
    case 5:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        if (func_0202EB14() == 0 && func_0202EB0C() != 0) {
            WIFICLUB_ClosePartnerMenu(p);
            WIFICLUB_ShowStreamedMessage(p, 0x95, 0);
            ((struct Obj00008 *)p)->f1CC = 0xa0;
            return ret;
        } else {
            WIFICLUB_ClosePartnerMenu(p);
            WIFICLUB_AddNetCommandsAndCheckFriend(p, (void *)-1);
            ((struct Obj00008 *)p)->f1CC = 0x9e;
        }
        break;
    case 0: case 1: case 2: case 3: default:
        break;
    }
    WIFICLUB_EnableTouchBar(p, 1);
    ((struct Obj00008 *)p)->f1E0 = 0;
    ((struct Obj00008 *)p)->f246 = choice;
    ((struct Obj00008 *)p)->f1CC = 0xad;
    return ret;
}

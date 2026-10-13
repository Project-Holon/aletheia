/*
 * function: WIFICLUB_StateOnPartnerConnected
 * address: 0x021C10A8
 * packet: pkt_ov099_021C10A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_GetFriendConnectionStatus 0x021C23C0 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUBACTOR_AddNetCommands 0x021BA7D8 thumb ov099
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb  arm9
 */
#include "../include/Obj03735.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int   u32;
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern unsigned char WIFICLUB_GetFriendConnectionStatus(void *a);
extern int WIFICLUB_GetFriendStatus(int i);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusSeatFlag(void *);
extern void WIFICLUBACTOR_AddNetCommands(void *p);
int WIFICLUB_StateOnPartnerConnected(char *p, int ret)
{
    int zero = 0;
    void *s;
    if (GFL_USE_IsSeSlotBusy(0) != 0) return ret;
    if (WIFICLUB_GetFriendConnectionStatus((void *)DWC_RAP_GetTargetFriendIndex()) == 0) {
        WIFICLUB_SetPartnerNameWord(p, ((struct Obj03735 *)p)->f1F0);
        WIFICLUB_ShowStreamedMessage(p, 15, zero);
        ((struct Obj03735 *)p)->f1CC = 19;
        return ret;
    }
    s = (void *)WIFICLUB_GetFriendStatus(DWC_RAP_GetTargetFriendIndex());
    WIFICLUB_GetStatusKind(p, ((struct Obj03735 *)p)->f8);
    WIFICLUB_GetStatusKind(p, s);
    WIFICLUB_GetStatusSeatFlag(((struct Obj03735 *)p)->f8);
    ((struct Obj03735 *)p)->f242 = DWC_RAP_GetTargetFriendIndex() + 1;
    if (((struct Obj03735 *)p)->f1351 == 0) {
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(p, 8, zero);
    }
    WIFICLUBACTOR_AddNetCommands(p);
    ((struct Obj03735 *)p)->f1CC = 41;
    ((struct Obj03735 *)p)->f1E0 = 30;
    return ret;
}

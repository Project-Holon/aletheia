/*
 * function: WIFICLUB_StateBranchOnPartnerPhase
 * address: 0x021C1510
 * packet: pkt_ov099_021C1510
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_HandleNetFailure 0x021C1154 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   WIFICLUB_IsTalkFinishedOrClosed 0x021C14EC thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GAME_DATA_GetWifiList  0x0201283C  thumb  arm9
 *   WIFILIST_UpdateFriendRecord  0x0200F4E4  thumb  arm9
 */
#include "../include/Obj10211.h"
typedef unsigned char u8;
extern int WIFICLUB_HandleNetFailure(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern int WIFICLUB_IsTalkFinishedOrClosed(char *);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
struct Sub020097BCFriend;
struct Sub020097BCObj;
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern int WIFILIST_UpdateFriendRecord(void *o);
extern void WIFICLUB_ClearTalkWindow(char *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern int WIFICLUB_GetFriendStatus(int i);
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
int WIFICLUB_StateBranchOnPartnerPhase(char *p, int ret)
{
    void *s;
    unsigned count;
    if (WIFICLUB_HandleNetFailure(p) == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 18, 10) != 0) {
            if (WIFICLUB_IsTalkFinishedOrClosed(p) == 1) {
                WIFILIST_UpdateFriendRecord(func_020099C8((struct Sub020097BCObj *)GAME_DATA_GetWifiList(((struct Obj10211 *)p)->fC4), 0));
                WIFICLUB_ClearTalkWindow(p);
                s = (void *)WIFICLUB_GetFriendStatus(DWC_RAP_GetTargetFriendIndex());
                WIFICLUB_GetStatusKind(p, s);
                count = WIFICLUB_GetStatusPhase(p, s);
                if (count == 3) {
                    ((struct Obj10211 *)p)->f1CC = 65;
                } else {
                    WIFICLUB_SetOwnStatusAndPublish(p, 4, count);
                    ((struct Obj10211 *)p)->f1CC = 115;
                }
            }
        }
    }
    return ret;
}

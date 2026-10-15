/*
 * unit: yes
 * function: WIFICLUB_RecvFriendTrainerCard, WIFICLUB_NoOpNetCommand
 * address: 0x021C1288
 * packet: pkt_ov099_021C1288
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * size: 72
 * follower: empty return at 0x021C12CC.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb  arm9
 *   MISC_SAVEDATA_InsertRecentValue  0x0200ED54  thumb  arm9
 */
#include "../include/Obj13701.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern void MYSTATUS_Copy(void *, void *);
extern void *MISC_SAVEDATA_GetBlock44(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32 val);
void WIFICLUB_RecvFriendTrainerCard(int index, int unused, void *src, char *p, int handle)
{
    void *q;
    void *list;
    if (handle == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        q = GAME_DATA_GetPlayerStatus(((struct Obj13701 *)p)->fC4, index);
        MYSTATUS_Copy(src, q);
        list = MISC_SAVEDATA_GetBlock44(((struct Obj13701 *)p)->fC0);
        MISC_SAVEDATA_InsertRecentValue(list, func_02008530(q));
    }
}
void WIFICLUB_NoOpNetCommand(void) {}

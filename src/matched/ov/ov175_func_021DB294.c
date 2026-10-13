/*
 * function: func_021DB294
 * address: 0x021DB294
 * packet: pkt_ov175_021DB294
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetPlayerStatus 0x02012950 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   func_02082D44 0x02082D44 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
#include "../include/Obj14339.h"
typedef unsigned int   u32;
struct Rec44;
struct Sub24;
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern int MYSTATUS_GetSize(void);
extern void func_02082D44(const void *, void *, int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void func_021DB294(int index, int unused, void *dest, char *ctx, int owner)
{
    void *record;
    record = GAME_DATA_GetPlayerStatus(((struct Obj14339 *)ctx)->f8, index);
    func_02082D44(dest, record, MYSTATUS_GetSize());
    if (owner == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        if (index != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())))
            ((struct Obj14339 *)ctx)->f13C = 1;
    }
}

/*
 * function: WIFICLUB_RefreshVisibleList
 * address: 0x021BE788
 * packet: pkt_ov099_021BE788
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_GetFriendConnectionStatus 0x021C23C0 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetSlotState 0x021C2050 thumb ov099
 *   WIFICLUB_ClearSlotState 0x021C203C thumb ov099
 */
#include "../include/Obj22048.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned char WIFICLUB_GetFriendConnectionStatus(void *a);
extern int WIFICLUB_GetFriendStatus(int i);
extern u8 WIFICLUB_GetStatusKind(int unused, void *s);
extern u8 WIFICLUB_GetSlotState(char *p, int i);
extern void WIFICLUB_ClearSlotState(char *p, int i);
int WIFICLUB_RefreshVisibleList(char *p)
{
    int count = 0;
    int i;
    unsigned value;
    for (i = 0; i < 32; i++) {
        *(u8 *)(p + i + 0x10) = 0;
        if (((struct Obj22048 *)p)->f132A > i && WIFICLUB_GetFriendConnectionStatus((void *)i)) {
            value = WIFICLUB_GetStatusKind((int)p, (void *)WIFICLUB_GetFriendStatus(i));
            if (value != 0 && value < 6) {
                *(u8 *)(p + count + 0x10) = i + 1;
                count++;
            } else if (WIFICLUB_GetSlotState(p, i + 1)) {
                WIFICLUB_ClearSlotState(p, i + 1);
            }
        }
    }
    return count;
}

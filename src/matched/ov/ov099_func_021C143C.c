/*
 * function: WIFICLUB_StateCheckPeerPhase
 * address: 0x021C143C
 * packet: pkt_ov099_021C143C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the narrowed callee result before comparing the indexed field.
 * symbols:
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   WIFICLUB_HandleNetFailure 0x021C1154 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 */
#include "../include/Obj06359.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);
extern int WIFICLUB_HandleNetFailure(char *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned, unsigned);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
int WIFICLUB_StateCheckPeerPhase(char *p, int ret)
{
    int index = 0;
    u16 value;
    if (GFL_NET_IsParentAid() != 0) index = 1;
    if (WIFICLUB_HandleNetFailure(p) == 0) {
        if (((u16 *)(p + 0x1f4))[index] != 0) {
            value = WIFICLUB_GetStatusPhase(p, ((struct Obj06359 *)p)->f8);
            if (value == ((u16 *)(p + 0x1f4))[index]) {
                GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 15, 10);
                ((struct Obj06359 *)p)->f1CC = 44;
            } else {
                WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
                WIFICLUB_ShowStreamedMessage(p, 13, 0);
                ((struct Obj06359 *)p)->f1CC = 19;
            }
        }
    }
    return ret;
}

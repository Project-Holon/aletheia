/*
 * function: WIFICLUB_StateDisconnectAckWait
 * address: 0x021BFF9C
 * packet: pkt_ov099_021BFF9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 */
#include "../include/Obj00008.h"

typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(char *,int);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern u32 KEY_GetTrg(void);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
int WIFICLUB_StateDisconnectAckWait(char *p, int ret) {
    if (!WIFICLUB_UpdateTalkStream(p, ret)) return ret;
    if (KEY_GetTrg() & 3) {
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        ((struct Obj00008 *)p)->f1E0=20;
        ((struct Obj00008 *)p)->f1CC=57;
    }
    return ret;
}

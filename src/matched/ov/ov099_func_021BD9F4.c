/*
 * function: WIFICLUB_StateShowDisconnectNotice
 * address: 0x021BD9F4
 * packet: pkt_ov099_021BD9F4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 */
#include "../include/Obj13696.h"
typedef unsigned int u32;
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern int GFL_NET_SetLoginOption(int);
extern int GFL_NET_IsParentAid(int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
int WIFICLUB_StateShowDisconnectNotice(char *p, int v)
{
    int zero;
    WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
    zero = 0;
    ((struct Obj13696 *)p)->f135C = zero;
    GFL_NET_SetAutoExit(0);
    if (GFL_NET_IsParentAid(GFL_NET_SetLoginOption(0)) != 0) {
        WIFICLUB_ShowStreamedMessage(p, 0x73, zero);
    } else {
        WIFICLUB_ShowStreamedMessage(p, 0x7c, zero);
    }
    ((struct Obj13696 *)p)->f1CC = 0x8e;
    return v;
}

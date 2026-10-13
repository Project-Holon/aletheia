/*
 * function: WIFICLUB_StateShowLeaveMessageBySeat
 * address: 0x021BD7E0
 * packet: pkt_ov099_021BD7E0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 */
#include "../include/Obj22041.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIFICLUB_SetOwnStatusAndPublish(char *, int, int);
extern u32 GFL_NET_IsParentAid(void);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
int WIFICLUB_StateShowLeaveMessageBySeat(char *p, int v)
{
    WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
    if (GFL_NET_IsParentAid() != 0) WIFICLUB_ShowStreamedMessage(p, 0x73, 0);
    else WIFICLUB_ShowStreamedMessage(p, 0x72, 0);
    ((struct Obj22041 *)p)->f1CC = 0x8e;
    return v;
}

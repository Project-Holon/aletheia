/*
 * function: WIFICLUB_StateReturnToClub
 * address: 0x021BF000
 * packet: pkt_ov099_021BF000
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_ResetClubScreen 0x021BEEBC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_ChangeNetMode 0x021BDE30 thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 */
#include "../include/Obj00008.h"
extern void WIFICLUB_ResetClubScreen(char *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *,int,int);
extern void WIFICLUB_ChangeNetMode(void *,int,int);
extern void WIFICLUB_DisableTouchBar(char *);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
int WIFICLUB_StateReturnToClub(char *p,int ret) {
 WIFICLUB_ResetClubScreen(p);
 WIFICLUB_SetOwnStatusAndPublish(p,1,2);
 WIFICLUB_ChangeNetMode(p,1,2);
 ((struct Obj00008 *)p)->f1CC=11;
 WIFICLUB_DisableTouchBar(p);
 GFL_NET_SetAutoExit(0);
 GFL_NET_SetLoginOption(0);
 return ret;
}

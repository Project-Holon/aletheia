/*
 * function: WIFICLUB_ResetOwnSeatStatus
 * address: 0x021C19A8
 * packet: pkt_ov099_021C19A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_StartBgmFade 0x021C24A4 thumb ov099
 *   WIFICLUB_SetStatusSeatFlag 0x021C27E8 thumb ov099
 *   WIFICLUB_SetStatusModeFlag 0x021C2864 thumb ov099
 *   WIFICLUB_PublishOwnStatus 0x021BE6E4 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIFICLUB_StartBgmFade(char *,int);
extern void WIFICLUB_SetStatusSeatFlag(void *,int);
extern void WIFICLUB_SetStatusModeFlag(void *,int);
extern void WIFICLUB_PublishOwnStatus(char *);
extern void WIFICLUB_GetStatusSeatFlag(void *);
void WIFICLUB_ResetOwnSeatStatus(char *p){WIFICLUB_StartBgmFade(p,127);WIFICLUB_SetStatusSeatFlag(((struct Obj00008 *)p)->f8,*(u8 *)(*(u32 *)&((struct Obj00008 *)p)->f248+0x46));WIFICLUB_SetStatusModeFlag(((struct Obj00008 *)p)->f8,*(u8 *)(*(u32 *)&((struct Obj00008 *)p)->f248+0x46));WIFICLUB_PublishOwnStatus(p);WIFICLUB_GetStatusSeatFlag(((struct Obj00008 *)p)->f8);}

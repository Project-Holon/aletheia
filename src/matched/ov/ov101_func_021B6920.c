/*
 * function: COMPATIBLE_IRC_SYS_ProfileSyncGetProfileForAid
 * address: 0x021B6920
 * packet: pkt_ov101_021B6920
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj13716.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
u32 COMPATIBLE_IRC_SYS_ProfileSyncGetProfileForAid(u32 a,u8 *p) {
 if(a==GFL_NET_SYSTEM_GetCurrentAid()) return ((struct Obj13716 *)p)->f2C;
 return ((struct Obj13716 *)p)->f30;
}

/*
 * function: IRCBATTLEMATCH_AbortSession
 * address: 0x021B95C0
 * packet: pkt_ov100_021B95C0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_IRC_WIRELESS_Exit 0x0203D0D0 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 */
#include "../include/Obj22064.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern int GFL_NET_Exit(int a0);
int IRCBATTLEMATCH_AbortSession(u8 *p) { *(int *)(((struct Obj22064 *)p)->f244+0x1c)=12; GFL_NET_IRC_WIRELESS_Exit(); return GFL_NET_Exit(0); }

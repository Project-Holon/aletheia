/*
 * function: COMPATIBLE_IRC_SYS_RecvAckHandler
 * address: 0x021B68A0
 * packet: pkt_ov101_021B68A0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj22107.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void COMPATIBLE_IRC_SYS_RecvAckHandler(u32 a,int b,int c,u8 *d,void *e) {
 if(e==GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_SYSTEM_GetCurrentAid()) ((struct Obj22107 *)d)->f1C=1; }
}

/*
 * function: WIFICLUB_RecvResumeState
 * address: 0x021C12FC
 * packet: pkt_ov099_021C12FC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj10210.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
void WIFICLUB_RecvResumeState(int a,int b,u8 *data,char *p,int handle){if(handle==(int)GFL_NET_HANDLE_GetCurrentHandle()){if(((struct Obj10210 *)p)->f1CC==0x48){((struct Obj10210 *)p)->f1357=*data;GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x1a,10);}else ((struct Obj10210 *)p)->f1CC=21;}}

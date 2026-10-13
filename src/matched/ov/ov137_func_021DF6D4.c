/*
 * function: func_021DF6D4
 * address: 0x021DF6D4
 * packet: pkt_ov137_021DF6D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021E0130 0x021E0130 thumb ov137
 */
#include "../include/Obj14227.h"
typedef unsigned char u8;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);extern void func_021E0130(u8 *,int);
int func_021DF6D4(u8 *p){void *ctx=GFL_NET_HANDLE_GetCurrentHandle();if(!((struct Obj14227 *)p)->f18)GFL_NET_HANDLE_SetTimingSyncRange(ctx,206,40);func_021E0130(p,10);((struct Obj14227 *)p)->f0=48;return 0;}

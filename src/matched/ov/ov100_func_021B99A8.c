/*
 * function: func_021B99A8
 * address: 0x021B99A8
 * packet: pkt_ov100_021B99A8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj22072.h"
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void func_02082D44(const void *,void *,unsigned);
void func_021B99A8(int a,int b,void *c,unsigned d,void *e)
{
 if(e==GFL_NET_HANDLE_GetCurrentHandle()) {
  if(a!=GFL_NET_SYSTEM_GetCurrentAid()) func_02082D44(c,(void *)(((struct Obj22072 *)d)->f244+0x18),4);
 }
}

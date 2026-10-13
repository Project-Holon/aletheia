/*
 * function: func_021DEEA8
 * address: 0x021DEEA8
 * packet: pkt_ov119_021DEEA8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEE00 0x021DEE00 thumb ov119
 */
#include "../include/Obj13900.h"
typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void func_021D8E84(void *,int);
extern void func_021DEE00(unsigned char *p);
void func_021DEEA8(void *p) {
 void *h=GFL_NET_HANDLE_GetCurrentHandle();
 ((struct Obj13900 *)p)->f109A=0;
 if(GFL_NET_SendToHandle((void *)h,0xc11,1,(u32)((char *)p+0x11e6))) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,8);
  if(((struct Obj13900 *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(0);
  func_021D8E84(p,(int)func_021DEE00);
 }
}

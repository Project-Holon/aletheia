/*
 * function: POKETRADE_PROC_RecvPeerFlags
 * address: 0x021D91D8
 * packet: pkt_ov119_021D91D8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
#include "../include/Obj08051.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void POKETRADE_PROC_RecvPeerFlags(int a,int b,const u8 *c,u8 *p,int e) {
 if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
  if(a!=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {
   p[0x11f2]=c[0]; p[0x11f4]=c[1];
   ((struct Obj08051 *)p)->f107E=p[0x11f2]*160+16;
  }
 }
}

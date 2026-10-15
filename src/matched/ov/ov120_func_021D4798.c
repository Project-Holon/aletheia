/*
 * function: GTSNEGO_DISP_SendStatus
 * address: 0x021D4798
 * packet: pkt_ov120_021D4798
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_StartSync 0x021D4774 thumb ov120
 *   MYSTATUS_GetSize  0x02008468  thumb  arm9
 */
#include "../include/Obj22826.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void); extern int MYSTATUS_GetSize(void); extern int GFL_NET_SendToHandle(void *,u16,u16,u32); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int); extern void GTSNEGO_DISP_StartSync(int);
void GTSNEGO_DISP_SendStatus(u8 *p) { void *link; int n; link=GFL_NET_HANDLE_GetCurrentHandle(); n=MYSTATUS_GetSize(); if (GFL_NET_SendToHandle(link,0x2201,n,*(u32 *)(((struct Obj22826 *)p)->f48+20))) GTSNEGO_DISP_SetStateCallback((int)p,GTSNEGO_DISP_StartSync,0x2bd); }

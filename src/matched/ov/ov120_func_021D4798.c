/*
 * function: func_021D4798
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
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4774 0x021D4774 thumb ov120
 *   MYSTATUS_GetSize  0x02008468  thumb  arm9
 */
#include "../include/Obj22826.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void); extern int MYSTATUS_GetSize(void); extern int GFL_NET_SendToHandle(void *,u16,u16,u32); extern void func_021D4244(int,void (*)(int),int); extern void func_021D4774(int);
void func_021D4798(u8 *p) { void *link; int n; link=GFL_NET_HANDLE_GetCurrentHandle(); n=MYSTATUS_GetSize(); if (GFL_NET_SendToHandle(link,0x2201,n,*(u32 *)(((struct Obj22826 *)p)->f48+20))) func_021D4244((int)p,func_021D4774,0x2bd); }

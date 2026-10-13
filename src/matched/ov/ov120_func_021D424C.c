/*
 * function: func_021D424C
 * address: 0x021D424C
 * packet: pkt_ov120_021D424C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj22820.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry; struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern void MI_CpuCopy8(const void *,void *,u32);
void func_021D424C(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&((struct Obj22820 *)p)->f48; if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(src,q+12,8); }

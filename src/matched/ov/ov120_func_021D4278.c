/*
 * function: func_021D4278
 * address: 0x021D4278
 * packet: pkt_ov120_021D4278
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   MYSTATUS_GetSize 0x02008468 thumb
 */
#include "../include/Obj22821.h"
#include "../include/Obj22822.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry; struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern void func_02082D44(const void *,void *,u32);
extern int MYSTATUS_GetSize(void);
void func_021D4278(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&((struct Obj22821 *)p)->f48; if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) func_02082D44(src,((struct Obj22822 *)q)->f18,MYSTATUS_GetSize()); }

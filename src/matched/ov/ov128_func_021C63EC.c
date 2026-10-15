/*
 * function: Wf2dmapFriend_InitText
 * address: 0x021C63EC
 * packet: pkt_ov128_021C63EC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_020355C4 0x020355C4 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 */
#include "../include/Obj04503.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u8 func_020355C4(void);
extern signed char MSG_SPEED_GetWait(void);
void Wf2dmapFriend_InitText(u8 *p, const u32 *q, int heap) {((struct Obj04503 *)p)->f4=*q;((struct Obj04503 *)p)->f58=STRBUF_Create(128,heap);((struct Obj04503 *)p)->f5C=STRBUF_Create(128,heap);((struct Obj04503 *)p)->f0=func_020355C4();p[12]=MSG_SPEED_GetWait();p[13]=0;p[14]=1;}

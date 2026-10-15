/*
 * function: MYSTERY_UTIL_CreateTask
 * address: 0x021DA854
 * packet: pkt_ov121_021DA854
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   d_021DFBA0 0x021DFBA0 data a1
 */
#include "../include/Obj22893.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DFBA0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,u32);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap) { u8 *p; p=func_02030734(heap,20,0,d_021DFBA0,0x61c); MI_CpuFill8(p,0,20); ((struct Obj22893 *)p)->fC=a; MYSTERY_UTIL_SetTaskHandler((u32 *)p,(u32)b); return p; }

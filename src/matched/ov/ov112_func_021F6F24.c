/*
 * function: STA_ACT_LIGHT_AllocElem
 * address: 0x021F6F24
 * packet: pkt_ov112_021F6F24
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F8454 0x021F8454 data a1
 */
#include "../include/Obj08026.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern const char d_021F8454[];
u8 *STA_ACT_LIGHT_AllocElem(u32 heap,u32 v) { u8 *p; p=func_02030734(heap,64,0,d_021F8454,81); ((struct Obj08026 *)p)->f0=heap; ((struct Obj08026 *)p)->f4=v; ((struct Obj08026 *)p)->f8=0; ((struct Obj08026 *)p)->f1C=0; return p; }

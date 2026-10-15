/*
 * function: Wf2dmapFriend_LoadBmps
 * address: 0x021C6A84
 * packet: pkt_ov128_021C6A84
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   gWf2dmapBmpFileIds 0x021CA4F5 data a1
 */
#include "../include/Obj23068.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 gWf2dmapBmpFileIds[];
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, u32, u32, void **, u16);
void Wf2dmapFriend_LoadBmps(u8 *p,u16 heap) {int i;for(i=0;i<2;i++) *(void **)(p+0x16c+i*4)=ARC_UTIL_LoadPaletteDataFromHandle(((struct Obj23068 *)p)->f8,gWf2dmapBmpFileIds[i],0,(void **)(p+0x174+i*4),heap);}

/*
 * function: WF2DMAP_TOUCH_CreateWidgetHandles
 * address: 0x021C9E10
 * packet: pkt_ov128_021C9E10
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   d_021CA648 0x021CA648 data a2
 */
#include "../include/Obj23107.h"
#include "../include/Obj23108.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021CA648[4];
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, u32, u32, void **, u16);
void WF2DMAP_TOUCH_CreateWidgetHandles(u8 *p,u8 *q,u16 heap)
{
    u16 ids[4];
    int i;
    ids[0]=d_021CA648[0]; ids[1]=d_021CA648[1];
    ids[2]=d_021CA648[2]; ids[3]=d_021CA648[3];
    for(i=0;i<4;i++) {
        ((struct Obj23107 *)p)->f0=ARC_UTIL_LoadPaletteDataFromHandle(((struct Obj23108 *)q)->f8,ids[i],0,(void **)(p+4),heap);
        p+=8;
    }
}

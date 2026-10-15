/*
 * function: WF2DMAP_TOUCH_UpdateItemBar
 * address: 0x021CA2DC
 * packet: pkt_ov128_021CA2DC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   WF2DMAP_TOUCH_DrawItemHighlight 0x021CA25C thumb ov128
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj23113.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void WF2DMAP_TOUCH_DrawItemHighlight(u32 a, u32 b);
void WF2DMAP_TOUCH_UpdateItemBar(char *p)  {
    unsigned i;
    if(func_020355C4()==1)  {
        for(i=0;i<8;i++) WF2DMAP_TOUCH_DrawItemHighlight(i,1);
    }
    else  {
        for(i=0;i<8;i++)  {
            if(i==((struct Obj23113 *)p)->f4) WF2DMAP_TOUCH_DrawItemHighlight(i,3);
            else WF2DMAP_TOUCH_DrawItemHighlight(i,1);
        }
    }
}

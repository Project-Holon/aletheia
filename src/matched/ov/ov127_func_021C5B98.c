/*
 * function: WF2DMAP_SCRDRAW_DrawTilesClipped
 * address: 0x021C5B98
 * packet: pkt_ov127_021C5B98
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of zero alignment padding precede WF2DMAP_SCRDRAW_DrawTilesWrapped.
 * lever: Integer address q spills; a pointer q consumes the clipping register.
 * symbols:
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   WF2DMAP_SCRDRAW_DrawTilesWrapped 0x021C5C8C thumb ov127
 */
#include "../include/Obj14033.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
extern void BG_SYS_SetTileEntry(u8,int,int,int,u8,u8,u8);
extern void WF2DMAP_SCRDRAW_DrawTilesWrapped(void *p, u8 layer, u8 x, u8 y, u8 w, u8 h, void *q, u8 sx, u8 sy, int width, int height);
void WF2DMAP_SCRDRAW_DrawTilesClipped(void *p,int layer,unsigned int q,s16 x,s16 y)
{
    s16 width=((struct Obj14033 *)q)->f0/8;
    s16 height=((struct Obj14033 *)q)->f2/8;
    s16 sx,sy,w,h;
    if(x<0) sx=-x; else sx=0;
    if(y<0) sy=-y; else sy=0;
    if(x<=0) x=0;
    if(y<=0) y=0;
    w=33-x;
    h=25-y;
    if(width<sx+w) w-= (s16)(sx+w-width);
    if(height<sy+h) h-= (s16)(sy+h-height);
    BG_SYS_SetTileEntry(layer,0,0,0,33,25,17);
    q+=12;
    WF2DMAP_SCRDRAW_DrawTilesWrapped(p,layer,x,y,w,h,(void *)q,sx,sy,(u8)width,(u8)height);
}

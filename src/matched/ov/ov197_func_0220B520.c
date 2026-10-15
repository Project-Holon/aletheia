/*
 * function: B_BAG_MAIN_DrawPocket
 * address: 0x0220B520
 * packet: pkt_ov197_0220B520
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   B_BAG_MAIN_DrawSlot 0x0220B4B8 thumb ov197
 *   d_0220DA28 0x0220DA28 data a1
 *   d_0220DA19 0x0220DA19 data a1
 */
#include "../include/Obj00314.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void BG_SYS_SetTileEntry(unsigned,int,int,int,u8,u8,u8);
extern void B_BAG_MAIN_DrawSlot(char *,u16);
extern const char d_0220DA28[],d_0220DA19[];
void B_BAG_MAIN_DrawPocket(char *p)
{
    u16 i;
    BG_SYS_SetTileEntry(5,0,0,0,0x20,0x13,0x11);
    for(i=0;i<6;i++)B_BAG_MAIN_DrawSlot(p,i);
    if(((u8 *)p)[0x141]==0)
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA28;
    else
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA19;
    ((u8 *)p)[0x141]^=1;
}
